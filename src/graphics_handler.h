#pragma once
#include <string>

class GraphicsHandler {
public:
  GraphicsHandler();
  SDL_Texture *load_texture(const std::string &filepath);
  void draw(Sprite2 &sprite, vec2::Vec2 position);

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
};