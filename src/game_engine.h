#pragma once

#include "character.h"
#include "game_object.h"
#include "input_handler.h"
#include "tile_handler.h"
#include "vec2.h"
#include "particle.h"
#include <SDL2/SDL.h>
#include <list>

class GameEngine {
public:
  GameEngine();
  ~GameEngine();
  void init();
  void handle_input();
  void update();
  void render();
  void quit();
  bool get_is_running();
  bool is_paused;

private:
  void init_SDL();

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *background;
  bool is_running;
  InputHandler input_handler;
  TileHandler *tile_handler;
  CollisionHandler collision_handler;
  std::list<GameObject *> game_objects;
  Character *player;
  SDL_Rect camera;
  ParticleEmitter *rain_emitter;
};