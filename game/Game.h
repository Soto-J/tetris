//
// Created by charl on 10/31/2024.
//
#include "Tetris.h"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
    Tetris tetris;
    bool gameOver{false};

    void draw();

    void update();

    void userInput();
};
#endif //GAME_HPP
