#pragma once

#include "character.h"
#include "game_object.h"
#include "input_handler.h"
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

private:
  void init_SDL();

  Character *player;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *background;
  bool is_running;
  InputHandler input_handler;
  std::list<GameObject *> game_objects;
};