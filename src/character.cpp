#include "character.h"
#include "game_engine.h"
#include "input/input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using vec2::Vec2;

Character::Character()
    : renderer{nullptr}, texture{nullptr}, srcrect{0, 0, FRAME_WIDTH,
                                                   FRAME_HEIGHT},
      dstrect{0, 0, FRAME_WIDTH, FRAME_HEIGHT}, position{Vec2{
                                                                  0, 0}} {}

Character::~Character() {}

void Character::init(const std::string &file, SDL_Renderer *renderer,
                     Vec2 position) {
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

void Character::update() {
  dstrect.x = position.x;
  dstrect.y = position.y;
}

void Character::render() {
  auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}

void Character::destroy() {}

void Character::move(Direction direction) {
  switch (direction) {
  case Direction::up:
    position += vec2::up * MOVE_SPEED;
    break;
  case Direction::down:
    position += vec2::down * MOVE_SPEED;
    break;
  case Direction::left:
    position += vec2::left * MOVE_SPEED;
    break;
  case Direction::right:
    position += vec2::right * MOVE_SPEED;
    break;
  }
}