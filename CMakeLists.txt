cmake_minimum_required(VERSION 3.20)
project(RayShooter3D)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
    GIT_SHALLOW 1
  )
  FetchContent_MakeAvailable(raylib)
endif()

set (SOURCES src/main.cpp src/game.cpp src/game_object.cpp src/player.cpp src/resource_manager.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
