#pragma once
#include "vec2.h"
#include "constants.h"
#include "character.h"

class Camera {
public:
  static const int VIEW_WIDTH = 640 * SCALE_FACTOR;
  static const int VIEW_HEIGHT = 360 * SCALE_FACTOR;

  Camera();
  ~Camera();
  void update(Character &character);

private:
  vec2::Vec2 position;
};