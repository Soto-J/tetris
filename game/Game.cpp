//
// Created by charl on 10/31/2024.
//
#include "Game.h"

void Game::draw() {
    this->tetris.draw();
}

void Game::update() {
    this->tetris.update();
}

void Game::userInput() {
    if (IsKeyPressed(KEY_RIGHT)) {
        this->tetris.shiftTetrominoRight();
    }

    if (IsKeyPressed(KEY_LEFT)) {
        this->tetris.shiftTetrominoLeft();
    }

    if (IsKeyPressed(KEY_DOWN)) {
        this->tetris.shiftTetrominoDown();
    }
}
