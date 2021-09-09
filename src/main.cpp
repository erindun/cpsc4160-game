// CS 4160 - starter code written by Victor Zordan

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <string>

#include "game_engine.h"
#include "game_object.h"

const int FPS = 60;
const int FRAME_DURATION = 1000 / FPS;

const int FRAME_WIDTH = 50;
const int FRAME_HEIGHT = 74;
const int NUM_FRAMES = 8;

const int SCALE_FACTOR = 5;

SDL_Event input;

int main(int argc, char *argv[]) {
  auto engine = new GameEngine();
  engine->init();

  auto game_object = new GameObject();
  game_object->init(engine->renderer, "../../../../src/cat_walking.png");
  engine->register_object(game_object);

  int fps_counter = 0;
  int last_count_start_time = 0;
  int current_fps = 0;
  int this_duration = 0;

  while (true) {
    Uint32 ticks = SDL_GetTicks();
    engine->update();
    engine->render();

    ++fps_counter;
    if (ticks >= last_count_start_time + 1000) {
      last_count_start_time = ticks;
      current_fps = fps_counter;
      fps_counter = 0;
    }

    std::cout << current_fps << std::endl;

    this_duration = SDL_GetTicks() - ticks;
    if (this_duration < FRAME_DURATION) {
      SDL_Delay(FRAME_DURATION - this_duration);
    }
  }

  engine->quit();
  return 0;
}
