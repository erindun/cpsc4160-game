#pragma once

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
  Sprite(const std::string &filepath, SDL_Renderer *renderer, int width,
         int height);
  ~Sprite();
  void render(SDL_Rect camera);
  void set_srcrect_pos(int x, int y) {
    srcrect.x = x;
    srcrect.y = y;
  }
  void set_dstrect_pos(int x, int y) {
    dstrect.x = x;
    dstrect.y = y;
  }

  SDL_RendererFlip flip;
  SDL_Texture *texture;

private:
  SDL_Texture *load_texture(SDL_Renderer *renderer,
                            const std::string &filepath);
  SDL_Renderer *renderer;
  SDL_Rect srcrect;
  SDL_Rect dstrect;
};