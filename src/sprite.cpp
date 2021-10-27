#include "sprite.h"
#include "utils.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

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