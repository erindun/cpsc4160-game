#pragma once
#include "game_object.h"
#include "direction.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <string>

class Player : public GameObject {
public:
  static const int FRAME_WIDTH = 50;
  static const int FRAME_HEIGHT = 74;
  static const int NUM_FRAMES = 8;
  static const int MOVE_SPEED = 4;

  Player();
  ~Player();

  void init(const std::string &file, SDL_Renderer *renderer, vec2::Vec2 position);
  void update() override;
  void render() override;
  void destroy() override;
  void move(Direction direction);

private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  vec2::Vec2 position;
};