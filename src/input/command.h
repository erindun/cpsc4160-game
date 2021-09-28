#pragma once
#include "../vec2.h"
#include "../character.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class MoveCommand : public Command {
public:
  MoveCommand(Character &player, vec2::Vec2 direction)
      : player{player}, direction{direction} {}
  void execute() override { player.move(direction); }

private:
  Character &player;
  vec2::Vec2 direction;
};