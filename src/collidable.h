#pragma once
#include "game_object.h"
#include <SDL.h>

class Collidable : public GameObject {
public:
  SDL_Rect get_collider() { return collider; }

protected:
  SDL_Rect collider;
};