#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "position.h"

class GameObject {
public:
  static const int FRAME_WIDTH = 50;
  static const int FRAME_HEIGHT = 74;
  static const int NUM_FRAMES = 8;

  GameObject();
  ~GameObject();

  void init(const std::string &file, SDL_Renderer *renderer, Position position);
  void update();
  void render();
  void quit();

  Position position;

private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  int translate;
};