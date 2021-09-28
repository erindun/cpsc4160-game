#pragma once
#include "../direction.h"
#include "../character.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class MoveCommand : public Command {
public:
  MoveCommand(Character &player, Direction direction)
      : player{player}, direction{direction} {}
  void execute() override { player.move(direction); }

private:
  Character &player;
  Direction direction;
};