#include "character_sprite_handler.h"
using vec2::Vec2;

CharacterSpriteHandler::CharacterSpriteHandler(Sprite *sprite)
    : sprite{sprite} {}

CharacterSpriteHandler::~CharacterSpriteHandler() {}

void CharacterSpriteHandler::update(Vec2 position, Vec2 direction,
                                    CharacterState state) {
  sprite->set_dstrect_pos(position.x, position.y);

  if (state == CharacterState::idle) {
    if (direction == vec2::down)
      anim_state = idle_forward;
    else if (direction == vec2::up)
      anim_state = idle_back;
    else
      anim_state = idle_side;
  } else {
    if (direction == vec2::down)
      anim_state = walk_forward;
    else if (direction == vec2::up)
      anim_state = walk_back;
    else
      anim_state = walk_side;
  }

  if (direction == vec2::left)
    sprite->flip = SDL_FLIP_HORIZONTAL;
  else
    sprite->flip = SDL_FLIP_NONE;

  current_frame = (SDL_GetTicks() / 100) % NUM_FRAMES;
  sprite->set_srcrect_pos(current_frame * FRAME_WIDTH,
                          FRAME_HEIGHT * anim_state);
}