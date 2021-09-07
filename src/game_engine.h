#pragma once
#include <SDL2/SDL.h>

class GameEngine {
public:
  static const int SCREEN_WIDTH = 640;
  static const int SCREEN_HEIGHT = 480;

  GameEngine();
  ~GameEngine();
  void init();
  void update();
  void render();
  void quit();

// private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};