#include "character.h"
#include "game_engine.h"
#include "input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using vec2::Vec2;

Character::Character(Sprite *sprite, Vec2 position)
    : position{position}, direction{vec2::down}, velocity{vec2::zero},
      sprite{sprite}, state{CharacterState::idle} {}

Character::~Character() {}

void Character::update() {
  int dampen = 0;
  if (velocity == vec2::zero)
    state = CharacterState::idle;
  else {
    state = CharacterState::moving;
    direction = velocity;
    if (velocity.x != 0 && velocity.y) {
      // Reduce diagonal movement speed.
      dampen = 1;
      // Force character direction to left or right when moving diagonally.
      direction.y = 0;
    }
  }
  position += velocity * (MOVE_SPEED - dampen);
  sprite->update(position, direction, state);
}

void Character::render(int x, int y) { sprite->render(x, y); }