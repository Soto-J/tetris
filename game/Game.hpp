#ifndef GAME_HPP
#define GAME_HPP

#include "Tetris.hpp"

class Game {
 public:
  Tetris tetris;
  bool gameOver{false};

  void draw();

  void update();

  void userInput();
};

#endif  // GAME_HPP
