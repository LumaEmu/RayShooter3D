#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "../include/game.hpp"

const int FPS = 60;
const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 800;

int main() {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ray Shooter 3D");
  SetTargetFPS(FPS);
  DisableCursor();

  // Color *mapPixels = LoadImageColors(imMap);
  // UnloadImage(imMap);
  
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  game.initGame();
  
  Vector3 mapPosition = { 0.0f, 0.0f, 0.0f }; 

  while (!WindowShouldClose()) {
    UpdateCamera(&game.player->player_camera, CAMERA_FREE);
    BeginDrawing();

      ClearBackground(RAYWHITE);
    
      BeginMode3D(game.player->player_camera);
        DrawGrid(100, 1.0f);
        DrawModel(game.resource_manager->model, mapPosition, 1.0f, WHITE);
      EndMode3D();
   
    EndDrawing();
  }

  game.clearResources();

  CloseWindow();

  return 0;

}
