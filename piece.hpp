//
// Created by papai on 2026. 05. 15..
//

#ifndef CLIONGRAPHICSKIT_PIECE_HPP
#define CLIONGRAPHICSKIT_PIECE_HPP
#include "widgets.hpp"

// szín, típus


class Piece{
    protected:
        bool white;
        char type;
    public:
    Piece(bool, char);
    ~Piece();

};


#endif //CLIONGRAPHICSKIT_PIECE_HPP