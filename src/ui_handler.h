#pragma once
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Text {
public:
  Text(const std::string &filepath, const std::string &text,
       SDL_Renderer *renderer, int x, int y);
  SDL_Texture *get_texture();
  SDL_Rect rect;
  void update(const std::string &text);

private:
  SDL_Texture *texture;
  SDL_Renderer *renderer;
  TTF_Font *font;
};

class UIHandler {
public:
  UIHandler(SDL_Renderer *renderer);
  void render();
  void render_score();
  void render_start();
  void render_end();
  void update_score(int new_score);

private:
  SDL_Renderer *renderer;
  Text *pause_text;
  Text *score_text;
  Text *start_text;
  Text *end_text;
  SDL_Rect fullscreen_rect;
};