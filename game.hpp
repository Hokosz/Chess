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
    int wkingcol = 4, wkingrow = 0;
    int bkingcol = 7, bkingrow = 0;
public:
    Game();

    const Board& getboard() const;

    bool iswhiteMove() const;

    void reset();
    bool trymove(int fromcol, int fromrow, int tocol, int torow);
    bool islegal(int fromcol, int fromrow, int tocol, int torow, Piece p, Piece q, bool checkTurn);
    bool incheck();

};


#endif //CLIONGRAPHICSKIT_GAME_HPP