#include "Grid.hpp"

Grid::Grid() {
  GRID_VIEW_X = 1;
  GRID_VIEW_Y = 1;
  GRID_COLS = 15;
  GRID_ROWS = 23;

  this->init();
}

void Grid::init() {
  for (int i = 0; i < GRID_ROWS; i++) {
    for (int j = 0; j < GRID_COLS; j++) {
      this->grid[i][j] = 0;
    }
  }
}

void Grid::draw() {
  DrawRectangle(  // Grid Viewport
      GRID_VIEW_X * CELL_SIZE, GRID_VIEW_Y * CELL_SIZE, GRID_COLS * CELL_SIZE,
      GRID_ROWS * CELL_SIZE, YELLOW);

  DrawRectangle(  // Preview Viewport
      PREVIEW_VIEW_X * CELL_SIZE, PREVIEW_VIEW_Y * CELL_SIZE,
      PREVIEW_VIEW_HEIGHT * CELL_SIZE, PREVIEW_VIEW_WIDTH * CELL_SIZE, YELLOW);

  this->tetris.draw();
}

void Grid::update() { this->tetris.update(); }

void Grid::userInput() {
  if (IsKeyPressed(KEY_LEFT)) {
    this->tetris.shiftTetrominoLeft(GRID_VIEW_X);
  }

  if (IsKeyPressed(KEY_RIGHT)) {
    this->tetris.shiftTetrominoRight(GRID_COLS);
  }

  if (IsKeyPressed(KEY_DOWN)) {
    this->tetris.shiftTetrominoDown(GRID_ROWS);
  }
}
