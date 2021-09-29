#pragma once
#include "game_object.h"
#include "sprite.h"
#include "character_state.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <string>

/// A game object to represent a game character.
/// This class should be generalizable for the
/// player character as well as NPCs.
class Character : public GameObject {
public:
  static const int MOVE_SPEED = 3;

  Character(Sprite *sprite, vec2::Vec2 position);
  ~Character();

  void update() override;
  void render() override;
  vec2::Vec2 position;
  vec2::Vec2 direction;
  vec2::Vec2 velocity;

private:
  Sprite *sprite;
  CharacterState state;
};