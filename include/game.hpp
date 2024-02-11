#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "enemy.hpp"
#include "level.hpp"
#include "resource_manager.hpp"

class Game {
public:
  float SCREEN_WIDTH;
  float SCREEN_HEIGHT;

  unsigned int current_level;

  ResourceManager *resource_manager;  

  Player *player;

  Game(float SCREEN_WIDTH, float SCREEN_HEIGHT);
  ~Game();

  void initGame();
  void clearResources();
  void drawGame();
  void updateGame(Vector3 &old_camera_position);
  void processInput();

  void UnloadTextures();

private:
  void resetGame();
  void checkCollisions(Vector3 &old_camera_position);

};

#endif
