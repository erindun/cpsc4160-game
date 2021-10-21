#include "game_engine.h"
#include "character.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using vec2::Vec2;

GameEngine::GameEngine()
    : window{nullptr}, renderer{nullptr}, background{nullptr},
      is_running{false}, player{nullptr},
      tile_handler{nullptr}, camera{0, 0, VIEW_WIDTH, VIEW_HEIGHT} {}

GameEngine::~GameEngine() {}

// TODO improve error handling/logging
void GameEngine::init_SDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, VIEW_WIDTH * 2,
                            VIEW_HEIGHT * 2, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (window == nullptr || renderer == nullptr) {
    exit(2);
  }
  SDL_RenderSetLogicalSize(renderer, 640, 360);
}

void GameEngine::init() {
  init_SDL();
  is_running = true;

  player = new Character(new Sprite("../../assets/cat.png", renderer),
                         Vec2{VIEW_WIDTH / 2, VIEW_HEIGHT / 2});
  game_objects.push_back(player);

  tile_handler = new TileHandler(renderer, "../../assets/tilemap.csv", "../../assets/tileset.png");
}

void GameEngine::handle_input() { input_handler.handle(*player, is_running); }

void GameEngine::update() {
  for (auto obj : game_objects)
    obj->update();

  // Set the camera to follow the player.
  camera.x = (player->position.x + Sprite::FRAME_WIDTH / 2) - VIEW_WIDTH / 2;
  camera.y = (player->position.y + Sprite::FRAME_WIDTH / 2) - VIEW_HEIGHT / 2;

  // Clamp the camera within the screen.
  if (camera.x < 0)
    camera.x = 0;
  if (camera.y < 0)
    camera.y = 0;
  if (camera.x + camera.w >= SCENE_WIDTH)
    camera.x = SCENE_WIDTH - VIEW_WIDTH;
  if (camera.y + camera.h >= SCENE_HEIGHT)
    camera.y = SCENE_HEIGHT - VIEW_HEIGHT;
}

void GameEngine::render() {
  SDL_RenderClear(renderer);

  tile_handler->render(renderer, camera);
  for (auto obj : game_objects)
    obj->render(camera);

  SDL_RenderPresent(renderer);
}

void GameEngine::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

bool GameEngine::get_is_running() { return is_running; }
