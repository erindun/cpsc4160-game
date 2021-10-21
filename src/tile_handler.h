#pragma once
#include <array>
#include <string>

class TileHandler {
public:
  static const int TILES_PER_ROW = 8;
  static const int TILE_SIZE = 16;
  static const int NUM_TILES = 50;

  TileHandler(const std::string &filepath);
  ~TileHandler();

private:
  std::array<std::array<int, 50>, 50> tiles;
};