#pragma once
#include "../character.h"
#include "command.h"
#include <list>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  Command *handle(Character &player, bool &is_running);
};