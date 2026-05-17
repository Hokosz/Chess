//
// Created by papai on 2026. 05. 17..
//

#include "board.hpp"

Board::Board() {
    reset();
}

void Board::reset() {
    squares[0][0] = {PieceType::ROOK,   PieceColor::WHITE};
    squares[1][0] = {PieceType::KNIGHT, PieceColor::WHITE};
    squares[2][0] = {PieceType::BISHOP, PieceColor::WHITE};
    squares[3][0] = {PieceType::QUEEN,  PieceColor::WHITE};
    squares[4][0] = {PieceType::KING,   PieceColor::WHITE};
    squares[5][0] = {PieceType::BISHOP, PieceColor::WHITE};
    squares[6][0] = {PieceType::KNIGHT, PieceColor::WHITE};
    squares[7][0] = {PieceType::ROOK,   PieceColor::WHITE};

    for (int i = 0; i < 8; i++) {
        squares[i][1] = {PieceType::PAWN,   PieceColor::WHITE};
    }

    squares[0][7] = {PieceType::ROOK,   PieceColor::BLACK};
    squares[1][7] = {PieceType::KNIGHT, PieceColor::BLACK};
    squares[2][7] = {PieceType::BISHOP, PieceColor::BLACK};
    squares[3][7] = {PieceType::QUEEN,  PieceColor::BLACK};
    squares[4][7] = {PieceType::KING,   PieceColor::BLACK};
    squares[5][7] = {PieceType::BISHOP, PieceColor::BLACK};
    squares[6][7] = {PieceType::KNIGHT, PieceColor::BLACK};
    squares[7][7] = {PieceType::ROOK,   PieceColor::BLACK};

    for (int i = 0; i < 8; i++) {
        squares[i][6] = {PieceType::PAWN,   PieceColor::BLACK};
    }
}

void Board::setPiece(const int row, const int col, Piece piece) {
    squares[row][col] = {piece};
}
Piece Board::getPiece(const int row, const int col) const {
    return squares[row][col];
}