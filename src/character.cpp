#include "character.h"
#include "game_engine.h"
#include "input/input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using vec2::Vec2;

Character::Character(Sprite *sprite, Vec2 position)
    : sprite{sprite}, position{position},
      direction{vec2::down}, velocity{vec2::zero},
      state{CharacterState::idle} {}

Character::~Character() {}

void Character::update() { 
  sprite->update(position); 
  std::cout << velocity.x << " " << velocity.y << " " << std::endl;

  // Reduce diagonal movement speed.
  int dampen = velocity.x != 0 && velocity.y != 0 ? -1 : 0;

  position += velocity * (MOVE_SPEED + dampen);
}

void Character::render() { sprite->render(); }