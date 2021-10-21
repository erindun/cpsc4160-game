#pragma once

#include "character_state.h"
#include "constants.h"
#include "vec2.h"
#include <SDL2/SDL.h>
#include <string>

/// A sprite for a Character game object.
///
/// Eventually, I plan to generalize this
/// class sprites that are _not_ Character
/// objects.
class Sprite {
public:
  static const int FRAME_WIDTH = 25;
  static const int FRAME_HEIGHT = 37;
  static const int NUM_FRAMES = 8;

  Sprite(const std::string &filepath, SDL_Renderer *renderer);
  ~Sprite();
  void update(vec2::Vec2 position, vec2::Vec2 direction, CharacterState state);
  void render(SDL_Rect camera);

private:
  int current_frame;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
  SDL_RendererFlip flip;
  enum AnimationState {
    idle_forward,
    idle_back,
    idle_side,
    walk_forward,
    walk_back,
    walk_side
  } anim_state;
};