#include "game_object.h"

GameObject::GameObject(SDL_Renderer *renderer)
    : renderer{renderer}, texture{nullptr}, rect{0, 0, 0, 0} {}
GameObject::~GameObject() {}
void GameObject::init() {}
void GameObject::update() {}
void GameObject::render() {}
void GameObject::quit() {}