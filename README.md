# Assignment 2: Game Core (CPSC 4160 Fall 2021 - Garrett Duncan)

This program is a demo of what will become my collection game. All artwork was created by me.
My initial idea is for mice to run across the screen, and you must "hunt" as many as you can
within a timeframe.

The character can be controlled in 8-directions using WASD or the arrow keys. The ESC
key terminates the program.

I used CMake to build and deploy the project between Linux and Windows. The following block of code will build the environment:
```
mkdir build && cd build
cmake ..
make
```

The executable will be located at `build/src/my_game`. The game can be clean rebuilt by removing the `build` folder and repeating
the above commands.

The project directory can be cleaned by running `make clean`.