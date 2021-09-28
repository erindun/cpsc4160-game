#include "player.h"
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

void Player::destroy() {}
void Player::update() {}
void Player::render() {
    //auto frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
    //srcrect.x = frame * FRAME_WIDTH;
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
}
