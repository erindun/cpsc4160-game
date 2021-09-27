#pragma once

#include "game_object.h"
#include "input/input_handler.h"
#include <SDL2/SDL.h>
#include <list>

class GameEngine {
public:
  static const int SCREEN_WIDTH = 640;
  static const int SCREEN_HEIGHT = 480;

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

  SDL_Window *window;
  SDL_Renderer *renderer;
  bool is_running;
  InputHandler input_handler;
  std::list<GameObject *> game_objects;
};