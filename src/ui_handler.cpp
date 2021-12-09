#include "ui_handler.h"
#include "constants.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

UIHandler::UIHandler(SDL_Renderer *renderer) : renderer{renderer} {
  pause_text = new Text("../assets/munro.ttf", "PAUSED", renderer);
  score_text = new Text("../assets/munro.ttf", "LIVES: 9", renderer);
  fullscreen_rect = SDL_Rect{0, 0, SCENE_WIDTH, SCENE_HEIGHT};
}

void UIHandler::render_score() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderCopy(renderer, score_text->get_texture(), nullptr, &fullscreen_rect);
}

void UIHandler::render() {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
  SDL_RenderFillRect(renderer, &fullscreen_rect);
  SDL_Rect rect = {0, 0, 50, 100};
  SDL_RenderCopy(renderer, pause_text->get_texture(), nullptr, &rect);
}

Text::Text(const std::string &filepath, const std::string &text,
           SDL_Renderer *renderer) {
  auto font = TTF_OpenFont(filepath.c_str(), 36);
  if (!font) {
    std::cout << SDL_GetError() << std::endl;
  }

  auto text_surface =
      TTF_RenderText_Solid(font, text.c_str(), SDL_Color{255, 255, 255});
  if (!text_surface) {
    std::cout << SDL_GetError() << std::endl;
  }

  texture = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);
}

SDL_Texture *Text::get_texture() { return texture; }
