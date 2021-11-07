#pragma once
#include "character_sprite_handler.h"
#include "character_state.h"
#include "collidable.h"
#include "collision_handler.h"
#include "game_object.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <string>

/// A game object to represent a game character.
/// This class should be generalizable for the
/// player character as well as NPCs.
class Character : public Collidable {
public:
  static const int MOVE_SPEED = 2;

  Character(Sprite *sprite, vec2::Vec2 position, CollisionHandler &collision_handler);
  ~Character();

  void update() override;
  void render(SDL_Rect camera) override;
  vec2::Vec2 position;
  vec2::Vec2 direction;
  vec2::Vec2 velocity;

private:
  Sprite *sprite;
  CharacterSpriteHandler *sprite_handler;
  CharacterState state;
  CollisionHandler &collision_handler;
};