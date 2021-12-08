#pragma once
#include <list>
#include <SDL.h>
#include "collidable.h"

class CollisionHandler {
public:
  bool detect_collisions(SDL_Rect a);
  void register_obj(Collidable *collidable);
  void deregister_obj(Collidable *collidable);

private:
  std::list<Collidable *> collidables;
  bool box_collide(SDL_Rect a, SDL_Rect b);
};