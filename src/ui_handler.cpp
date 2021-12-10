#include "ui_handler.h"
#include "constants.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

UIHandler::UIHandler(SDL_Renderer *renderer) : renderer{renderer} {
  // Text manually offset based on width of text. Ideally, this would be handled
  // automatically
  start_text = new Text("../assets/munro.ttf", "PRESS ENTER TO START", renderer,
                        VIEW_WIDTH / 2 - 140, VIEW_HEIGHT / 2);
  end_text = new Text("../assets/munro.ttf", "GAME OVER!", renderer,
                        VIEW_WIDTH / 2 - 80, VIEW_HEIGHT / 2);
  pause_text = new Text("../assets/munro.ttf", "PAUSED", renderer,
                        VIEW_WIDTH / 2 - 40, VIEW_HEIGHT / 2);
  score_text = new Text("../assets/munro.ttf", "LIVES: 9", renderer, 5, 0);
  fullscreen_rect = SDL_Rect{0, 0, SCENE_WIDTH, SCENE_HEIGHT};
}

void UIHandler::render_score() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderCopy(renderer, score_text->get_texture(), nullptr,
                 &score_text->rect);
}

void UIHandler::render() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderFillRect(renderer, &fullscreen_rect);
  SDL_RenderCopy(renderer, pause_text->get_texture(), nullptr,
                 &pause_text->rect);
}

void UIHandler::render_start() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderFillRect(renderer, &fullscreen_rect);
  SDL_RenderCopy(renderer, start_text->get_texture(), nullptr,
                 &start_text->rect);
}

void UIHandler::render_end() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderFillRect(renderer, &fullscreen_rect);
  SDL_RenderCopy(renderer, end_text->get_texture(), nullptr,
                 &end_text->rect);
}


void UIHandler::update_score(int new_score) {
  std::string str = "LIVES: " + std::to_string(new_score);
  if (score_text != nullptr)
    score_text->update(str);
}

Text::Text(const std::string &filepath, const std::string &text,
           SDL_Renderer *renderer, int x, int y)
    : renderer{renderer}, rect{x, y, 0, 0} {
  font = TTF_OpenFont(filepath.c_str(), 36);
  if (!font) {
    std::cout << SDL_GetError() << std::endl;
  }
  update(text);
}

void Text::update(const std::string &text) {
  auto text_surface =
      TTF_RenderText_Solid(font, text.c_str(), SDL_Color{255, 255, 255});
  if (!text_surface) {
    std::cout << SDL_GetError() << std::endl;
  }

  int w, h;
  texture = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
  rect.w = w;
  rect.h = h;
  SDL_FreeSurface(text_surface);
}

SDL_Texture *Text::get_texture() { return texture; }
