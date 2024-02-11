#include "../include/game.hpp"
#include <raylib.h>
#include <iostream>

Game::Game(float SCREEN_WIDTH, float SCREEN_HEIGHT)
  : SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT) {
}

Game::~Game() {
  delete this->player;
  delete this->resource_manager;
}

void Game::initGame() {

  this->resource_manager = new ResourceManager();
  this->resource_manager->loadGraphics("../resources/game_map1.png", "../resources/game_map1_atlas.png");


  this->player = new Player(Vector3{2.0f, 0.5f, 2.0f}, Vector3{1.0f, 1.0f, 1.0f});
  this->player->player_camera.position   = this->player->position;
  this->player->player_camera.target     = (Vector3){3.0f, 0.5f, 3.0f};
  this->player->player_camera.up         = (Vector3){0.0f, 1.0f, 0.0f};
  this->player->player_camera.fovy       = 60.0f;
  this->player->player_camera.projection = CAMERA_PERSPECTIVE;
}

void Game::clearResources() {
  this->resource_manager->unloadGraphics();
}

void Game::drawGame() {

}

void Game::updateGame(Vector3 &old_camera_position) {
  this->checkCollisions(old_camera_position);
}


void Game::resetGame() {

}

void Game::processInput() {

}

void Game::checkCollisions(Vector3 &old_camera_position) {
  
  int map_height = this->resource_manager->cube_map.height;
  int map_width  = this->resource_manager->cube_map.width;

  Vector3 current_camera_position = this->player->player_camera.position;

  for (int row = 0; row < map_height; row++) {
    for (int col = 0; col < map_width; col++) {
      if (this->resource_manager->map_pixels[row * map_width + col].r == 255 &&
          CheckCollisionCircleRec(Vector2{current_camera_position.x, current_camera_position.z}, 0.1f, Rectangle{(float)col, (float)row, 1.0f, 1.0f})) {

        this->player->player_camera.position = old_camera_position;
        
      }
    }
  }
}
