#include "tile_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <SDL_image.h>

TileHandler::TileHandler(SDL_Renderer *renderer, const std::string &filepath) {
  std::ifstream file(filepath);
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

  SDL_Surface *tileset_surface = IMG_Load("../../assets/tileset.png");
  if (tileset_surface == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    if (tileset == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(tileset_surface);
}

void TileHandler::draw(SDL_Renderer *renderer, SDL_Rect camera) {
for (int i = 0; i < NUM_TILES; i++) {
  for (int j = 0; j < NUM_TILES; j++) {
    SDL_Rect dstrect = {
      j * TILE_SIZE - camera.x,
      i * TILE_SIZE - camera.y,
      TILE_SIZE,
      TILE_SIZE
    };
    SDL_Rect srcrect = {
      (tiles.at(i).at(j) % TILES_PER_ROW) * TILE_SIZE,
      (tiles.at(i).at(j) / TILES_PER_ROW) * TILE_SIZE,
      TILE_SIZE,
      TILE_SIZE
    };
    SDL_RenderCopy(renderer, tileset, &srcrect, &dstrect);
  }
}
}