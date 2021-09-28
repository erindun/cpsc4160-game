#include "input_handler.h"
#include "../character.h"
#include "../vec2.h"
#include "command.h"
#include <SDL2/SDL.h>

InputHandler::InputHandler() {}
InputHandler::~InputHandler() {}

Command *InputHandler::handle(Character &player, bool &is_running) {
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type) {
  case SDL_QUIT:
    is_running = false;
    return nullptr;

  case SDL_KEYDOWN: {
    switch (e.key.keysym.sym) {
    case SDLK_ESCAPE:
      is_running = false;
      return nullptr;

    case SDLK_UP:
    case SDLK_w:
      return new MoveCommand(player, vec2::up);

    case SDLK_DOWN:
    case SDLK_s:
      return new MoveCommand(player, vec2::down);

    case SDLK_LEFT:
    case SDLK_a:
      return new MoveCommand(player, vec2::left);

    case SDLK_RIGHT:
    case SDLK_d:
      return new MoveCommand(player, vec2::right);
    }
  }

  default:
    break;
  }

  return nullptr;
}