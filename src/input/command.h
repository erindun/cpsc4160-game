#pragma once
#include "../player.h"
#include "../movement.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class MoveCommand : public Command {
public:
  MoveCommand(Player &player, MoveDirection direction)
      : player{player}, direction{direction} {}
  void execute() override { player.move(direction); }

private:
  Player &player;
  MoveDirection direction;
};