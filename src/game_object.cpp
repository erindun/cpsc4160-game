#include "game_object.h"

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

GameObject::GameObject(SDL_Renderer *renderer)
    : renderer{renderer}, texture{nullptr}, rect{0, 0, 0, 0} {}

GameObject::~GameObject() {}

void GameObject::init(const std::string &file) {
  SDL_Surface *image = IMG_Load(file.c_str());
  if (image == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, image);
    if (texture == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(image);
}

void GameObject::update() {}

void GameObject::render() {}

void GameObject::quit() {}