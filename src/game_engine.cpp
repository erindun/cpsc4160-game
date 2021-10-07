#include "game_engine.h"
#include "character.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

GameEngine::GameEngine()
    : window{nullptr}, renderer{nullptr}, background{nullptr},
      is_running{false}, player{nullptr} {}

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

  player = new Character(new Sprite("../../assets/cat.png", renderer),
                         Vec2{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});
  game_objects.push_back(player);

  SDL_Surface *bg_surface = IMG_Load("../../assets/background.png");
  if (bg_surface == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    background = SDL_CreateTextureFromSurface(renderer, bg_surface);
    if (background == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(bg_surface);
}

void GameEngine::handle_input() { input_handler.handle(*player, is_running); }

void GameEngine::update() {
  for (auto obj : game_objects)
    obj->update();
}

void GameEngine::render() {
  SDL_RenderClear(renderer);

  // Draw background
  SDL_Rect bg_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
  SDL_RenderCopy(renderer, background, nullptr, &bg_rect);

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
