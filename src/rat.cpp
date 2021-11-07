#include "rat.h"
using vec2::Vec2;

Rat::Rat(Sprite *sprite, Vec2 position) : sprite{sprite}, position{position} {
  collider = sprite->get_dstrect();
}

void Rat::render(SDL_Rect camera) {
  sprite->set_dstrect_pos(position.x, position.y);
  collider = sprite->get_dstrect();
  sprite->render(camera);
}