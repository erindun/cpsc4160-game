#pragma once

#include "game_object.h"
#include <SDL2/SDL.h>
#include <vector>

class GameEngine {
public:
  static const int SCREEN_WIDTH = 640;
  static const int SCREEN_HEIGHT = 480;

  GameEngine();
  ~GameEngine();
  void register_object(GameObject *obj);
  void init();
  void update();
  void render();
  void quit();

  // private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::vector<GameObject *> game_objects;
};