#include "collision_handler.h"

bool CollisionHandler::detect_collisions(SDL_Rect a) {
  for (auto collidable : collidables)
    if (box_collide(a, collidable->get_collider()))
      return true;
  return false;
}

void CollisionHandler::register_obj(Collidable *collidable) { collidables.push_back(collidable); }

bool CollisionHandler::box_collide(SDL_Rect a, SDL_Rect b) {
  if (a.x + a.w < b.x)
    return false;
  if (a.x > b.x + b.w)
    return false;
  if (a.y + a.h < b.y)
    return false;
  if (a.y > b.y + b.h)
    return false;
  return true;
}