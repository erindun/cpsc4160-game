#include "tile_handler.h"
#include <SDL_image.h>
#include <fstream>
#include <iostream>
#include <sstream>

TileHandler::TileHandler(SDL_Renderer *renderer,
                         const std::string &tilemap_filepath,
                         const std::string &tileset_filepath) {
  std::ifstream file(tilemap_filepath);
  // Read CSV into tilemap array.
  for (int i = 0; i < NUM_TILES; i++) {
    std::string line;
    std::getline(file, line);
    std::stringstream s(line);
    for (int j = 0; j < NUM_TILES; j++) {
      std::string tile_id;
      std::getline(s, tile_id, ',');
      tiles.at(i).at(j) = std::stoi(tile_id);
    }
  }

  tileset = new Sprite(tileset_filepath, renderer, TILE_SIZE, TILE_SIZE);
}

void TileHandler::render(SDL_Renderer *renderer, SDL_Rect camera) {
  for (int y = 0; y < NUM_TILES; y++) {
    for (int x = 0; x < NUM_TILES; x++) {
      if (!is_visible(x, y, camera))
        continue;

      tileset->set_dstrect_pos(x * TILE_SIZE, y * TILE_SIZE);
      tileset->set_srcrect_pos((tiles.at(y).at(x) % TILES_PER_ROW) * TILE_SIZE,
                               (tiles.at(y).at(x) / TILES_PER_ROW) * TILE_SIZE);
      tileset->render(camera);
    }
  }
}

bool TileHandler::is_visible(int x, int y, SDL_Rect camera) {
  int x_pos = x * TILE_SIZE;
  int y_pos = y * TILE_SIZE;
  // Render additional row on lower bounds to ensure screen will always be
  // covered with tiles.
  return (x_pos + TILE_SIZE) >= camera.x && x_pos <= camera.x + camera.w &&
         (y_pos + TILE_SIZE) >= camera.y && y_pos <= camera.y + camera.h;
}