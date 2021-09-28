#pragma once
#include "game_object.h"
#include "position.h"
#include <SDL2/SDL.h>
#include <string>

class Character : public GameObject {
public:
  static const int FRAME_WIDTH = 50;
  static const int FRAME_HEIGHT = 74;
  static const int NUM_FRAMES = 8;

  Character();
  ~Character();

  void init(const std::string &file, SDL_Renderer *renderer, Position position);
  void update() override;
  void render() override;
  void destroy() override;
  Position position;

private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  int translate;
};