#include "input_handler.h"
#include "command.h"
#include "game_object.h"

InputHandler::InputHandler() {}
InputHandler::~InputHandler() {}

Command InputHandler::handle() {
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type) {
  case SDL_QUIT:
    return Command::quit;

  case SDL_KEYDOWN: {
    switch (e.key.keysym.sym) {
    case SDLK_ESCAPE:
      return Command::quit;

    case SDLK_UP:
    case SDLK_w:
      return Command::move_up;

    case SDLK_DOWN:
    case SDLK_s:
      return Command::move_down;

    case SDLK_LEFT:
    case SDLK_a:
      return Command::move_left;

    case SDLK_RIGHT:
    case SDLK_d:
      return Command::move_right;

    default:
      return Command::none;
    }
  }

  default:
    return Command::none;
  }
}

void InputHandler::register_obj(GameObject *obj) { observers.push_back(obj); }
void InputHandler::deregister_obj(GameObject *obj) { observers.remove(obj); }
