#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <raylib.h>

class ResourceManager {
public:
  
  Image image_map;
  Texture2D cube_map;
  Mesh mesh;
  Model model;
  
  Texture2D level_texture_atlas;

  Color *map_pixels;


  ResourceManager();
  ~ResourceManager();
  
  void loadGraphics(const char *map_file, const char *level_texture_atlas_file); 
  void unloadGraphics();

};

#endif // !RESOURCE_MANAGER_H
