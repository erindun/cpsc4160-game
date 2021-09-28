#include "player.h"
#include "movement.h"
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

void Player::move(MoveDirection direction) {
  switch (direction) {
  case MoveDirection::up:
    position.y -= Player::MOVE_SPEED;
    break;
  case MoveDirection::down:
    position.y += Player::MOVE_SPEED;
    break;
  case MoveDirection::left:
    position.x -= Player::MOVE_SPEED;
    break;
  case MoveDirection::right:
    position.x += Player::MOVE_SPEED;
    std::cout << position.x;
    break;
  }
}

void Player::destroy() {}
void Player::update() { 
  //position.x += 2;
  //if (position.x > GameEngine::SCREEN_WIDTH)
  //  position.x = 0;

  dstrect.x = position.x;
  dstrect.y = position.y;
}
void Player::render() {
  // auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  // srcrect.x = frame * FRAME_WIDTH;
  SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}
