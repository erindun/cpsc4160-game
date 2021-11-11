#pragma once
#include "sprite.h"
#include "vec2.h"
#include <vector>
#include <SDL.h>

static const int MAX_PARTS = 12;
static const int RAIN_WIDTH = 8;
static const int RAIN_HEIGHT = 64;

enum class ParticleEffect { rain };

class Particle {
public:
  Particle(vec2::Vec2 position, Sprite *sprite, ParticleEffect effect, int start_lifetime);
  void update();
  void render(SDL_Rect camera);
  Sprite *get_sprite() { return sprite; }
  vec2::Vec2 get_pos() { return position; }

private:
  vec2::Vec2 position;
  vec2::Vec2 velocity;
  Sprite *sprite;
  int lifetime;
  ParticleEffect effect;
};

class ParticleEmitter {
public:
  ParticleEmitter(ParticleEffect effect_type, SDL_Renderer *renderer);
  void update();
  void render(SDL_Rect camera);

private:
  SDL_Renderer *renderer;
  std::vector<Particle *> particles;
  ParticleEffect effect_type;
};