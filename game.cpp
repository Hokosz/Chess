//
// Created by papai on 2026. 05. 16..
//

#include "game.hpp"

Game::Game() {
    reset();
    white_move = true;
}

void Game::reset() {
    board.reset();
    white_move = true;
}

const Board& Game::getBoard() const {
    return board;
}

bool Game::isWhiteMove() const {return white_move;}

bool Game::tryMove(int fromrow, int fromcol, int torow, int tocol) {
    return true;
}