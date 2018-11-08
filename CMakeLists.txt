cmake_minimum_required(VERSION 3.12)
project(LOG)

set(CMAKE_CXX_STANDARD 14)

add_executable(LOG SetUp/main.cpp SetUp/Game.cpp SetUp/Game.h Characters/player.cpp Characters/player.h Characters/enemy.cpp Characters/enemy.h SetUp/TextureManager.cpp SetUp/TextureManager.h SetUp/Map.cpp SetUp/Map.h InternalLogic/Pathfinding.cpp InternalLogic/Pathfinding.h SetUp/Levels.cpp SetUp/Levels.h InternalLogic/Dijkstra.cpp InternalLogic/Dijkstra.h InternalLogic/Kruskal.cpp InternalLogic/Kruskal.h InternalLogic/Prim.cpp InternalLogic/Prim.h War.cpp War.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries(LOG ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

target_link_libraries(LOG pthread)