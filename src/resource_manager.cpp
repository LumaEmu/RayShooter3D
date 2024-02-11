#include "../include/resource_manager.hpp"
#include <raylib.h>


ResourceManager::ResourceManager() {
}

void ResourceManager::loadGraphics(const char *map_file, const char *level_texture_atlas_file) {
  this->image_map = LoadImage(map_file);
  this->cube_map  = LoadTextureFromImage(this->image_map);
  this->mesh      = GenMeshCubicmap(image_map, (Vector3){ 1.0f, 1.0f, 1.0f});
  this->model     = LoadModelFromMesh(mesh);
  
  this->level_texture_atlas = LoadTexture(level_texture_atlas_file);
  this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = level_texture_atlas;

  this->map_pixels = LoadImageColors(this->image_map);
}

void ResourceManager::unloadGraphics() {
  UnloadImage(this->image_map);
  UnloadTexture(this->cube_map);
  UnloadTexture(this->level_texture_atlas);
  UnloadModel(this->model);
}

ResourceManager::~ResourceManager() {
}
