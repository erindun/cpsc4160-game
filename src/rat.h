#pragma once

#include "collidable.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL.h>
#include <list>
#include "collision_handler.h";

enum spawn_location {Up, Down, Left, Right};

class Rat : public Collidable {
public:
  Rat(SDL_Renderer *renderer);
  void update() override;
  void render(SDL_Rect camera) override;
  vec2::Vec2 get_position();
  void new_spawn();

private:
  Sprite *sprite;
  vec2::Vec2 position;
  vec2::Vec2 velocity;
  int speed;
};

class RatHandler {
public:
  RatHandler(SDL_Renderer *renderer, std::list<GameObject *> &game_objects, CollisionHandler *collision_handler);
  void update();
  void render(SDL_Rect camera);

private:
  std::list<Rat *> rats;
  SDL_Renderer *renderer;
  std::list<GameObject *> &game_objects;
  CollisionHandler *collision_handler;
};
