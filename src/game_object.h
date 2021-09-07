#pragma once
#include <SDL2/SDL.h>
#include <string>

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