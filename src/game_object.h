#pragma once

/// Abstract class for an object in the game world.
class GameObject {
public:
  virtual void update() = 0;
  virtual void render() = 0;
};