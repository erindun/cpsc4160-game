#include "game_object.h"
#include "game_engine.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

GameObject::GameObject()
    : renderer{nullptr}, texture{nullptr}, srcrect{0, 0, FRAME_WIDTH,
                                                   FRAME_HEIGHT},
      dstrect{0, 0, FRAME_WIDTH, FRAME_HEIGHT}, translate{0} {}

GameObject::~GameObject() {}

void GameObject::init(const std::string &file, SDL_Renderer *renderer,
                      int y_pos) {
  this->renderer = renderer;
  dstrect.y = y_pos;

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
  dstrect.x += 2;
  if (dstrect.x > GameEngine::SCREEN_WIDTH)
    dstrect.x = 0;
}

void GameObject::render() {
  auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void GameObject::quit() {}