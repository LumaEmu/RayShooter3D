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

  Texture2D gun = LoadTexture("../resources/PIST1.png");

  while (!WindowShouldClose()) {
    Vector3 old_camera_position = game.player->player_camera.position;

    UpdateCamera(&game.player->player_camera, CAMERA_FIRST_PERSON);
    game.updateGame(old_camera_position);


    BeginDrawing();

      ClearBackground(RAYWHITE);
      
      BeginMode3D(game.player->player_camera);
        DrawGrid(100, 1.0f);
        DrawModel(game.resource_manager->model, mapPosition, 1.0f, WHITE);
      EndMode3D();
   
      DrawTexturePro(gun, 
                     Rectangle{0.0f, 0.0f, 101.0f, 122.0f}, 
                     Rectangle{500.0f, 500.0f, 300.0f, 320.0f}, 
                     Vector2{0.0f, 0.0f}, 0.0f, WHITE);

    EndDrawing();
  }

  game.clearResources();
  
  UnloadTexture(gun);
  CloseWindow();

  return 0;

}
