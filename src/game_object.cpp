#include "game_object.h"
#include "game_engine.h"
#include "input/input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

GameObject::GameObject()
    : renderer{nullptr}, texture{nullptr}, srcrect{0, 0, FRAME_WIDTH,
                                                   FRAME_HEIGHT},
      dstrect{0, 0, FRAME_WIDTH, FRAME_HEIGHT}, translate{0}, position{Position{
                                                                  0, 0}} {}

GameObject::~GameObject() {}

void GameObject::init(const std::string &file, SDL_Renderer *renderer,
                      Position position) {
  this->renderer = renderer;
  this->position = position;

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
  position.x += 2;
  if (position.x > GameEngine::SCREEN_WIDTH)
    position.x = 0;

  dstrect.x = position.x;
  dstrect.y = position.y;
}

void GameObject::render() {
  auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void GameObject::quit() {}