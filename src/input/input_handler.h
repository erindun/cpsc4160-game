#pragma once
#include "../game_object.h"
#include "command.h"
#include <list>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  Command handle();
  void register_obj(GameObject *obj);
  void deregister_obj(GameObject *obj);

private:
  std::list<GameObject *> observers;
};