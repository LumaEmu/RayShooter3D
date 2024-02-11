#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <raylib.h>

class GameObject {
public:
  Vector3 position;
  Vector3 cube_size; // {width, height, length}

  GameObject();
  GameObject(Vector3 position, Vector3 cube_size);
  ~GameObject();


};

#endif
