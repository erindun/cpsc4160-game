#pragma once
#include <string>
#include <SDL2/SDL.h>

class GameObject {
public:
  GameObject(SDL_Renderer *renderer);
  ~GameObject();

  void init(const std::string &file);
  void update();
  void render();
  void quit();

// private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect rect;
};