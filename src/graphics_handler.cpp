#include "graphics_handler.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

GraphicsHandler::GraphicsHandler() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, VIEW_WIDTH * 2,
                            VIEW_HEIGHT * 2, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (window == nullptr || renderer == nullptr) {
    exit(2);
  }
  SDL_RenderSetLogicalSize(renderer, 640, 360);
}

SDL_Texture *GraphicsHandler::load_texture(const std::string &filepath) {
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

void GraphicsHandler::draw(Sprite2 &sprite, vec2::Vec2 position) {
  SDL_Rect dstrect = {position.x, position.y, sprite.get_rect().w,
                      sprite.get_rect().h};
  SDL_RenderCopyEx(renderer, sprite.get_texture(), &sprite.get_rect(), &dstrect,
                   0.0, nullptr, sprite.flip);
}