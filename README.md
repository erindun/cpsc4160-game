# Assignment 5: Finish your game! (CPSC 4160 Fall 2021 - Garrett Duncan)

Scaredy Cat: see how long you can avoid the horde of rats!

The character can be controlled in 8-directions using WASD or the arrow keys. The ESC
key pauses the game.

I selected the following components:
- Start/finish screens
- In-play UI: "Lives" heads-up item and pause menu
- Textual items with fonts


I used CMake to build and deploy the project between Linux and Windows systems. The following commands will build and run the game:
```
mkdir build && cd build
cmake ..
make
./my_game
```

Please note that, due to hardcoded paths to the `assets` directory, the executable must be run inside the `build` folder.

To clean rebuild the project, simply remove the `build` directory and repeat the above steps.