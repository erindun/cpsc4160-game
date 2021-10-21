#include "sprite.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

Sprite::Sprite(const std::string &file, SDL_Renderer *renderer)
    : current_frame{0}, renderer{renderer}, texture{nullptr},
      srcrect{0, 0, FRAME_WIDTH, FRAME_HEIGHT}, dstrect{0, 0, FRAME_WIDTH,
                                                        FRAME_HEIGHT} {
  SDL_Surface *image = IMG_Load(file.c_str());
  if (image == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(image);
}

Sprite::~Sprite() {}

void Sprite::update(Vec2 position, Vec2 direction, CharacterState state) {
  dstrect.x = position.x;
  dstrect.y = position.y;

  if (state == CharacterState::idle) {
    if (direction == vec2::down)
      anim_state = idle_forward;
    else if (direction == vec2::up)
      anim_state = idle_back;
    else
      anim_state = idle_side;
  } else {
    if (direction == vec2::down)
      anim_state = walk_forward;
    else if (direction == vec2::up)
      anim_state = walk_back;
    else
      anim_state = walk_side;
  }

  if (direction == vec2::left)
    flip = SDL_FLIP_HORIZONTAL;
  else
    flip = SDL_FLIP_NONE;

  current_frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  srcrect.x = current_frame * FRAME_WIDTH;
  srcrect.y = FRAME_HEIGHT * anim_state;
}

void Sprite::render(SDL_Rect camera) {
  SDL_Rect draw_rect = {dstrect.x - camera.x, dstrect.y - camera.y, dstrect.w,
                       dstrect.h};
  SDL_RenderCopyEx(renderer, texture, &srcrect, &draw_rect, 0, nullptr, flip);
}