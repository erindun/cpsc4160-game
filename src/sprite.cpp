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

void Sprite::update(Vec2 position) {
  dstrect.x = position.x;
  dstrect.y = position.y;
}

void Sprite::render() {
  auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}