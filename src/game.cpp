#include "../include/game.hpp"
#include <raylib.h>

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

void Game::updateGame() {

}

void Game::resetGame() {

}

void Game::processInput() {

}

void Game::checkCollisions() {
  
}
