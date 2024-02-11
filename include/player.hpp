#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.hpp"

class Player : public GameObject {
public:
  Camera3D player_camera;

  Player(Vector3 position, Vector3 cube_size);
  ~Player();
};


#endif // !PLAYER_H
