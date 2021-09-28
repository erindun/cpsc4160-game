#pragma once
#include "../direction.h"
#include "../player.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class MoveCommand : public Command {
public:
  MoveCommand(Player &player, Direction direction)
      : player{player}, direction{direction} {}
  void execute() override { player.move(direction); }

private:
  Player &player;
  Direction direction;
};