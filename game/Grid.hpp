#ifndef GAME_HPP
#define GAME_HPP

#include "Tetris.hpp"

// Preview Viewport
// constexpr int PREVIEW_VIEW_X{18};
// constexpr int PREVIEW_VIEW_Y{1};
// constexpr int PREVIEW_VIEW_HEIGHT{6};
// constexpr int PREVIEW_VIEW_WIDTH{8};

class Grid {
 public:
  int grid[20][10];

  Tetris tetris;
  bool gameOver{false};

  Grid();

  void init();

  void draw();

  void update();

  void userInput();

 private:
  // Grid Viewport
  int GRID_VIEW_X;
  int GRID_VIEW_Y;
  int GRID_COLS;
  int GRID_ROWS;
};

#endif  // GAME_HPP
