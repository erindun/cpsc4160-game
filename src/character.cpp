#include "character.h"
#include "game_engine.h"
#include "input/input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using vec2::Vec2;

Character::Character(Sprite *sprite, Vec2 position)
    : sprite{sprite}, position{position}, direction{vec2::down},
      state{CharacterState::idle} {}

Character::~Character() {}

void Character::update() { sprite->update(position); }

void Character::render() { sprite->render(); }

void Character::move(Vec2 direction) {
  this->direction = direction;
  state = CharacterState::moving;
  position += direction * MOVE_SPEED;
}