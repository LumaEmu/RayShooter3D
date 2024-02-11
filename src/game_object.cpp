#include "../include/game_object.hpp"

GameObject::GameObject()
  : position(Vector3{0.0f, 0.0f, 0.0f}), cube_size(Vector3{0.0f, 0.0f, 0.0f}) {

}

GameObject::GameObject(Vector3 position, Vector3 cube_size)
  : position(position), cube_size(cube_size) {

}

GameObject::~GameObject() {

}
