// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

// Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FRAME_WIDTH = 25;
const int FRAME_HEIGHT = 37;
const int NUM_FRAMES = 8;

const int SCALE_FACTOR = 5;

SDL_Window *my_window = NULL;
SDL_Renderer *my_renderer = NULL;
SDL_Event input;

void my_SDL_init() {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
  }

  // Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  my_window =
      SDL_CreateWindow("my_game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window, -1, 0);
}

int main(int argc, char *argv[]) {
  my_SDL_init();

  SDL_Texture *my_texture = NULL;
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
  SDL_Surface *temp = IMG_Load("../../../../src/cat_walking.png");
  my_texture = SDL_CreateTextureFromSurface(my_renderer, temp);
  if (my_texture == NULL) {
    std::cout << "error" << std::endl;
    return 1;
  }

  SDL_FreeSurface(temp);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 150;
  rect.w = FRAME_WIDTH * NUM_FRAMES * SCALE_FACTOR;
  rect.h = FRAME_HEIGHT * SCALE_FACTOR;

  while (true) {

    SDL_RenderClear(my_renderer);
    SDL_RenderCopy(my_renderer, my_texture, NULL, &rect);
    SDL_RenderPresent(my_renderer);
  }

  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();

  return 0;
}
