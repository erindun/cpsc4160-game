#include "tile_handler.h"
#include "utils.h"
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

  tileset = load_texture(renderer, tileset_filepath);
}

void TileHandler::render(SDL_Renderer *renderer, SDL_Rect camera) {
  for (int i = 0; i < NUM_TILES; i++) {
    for (int j = 0; j < NUM_TILES; j++) {
      SDL_Rect dstrect = {j * TILE_SIZE - camera.x, i * TILE_SIZE - camera.y,
                          TILE_SIZE, TILE_SIZE};
      SDL_Rect srcrect = {(tiles.at(i).at(j) % TILES_PER_ROW) * TILE_SIZE,
                          (tiles.at(i).at(j) / TILES_PER_ROW) * TILE_SIZE,
                          TILE_SIZE, TILE_SIZE};
      SDL_RenderCopy(renderer, tileset, &srcrect, &dstrect);
    }
  }
}