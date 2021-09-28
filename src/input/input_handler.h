#pragma once
#include "../player.h"
#include "command.h"
#include <list>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  Command *handle(Player &player, bool &is_running);
};