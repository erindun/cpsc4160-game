# Assignment 2: Game Core (CPSC 4160 Fall 2021 - Garrett Duncan)

This program is a demo of what will become my collection game. All artwork was created by me.
My initial idea is for mice to run across the screen, and you must "hunt" as many as you can
within a timeframe, although this is subject to change.

The character can be controlled in 8-directions using WASD or the arrow keys. The ESC
key terminates the program.

I initially used position-based movement when I was implementing player movement. However,
this didn't quite give me the control that I wanted. Diagonal movement did not work, and movement
was too rigid and snappy. I switched to velocity-based movement, which allows the player to be controlled
in a very fluid manner. I also took advantage of the velocity movement vectors to control the player's animation logic.
My position-based movement can be seen in the InputHandler::handle_pos function, but it is unused.

To build and run the program, run the following commands in the project root:
```
make
./my_game
```

The project directory can be cleaned by running `make clean`.