//
// Created by papai on 2026. 05. 15..
//

#ifndef CLIONGRAPHICSKIT_PIECE_HPP
#define CLIONGRAPHICSKIT_PIECE_HPP

// szín, típus

enum class  PieceType {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
};

enum class  PieceColor {
    NONE,
    WHITE,
    BLACK,
};

struct Piece {
    PieceType type = PieceType::EMPTY;
    PieceColor color = PieceColor::NONE;

    bool isEmpty() const;
};


#endif //CLIONGRAPHICSKIT_PIECE_HPP