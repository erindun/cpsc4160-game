# Assignment 4: Adding particle effects and colliders (CPSC 4160 Fall 2021 - Garrett Duncan)

This program is a demo of what will become my collection game. All artwork was created by me.
My initial idea is for mice to run across the screen, and you must "hunt" as many as you can
within a timeframe.

The character can be controlled in 8-directions using WASD or the arrow keys. The ESC
key terminates the program.

I used CMake to build and deploy the project between Linux and Windows systems. The following commands will build and run the game:
```
mkdir build && cd build
cmake ..
make
./my_game
```

Please note that, due to hardcoded paths to the `assets` directory, the executable must be run inside the `build` folder.

To clean rebuild the project, simply remove the `build` directory and repeat the above steps.