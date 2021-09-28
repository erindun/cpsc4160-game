#pragma once
#include "game_object.h"
#include "movement.h"
#include "position.h"
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

  void init(const std::string &file, SDL_Renderer *renderer, Position position);
  void update() override;
  void render() override;
  void destroy() override;
  void move(MoveDirection direction);

private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  Position position;
};