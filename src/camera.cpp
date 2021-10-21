#include "camera.h"

Camera::Camera() {}

Camera::~Camera() {}


void Camera::update(Character& character) { position = character.position; }