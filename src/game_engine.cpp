#include "game_engine.h"
#include "game_object.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

GameEngine::GameEngine() : window{nullptr}, renderer{nullptr} {}

GameEngine::~GameEngine() {}

// TODO improve error handling/logging
void GameEngine::init_sdl() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  window =
      SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (window == nullptr || renderer == nullptr) {
    exit(2);
  }
}

void GameEngine::init() {
  init_sdl();

  auto cat = new GameObject();
  cat->init("../../../../src/cat_walking.png", renderer, 40);
  game_objects.push_back(cat);

  auto fox = new GameObject();
  fox->init("../../../../src/fox_walking.png", renderer, 140);
  game_objects.push_back(fox);

  auto raccoon = new GameObject();
  raccoon->init("../../../../src/raccoon_walking.png", renderer, 240);
  game_objects.push_back(raccoon);

  auto deer = new GameObject();
  deer->init("../../../../src/deer_walking.png", renderer, 340);
  game_objects.push_back(deer);
}

void GameEngine::update() {
  for (auto obj : game_objects) {
    obj->update();
  }
}

void GameEngine::render() {
  SDL_RenderClear(renderer);

  // Draw background
  SDL_Rect bg_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
  SDL_SetRenderDrawColor(renderer, 95, 201, 98, 1);
  SDL_RenderFillRect(renderer, &bg_rect);

  for (auto obj : game_objects) {
    obj->render();
  }

  SDL_RenderPresent(renderer);
}

void GameEngine::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}