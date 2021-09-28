#pragma once
#include "../player.h"
#include "command.h"
#include <list>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  Command *handle(Player &player);
  void register_obj(Player *obj);
  void deregister_obj(Player *obj);

private:
  std::list<GameObject *> observers;
};