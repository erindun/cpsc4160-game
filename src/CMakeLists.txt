# CMakeList.txt : CMake project for Cpsc4160Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (main "main.cpp"  "game_engine.h" "game_engine.cpp" "character.h" "character.cpp" "position.h" "input/input_handler.h" "input/input_handler.cpp" "input/command.h"  "game_object.h" "player.h" "player.cpp" "direction.h")

target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image)

# TODO: Add tests and install targets if needed.
