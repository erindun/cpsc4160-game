cmake_minimum_required (VERSION 3.8)

project ("cpsc4160-game")
cmake_minimum_required (VERSION 3.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable (my_game "src/main.cpp"
                     "src/game_engine.h"
                     "src/game_engine.cpp"
                     "src/character.h"
                     "src/character.cpp"
                     "src/vec2.h"
                     "src/input_handler.h"
                     "src/input_handler.cpp"
                     "src/game_object.h"
                     "src/sprite.h"
                     "src/sprite.cpp"
                     "src/character_state.h"
                     "src/character_sprite_handler.h"
                     "src/character_sprite_handler.cpp"
                     "src/tile_handler.h"
                     "src/tile_handler.cpp"
                     "src/rat.h"
                     "src/rat.cpp"
                     "src/collision_handler.h"
                     "src/collidable.h" "src/collision_handler.cpp" "src/particle.h" "src/particle.cpp" "src/tree.h" "src/tree.cpp" "src/ui_handler.h" "src/ui_handler.cpp")

target_link_libraries(my_game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
