#include "sprite.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

/// A sprite within the game.
Sprite::Sprite(const std::string &filepath, SDL_Renderer *renderer, int width,
               int height)
    : renderer{renderer}, srcrect{0, 0, width, height},
      dstrect{0, 0, width, height}, flip{SDL_FLIP_NONE} {
  texture = load_texture(renderer, filepath);
}

Sprite::~Sprite() {}

void Sprite::render(SDL_Rect camera) {
  SDL_Rect draw_rect = {dstrect.x - camera.x, dstrect.y - camera.y, dstrect.w,
                        dstrect.h};
  SDL_RenderCopyEx(renderer, texture, &srcrect, &draw_rect, 0, nullptr, flip);
}

SDL_Texture *Sprite::load_texture(SDL_Renderer *renderer,
                                  const std::string &filepath) {
  SDL_Surface *surface = IMG_Load(filepath.c_str());
  SDL_Texture *texture = nullptr;
  if (surface == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(surface);
  return texture;
}