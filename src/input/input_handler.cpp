#include "input_handler.h"
#include "../player.h"
#include "command.h"
#include <SDL2/SDL.h>

InputHandler::InputHandler() {}
InputHandler::~InputHandler() {}

Command *InputHandler::handle(Player &player) {
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type) {
  case SDL_QUIT:
    break;

  case SDL_KEYDOWN: {
    switch (e.key.keysym.sym) {
    case SDLK_ESCAPE:
      break;

    case SDLK_UP:
    case SDLK_w:
      return new MoveCommand(player, MoveDirection::up);

    case SDLK_DOWN:
    case SDLK_s:
      return new MoveCommand(player, MoveDirection::down);

    case SDLK_LEFT:
    case SDLK_a:
      return new MoveCommand(player, MoveDirection::left);

    case SDLK_RIGHT:
    case SDLK_d:
      return new MoveCommand(player, MoveDirection::right);
    }
  }

  default:
    break;
  }

  return nullptr;
}

void InputHandler::register_obj(Player *obj) { observers.push_back(obj); }
void InputHandler::deregister_obj(Player *obj) { observers.remove(obj); }
