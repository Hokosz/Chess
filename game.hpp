//
// Created by papai on 2026. 05. 16..
//

#ifndef CLIONGRAPHICSKIT_GAME_HPP
#define CLIONGRAPHICSKIT_GAME_HPP



// lépés, Board hívás, ki jön?, App-tól fogadni a cuccost,
// továbbadni Appnak amit kapott

#include "board.hpp"

class Game {
protected:
    Board board;
    bool white_move = true;
public:
    Game();

    const Board& getBoard() const;

    bool isWhiteMove() const;

    void reset();
    bool tryMove(int fromrow, int fromcol, int torow, int tocol);

};


#endif //CLIONGRAPHICSKIT_GAME_HPP