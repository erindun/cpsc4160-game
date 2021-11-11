#include "particle.h"
#include <cstdlib>
using vec2::Vec2;

Particle::Particle(Vec2 position, Sprite *sprite, ParticleEffect effect, int start_lifetime)
    : position{position}, sprite{sprite}, effect{effect}, lifetime{start_lifetime} {}

void Particle::render(SDL_Rect camera) { sprite->render(camera); }

void Particle::update() {
  if (effect == ParticleEffect::rain) {
    if (lifetime > 0) {
      // Move raindrop at variable speed each cycle.
      position.y += (rand() % 4) + 4;
      lifetime--;
    } else {
      // Respawn raindrop with a variable lifetime and (constrained) random position.
      lifetime = rand() % 100 + 50;
      position = {position.x + (rand() % 1 * -1) * (rand() % 15), rand() % 180};
    }
    sprite->set_dstrect_pos(position.x, position.y);
  }
}

ParticleEmitter::ParticleEmitter(ParticleEffect effect_type,
                                 SDL_Renderer *renderer)
    : effect_type{effect_type}, renderer{renderer} {

  if (effect_type == ParticleEffect::rain) {
    for (int i = 0; i <= MAX_PARTS; i++) {
      auto particle = new Particle(
          Vec2{(i * 100) + rand() % 15, rand() % 180},
          new Sprite("../assets/rain.png", renderer, RAIN_WIDTH, RAIN_HEIGHT),
          effect_type, rand() % 100 + 50);
      particle->get_sprite()->set_dstrect_pos(particle->get_pos().x,
                                              particle->get_pos().y);
      particles.push_back(particle);
    }
  }
}

void ParticleEmitter::render(SDL_Rect camera) {
  for (auto particle : particles) {
    particle->render(camera);
  }
}

void ParticleEmitter::update() {
  for (auto particle : particles) {
    particle->update();
  }
}
