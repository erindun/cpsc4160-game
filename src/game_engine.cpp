#include "game_engine.h"
#include "character.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

GameEngine::GameEngine()
    : window{nullptr}, renderer{nullptr}, player{nullptr}, is_running{false} {}

GameEngine::~GameEngine() {}

// TODO improve error handling/logging
void GameEngine::init_SDL() {
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
  init_SDL();
  is_running = true;

  player = new Character(
      new Sprite("../../../../assets/cat_walking.png", renderer), Vec2{0, 40});
  game_objects.push_back(player);

  auto fox = new Character(
      new Sprite("../../../../assets/fox_walking.png", renderer), Vec2{0, 140});
  game_objects.push_back(fox);

  auto raccoon = new Character(
      new Sprite("../../../../assets/raccoon_walking.png", renderer),
      Vec2{0, 240});
  game_objects.push_back(raccoon);

  auto deer =
      new Character(new Sprite("../../../../assets/deer_walking.png", renderer),
                    Vec2{0, 340});
  game_objects.push_back(deer);
}

void GameEngine::handle_input() {
  input_handler.handle(*player, is_running);
}

void GameEngine::update() {
  for (auto obj : game_objects)
    obj->update();
}

void GameEngine::render() {
  SDL_RenderClear(renderer);

  // Draw background
  SDL_Rect bg_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
  SDL_SetRenderDrawColor(renderer, 157, 199, 159, 255);
  SDL_RenderFillRect(renderer, &bg_rect);

  for (auto obj : game_objects)
    obj->render();

  SDL_RenderPresent(renderer);
}

void GameEngine::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

bool GameEngine::get_is_running() { return is_running; }