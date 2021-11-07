#include "character.h"
#include "game_engine.h"
#include "input_handler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using vec2::Vec2;

Character::Character(Sprite *sprite, Vec2 position,
                     CollisionHandler &collision_handler)
    : sprite{sprite}, position{position}, direction{vec2::down},
      velocity{vec2::zero}, state{CharacterState::idle},
      collision_handler{collision_handler} {
  sprite_handler = new CharacterSpriteHandler(sprite);
  collider = sprite->get_dstrect();
}

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
  if (collision_handler.detect_collisions(get_collider())) {
      velocity.x += -velocity.x;
      velocity.y += -velocity.y;
  }
  position += velocity * (MOVE_SPEED - dampen);
  sprite_handler->update(position, direction, state);
  collider = sprite->get_dstrect();
}

void Character::render(SDL_Rect camera) { sprite->render(camera); }