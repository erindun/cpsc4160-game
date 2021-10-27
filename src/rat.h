#include "game_object.h"
#include "sprite.h"
#include "vec2.h"
#include <SDL.h>

class Rat : public GameObject {
public:
  Rat(Sprite *sprite, vec2::Vec2 position);
  void update() override {}
  void render(SDL_Rect camera) override;

private:
  Sprite *sprite;
  vec2::Vec2 position;
};