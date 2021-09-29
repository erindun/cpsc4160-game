#pragma once
#include "../character.h"
#include <list>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  void handle(Character &player, bool &is_running);
  void handle_pos(Character &player, bool &is_running);
};