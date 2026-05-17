//
// Created by papai on 2026. 05. 17..
//

#ifndef CLIONGRAPHICSKIT_BOARD_HPP
#define CLIONGRAPHICSKIT_BOARD_HPP


#include "piece.hpp"

class Board {
protected:
    Piece squares[8][8];
public:
    Board();
    void reset();

    Piece getPiece(int row, int col) const;
    void setPiece(int row, int col, Piece piece);

};


#endif //CLIONGRAPHICSKIT_BOARD_HPP