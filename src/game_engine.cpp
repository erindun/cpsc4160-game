#include "game_engine.h"
#include "character.h"
#include "character_sprite_handler.h"
#include "constants.h"
#include "rat.h"
#include "tree.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
using vec2::Vec2;

GameEngine::GameEngine()
    : window{nullptr}, renderer{nullptr}, background{nullptr},
      is_running{false}, player{nullptr},
      tile_handler{nullptr}, camera{0, 0, VIEW_WIDTH, VIEW_HEIGHT},
      rain_emitter{nullptr}, is_paused{false}, is_started{false}, game_over{
                                                                      false} {}

GameEngine::~GameEngine() {}

// TODO improve error handling/logging
void GameEngine::init_SDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  TTF_Init();

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

  std::vector<GameObject *> rats;

  player =
      new Character(new Sprite("../assets/cat.png", renderer,
                               CharacterSpriteHandler::FRAME_WIDTH,
                               CharacterSpriteHandler::FRAME_HEIGHT),
                    Vec2{VIEW_WIDTH / 2, VIEW_HEIGHT / 2}, collision_handler);
  game_objects.push_back(player);

  tile_handler = new TileHandler(renderer, "../assets/tilemap.csv",
                                 "../assets/tileset.png");

  rain_emitter = new ParticleEmitter(ParticleEffect::rain, renderer);

  rat_handler = new RatHandler(renderer, game_objects, &collision_handler);

  ui_handler = new UIHandler(renderer);
}

void GameEngine::handle_input() {
  input_handler.handle(*player, is_running, is_paused, is_started);
}

void GameEngine::update() {
  int remaining_lives = player->lives;
  for (auto obj : game_objects)
    obj->update();

  // Set the camera to follow the player.
  camera.x = (player->position.x + CharacterSpriteHandler::FRAME_WIDTH / 2) -
             VIEW_WIDTH / 2;
  camera.y = (player->position.y + CharacterSpriteHandler::FRAME_WIDTH / 2) -
             VIEW_HEIGHT / 2;

  if (remaining_lives == 0) {
    game_over = true;
  }

  if (remaining_lives != 0 && player->lives != remaining_lives) {
    remaining_lives = player->lives;
    ui_handler->update_score(remaining_lives);
  }

  // Clamp the camera within the screen.
  if (camera.x < 0)
    camera.x = 0;
  if (camera.y < 0)
    camera.y = 0;
  if (camera.x + camera.w >= SCENE_WIDTH)
    camera.x = SCENE_WIDTH - VIEW_WIDTH;
  if (camera.y + camera.h >= SCENE_HEIGHT)
    camera.y = SCENE_HEIGHT - VIEW_HEIGHT;

  //rain_emitter->update();
  rat_handler->update();
}

void GameEngine::render() {
  SDL_RenderClear(renderer);

  tile_handler->render(renderer, camera);
  for (auto obj : game_objects)
    obj->render(camera);

  //rain_emitter->render(camera);

  ui_handler->render_score();

  if (game_over)
    ui_handler->render_end();
  else if (!is_started)
    ui_handler->render_start();
  else if (is_paused)
    render_pause();

  SDL_RenderPresent(renderer);
}

void GameEngine::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();
}

void GameEngine::render_pause() {
  ui_handler->render();
}

bool GameEngine::get_is_running() { return is_running; }