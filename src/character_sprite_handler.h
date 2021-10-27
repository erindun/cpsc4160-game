#pragma once
#include "character_state.h"
#include "sprite.h"
#include "vec2.h"

class CharacterSpriteHandler {
public:
  static const int FRAME_WIDTH = 25;
  static const int FRAME_HEIGHT = 37;
  static const int NUM_FRAMES = 8;

  CharacterSpriteHandler(Sprite *sprite);
  ~CharacterSpriteHandler();
  void update(vec2::Vec2 position, vec2::Vec2 direction, CharacterState state);

private:
  Sprite *sprite;
  int current_frame;
  enum AnimationState {
    idle_forward,
    idle_back,
    idle_side,
    walk_forward,
    walk_back,
    walk_side
  } anim_state;
};