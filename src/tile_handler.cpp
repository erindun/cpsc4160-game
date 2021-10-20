#include "tile_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>

TileHandler::TileHandler(const std::string &filepath) {
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
}