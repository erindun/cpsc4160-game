#pragma once
#include <SDL.h>
#include <string>

class Text {
public:
  Text(const std::string &filepath, const std::string &text,
       SDL_Renderer *renderer);
  SDL_Texture *get_texture();

private:
  SDL_Texture *texture;
  SDL_Renderer *renderer;
};

class UIHandler {
public:
  UIHandler(SDL_Renderer *renderer);
  void render();

private:
  SDL_Renderer *renderer;
  Text *pause_text;
};