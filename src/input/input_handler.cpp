#include "input_handler.h"
#include "../character.h"
#include "../vec2.h"
#include <SDL2/SDL.h>

InputHandler::InputHandler() {}
InputHandler::~InputHandler() {}

void InputHandler::handle(Character &player, bool &is_running) {
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type) {
  case SDL_QUIT:
    is_running = false;
    break;

  case SDL_KEYDOWN:
    switch (e.key.keysym.sym) {
    case SDLK_ESCAPE:
      is_running = false;
      break;

    case SDLK_UP:
    case SDLK_w:
      player.velocity.y = -1;
      break;

    case SDLK_DOWN:
    case SDLK_s:
      player.velocity.y = 1;
      break;

    case SDLK_LEFT:
    case SDLK_a:
      player.velocity.x = -1;
      break;

    case SDLK_RIGHT:
    case SDLK_d:
      player.velocity.x = 1;
      break;
    }
    break;

  case SDL_KEYUP:
    switch (e.key.keysym.sym) {
    case SDLK_UP:
    case SDLK_w:
      if (player.velocity.y == vec2::up.y)
        player.velocity.y = 0;
        break;

    case SDLK_DOWN:
    case SDLK_s:
      if (player.velocity.y == vec2::down.y)
        player.velocity.y = 0;
      break;

    case SDLK_LEFT:
    case SDLK_a:
      if (player.velocity.x == vec2::left.x)
        player.velocity.x = 0;
      break;

    case SDLK_RIGHT:
    case SDLK_d:
      if (player.velocity.x == vec2::right.x)
        player.velocity.x = 0;
      break;
    }
    break;
  }
}