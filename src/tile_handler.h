#pragma once
#include "sprite.h"
#include <SDL.h>
#include <array>
#include <string>

/// Renders background tiles as specified by a tilemap.
class TileHandler {
public:
  static const int TILES_PER_ROW = 8;
  static const int NUM_ROWS = 2;
  static const int TILE_SIZE = 16;
  static const int NUM_TILES = 50;

  TileHandler(SDL_Renderer *renderer, const std::string &tilemap_filepath,
              const std::string &tileset_filepath);
  ~TileHandler();
  bool is_visible(int x, int y, SDL_Rect camera);
  void render(SDL_Renderer *renderer, SDL_Rect camera);

private:
  std::array<std::array<int, 50>, 50> tiles;
  Sprite *tileset;
};