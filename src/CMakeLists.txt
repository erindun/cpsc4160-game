cmake_minimum_required (VERSION 3.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable (my_game "main.cpp"
                     "game_engine.h"
                     "game_engine.cpp"
                     "character.h"
                     "character.cpp"
                     "vec2.h"
                     "input_handler.h"
                     "input_handler.cpp"
                     "game_object.h"
                     "sprite.h"
                     "sprite.cpp"
                     "character_state.h" "tile_handler.h")

target_link_libraries(my_game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
