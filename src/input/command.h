#pragma once

/// Commands that may be sent to the game
/// engine or to game objects via player input.
enum class Command { quit, move_up, move_down, move_left, move_right, none };