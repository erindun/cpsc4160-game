#include "player.h"
#include "direction.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Player::Player()
    : renderer{nullptr}, texture{nullptr}, srcrect{0, 0, FRAME_WIDTH,
                                                   FRAME_HEIGHT},
      dstrect{0, 0, FRAME_WIDTH, FRAME_HEIGHT}, position{Position{0, 0}} {}

Player::~Player() {}

void Player::init(const std::string &file, SDL_Renderer *renderer,
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

void Player::move(Direction direction) {
  switch (direction) {
  case Direction::up:
    position.y -= Player::MOVE_SPEED;
    break;
  case Direction::down:
    position.y += Player::MOVE_SPEED;
    break;
  case Direction::left:
    position.x -= Player::MOVE_SPEED;
    break;
  case Direction::right:
    position.x += Player::MOVE_SPEED;
    break;
  }
}

void Player::destroy() {}
void Player::update() { 
  dstrect.x = position.x;
  dstrect.y = position.y;
}
void Player::render() {
  // auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  // srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}
