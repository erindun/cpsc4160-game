#pragma once
#include "game_object.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <string>

enum class CharacterState { idle, moving };

class Character : public GameObject {
public:
  static const int MOVE_SPEED = 3;

  Character(Sprite *sprite, vec2::Vec2 position);
  ~Character();

  void update() override;
  void render() override;
  void move(vec2::Vec2 direction);
  vec2::Vec2 position;
  vec2::Vec2 direction;
  vec2::Vec2 velocity;

private:
  Sprite *sprite;
  CharacterState state;
};