// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "game_engine.h"

const int FPS = 60;
const int FRAME_DURATION = 1000 / FPS;

const int FRAME_WIDTH = 50;
const int FRAME_HEIGHT = 74;
const int NUM_FRAMES = 8;

const int SCALE_FACTOR = 5;

SDL_Event input;

/** Loads an image into an SDL Texture. */
SDL_Texture* load_image(const std::string &file, SDL_Renderer *renderer) {
  SDL_Texture *texture = nullptr;
  SDL_Surface *image = IMG_Load(file.c_str());
  if (image == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(image);
  return texture;
}

int main(int argc, char *argv[]) {
  auto engine = new GameEngine();
  engine->init();

  auto texture = load_image("../../../../src/cat_walking.png", engine->renderer);

  int translate = 0;
  int fps_counter = 0;
  int last_count_start_time = 0;
  int current_fps = 0;
  int this_duration = 0;
  int frame_duration = 120;

  while (true) {
    Uint32 ticks = SDL_GetTicks();
    Uint32 sprite = (ticks / 100) % 8;

    SDL_Rect srcrect = {sprite * FRAME_WIDTH, 0, FRAME_WIDTH, FRAME_HEIGHT};
    SDL_Rect dstrect = {translate, 200, FRAME_WIDTH, FRAME_HEIGHT};

    translate += 2;
    if (translate > GameEngine::SCREEN_WIDTH)
      translate = 0;

    SDL_RenderClear(engine->renderer);
    SDL_RenderCopy(engine->renderer, texture, &srcrect, &dstrect);
    SDL_RenderPresent(engine->renderer);

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

  return 0;
}
