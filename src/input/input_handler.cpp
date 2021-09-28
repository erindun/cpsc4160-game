#include "input_handler.h"
#include "../player.h"
#include "../direction.h"
#include "command.h"
#include <SDL2/SDL.h>

InputHandler::InputHandler() {}
InputHandler::~InputHandler() {}

Command *InputHandler::handle(Player &player, bool &is_running) {
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
      return new MoveCommand(player, Direction::up);

    case SDLK_DOWN:
    case SDLK_s:
      return new MoveCommand(player, Direction::down);

    case SDLK_LEFT:
    case SDLK_a:
      return new MoveCommand(player, Direction::left);

    case SDLK_RIGHT:
    case SDLK_d:
      return new MoveCommand(player, Direction::right);
    }
  }

  default:
    break;
  }

  return nullptr;
}