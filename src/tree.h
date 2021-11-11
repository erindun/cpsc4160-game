#pragma once
#include "collidable.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL.h>

class Tree : public Collidable {
public:
  Tree(Sprite *sprite, vec2::Vec2 position);
  void update() override {}
  void render(SDL_Rect camera) override;

private:
  Sprite *sprite;
  vec2::Vec2 position;
};