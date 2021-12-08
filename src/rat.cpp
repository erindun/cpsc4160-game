#include "rat.h"
#include "constants.h"
#include <cmath>

using vec2::Vec2;

Rat::Rat(SDL_Renderer *renderer) {
  sprite = new Sprite("../assets/rat.png", renderer, 16, 16);
  collider = sprite->get_dstrect();
  new_spawn();
}

void Rat::new_spawn() {
  vec2::Vec2 pos = vec2::zero, vel = vec2::zero;
  int spawn = rand() % 4;
  int delay = rand() % 32;
  switch (spawn) {
  case spawn_location::Up:
    pos = {rand() % SCENE_WIDTH, 0 - delay};
    vel = vec2::down;
    break;
  case spawn_location::Down:
    pos = {rand() % SCENE_WIDTH, SCENE_HEIGHT + delay};
    vel = vec2::up;
    break;
  case spawn_location::Left:
    pos = {0 - delay, rand() % SCENE_HEIGHT};
    vel = vec2::right;
    break;
  case spawn_location::Right:
    pos = {SCENE_WIDTH + delay, rand() % SCENE_HEIGHT};
    vel = vec2::left;
    break;
  }
  speed = rand() % 3 + 2;
  position = pos;
  velocity = vel;
}

void Rat::render(SDL_Rect camera) {
  sprite->set_dstrect_pos(position.x, position.y);
  collider = sprite->get_dstrect();
  sprite->render(camera);
}

Vec2 Rat::get_position() { return position; }

void Rat::update() { position += velocity * speed; }

RatHandler::RatHandler(SDL_Renderer *renderer,
                       std::list<GameObject *> &game_objects, CollisionHandler *collision_handler)
    : renderer{renderer}, game_objects{game_objects}, collision_handler{
                              collision_handler} {}

bool rat_out_of_bounds(Rat *rat) {
  return rat->get_position().x < -5 || rat->get_position().x > SCENE_WIDTH + 5 || rat->get_position().y < -5 || rat->get_position().y > SCENE_HEIGHT + 5;
}

void RatHandler::update() {
  vec2::Vec2 pos, vel;

  while (rats.size() < 35) {
    auto rat = new Rat(renderer);
    rats.push_back(rat);
    game_objects.push_back(rat);
    collision_handler->register_obj(rat);
  }
   
  for (auto rat : rats) {
    if (rat_out_of_bounds(rat)) {
      rat->new_spawn();
    }
  }
 
}

void RatHandler::render(SDL_Rect camera) {
  // for (auto rat : rats) {
  //  rat->render(camera);
  //}
}