#pragma once
#include <SDL.h>

class UIHandler {
public:
  UIHandler(SDL_Renderer *renderer);
  void render();

private:
  SDL_Renderer *renderer;
};