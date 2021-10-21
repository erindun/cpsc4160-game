#include "constants.h"
#include "game_engine.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

int main(int argc, char *argv[]) {
  auto engine = new GameEngine();
  engine->init();

  unsigned int fps_counter = 0;
  unsigned int last_count_start_time = 0;
  unsigned int current_fps = 0;
  unsigned int this_duration = 0;

  while (engine->get_is_running()) {
    auto ticks = SDL_GetTicks();
    engine->handle_input();
    engine->update();
    engine->render();

    ++fps_counter;
    if (ticks >= last_count_start_time + 1000) {
      last_count_start_time = ticks;
      current_fps = fps_counter;
      fps_counter = 0;
    }
    // std::cout << current_fps << std::endl;

    this_duration = SDL_GetTicks() - ticks;
    if (this_duration < FRAME_DURATION) {
      SDL_Delay(FRAME_DURATION - this_duration);
    }
  }

  engine->quit();
  return 0;
}
