#include "game_object.h"
#include "game_engine.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

GameObject::GameObject()
    : renderer{nullptr}, texture{nullptr}, srcrect{0, 0, 0, 0},
      dstrect{0, 0, 0, 0}, translate{0} {}

GameObject::~GameObject() {}

void GameObject::init(SDL_Renderer *renderer, const std::string &file) {
  this->renderer = renderer;

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

void GameObject::update() {
  Uint32 ticks = SDL_GetTicks();
  int sprite = (ticks / 100) % 8;

  srcrect = {sprite * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT};
  dstrect = {translate, 200, FRAME_WIDTH, FRAME_HEIGHT};

  translate += 2;
  if (translate > GameEngine::SCREEN_WIDTH)
    translate = 0;
}

void GameObject::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
  SDL_RenderPresent(renderer);
}

void GameObject::quit() {}