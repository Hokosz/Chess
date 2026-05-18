//
// Created by papai on 2026. 05. 16..
//

#include "game.hpp"

#include <iostream>

Game::Game() {
    reset();
    white_move = true;
}

void Game::reset() {
    board.reset();
    white_move = true;
}

const Board& Game::getboard() const {
    return board;
}

bool Game::iswhiteMove() const {return white_move;}

bool Game::trymove(const int fromcol, const int fromrow, const int tocol, const int torow) {
    const Piece p = board.getPiece(fromcol, fromrow);
    const Piece q = board.getPiece(tocol, torow);

    if (p.isEmpty())
        return false;


    if (!islegal(fromcol, fromrow, tocol, torow, p, q)) {
        return false;
    }

    board.setPiece(tocol, torow, p);
    board.setPiece(fromcol, fromrow, Piece());

    white_move = !white_move;
    return true;
}

bool Game::islegal(const int fromcol, const int fromrow, const int tocol, const int torow,
    const Piece p, const Piece q) {

    if ((white_move && p.color != PieceColor::WHITE) ||
    (!white_move && p.color != PieceColor::BLACK))
        return false;

    if (p.color == q.color)
        return false;

    const int dc = tocol - fromcol;
    const int dr = torow - fromrow;

    //bábuk
    switch (p.type) {
        case PieceType::PAWN:
            if (p.color == PieceColor::WHITE) {

                if (dc == 0 && dr == 1 && q.isEmpty()) {
                    return true;
                }
                if (abs(dc) == 1 && dr == 1 && !q.isEmpty()) {
                    return true;
                }
                if (dc == 0 && fromrow == 1 && dr == 2 && q.isEmpty()) {
                    return true;
                }
                // en passant később
            }

            if (p.color == PieceColor::BLACK) {
                if (dc == 0 && dr == -1 && q.isEmpty()) {
                    return true;
                }
                if (abs(dc) == 1 && dr == -1 && !q.isEmpty()) {
                    return true;
                }
                if (dc == 0 && fromrow == 6 && dr == -2 && q.isEmpty()) {
                    return true;
                }
            }
            return false;
        case PieceType::KNIGHT:
            if ((abs(dc) == 2 && abs(dr) == 1) ||
                (abs(dc) == 1 && abs(dr) == 2)) {
                if ((p.color == PieceColor::WHITE && incheck(board.getPiece(wkingcol, wkingrow)))
                    || (p.color == PieceColor::BLACK && incheck(board.getPiece(bkingcol, bkingrow)))) {
                        return false;
                }

                //TODO: inchek vizsgálat
                return true;
            }
            return false;
        case PieceType::ROOK:
            if (dc != 0 && dr != 0) {
                return false;
            }

            if (dc != 0) {
                for (int i = 1; i < abs(dc); i ++) {

                   if (((!board.getPiece(fromcol + i, fromrow).isEmpty()) && (dc > 0))||
                   ((!board.getPiece(fromcol - i, fromrow).isEmpty()) && (dc < 0)))
                       return false;
                }
            }
            if (dr != 0) {
                for (int i = 1; i < abs(dr); i ++) {

                    if (((!board.getPiece(fromcol, fromrow+i).isEmpty()) && (dr > 0))||
                    ((!board.getPiece(fromcol, fromrow-i).isEmpty()) && (dr < 0)))
                        return false;
                }
            }
            //TODO: inchek vizsgálat
            return true;
        case PieceType::BISHOP:
            if (abs(dc) != abs(dr)) {
                return false;
            }

            for (int i = 1; i < abs(dr); i++) {
                if (
                ((!board.getPiece(fromcol + i, fromrow + i).isEmpty()) && (dc > 0 && dr > 0))||
                ((!board.getPiece(fromcol + i, fromrow - i).isEmpty()) && (dc > 0 && dr < 0))||
                ((!board.getPiece(fromcol - i, fromrow + i).isEmpty()) && (dc < 0 && dr > 0))||
                ((!board.getPiece(fromcol - i, fromrow - i).isEmpty()) && (dc < 0 && dr < 0))
                    )return false;
            }
            //TODO: inchek vizsgálat
            return true;
        case PieceType::QUEEN:
            if ((abs(dc) != abs(dr)) && dc != 0 && dr != 0) return false;

            if (abs(dc) == abs(dr)) {
                for (int i = 1; i < abs(dr); i++) {
                    if (
                    ((!board.getPiece(fromcol + i, fromrow + i).isEmpty()) && (dc > 0 && dr > 0))||
                    ((!board.getPiece(fromcol + i, fromrow - i).isEmpty()) && (dc > 0 && dr < 0))||
                    ((!board.getPiece(fromcol - i, fromrow + i).isEmpty()) && (dc < 0 && dr > 0))||
                    ((!board.getPiece(fromcol - i, fromrow - i).isEmpty()) && (dc < 0 && dr < 0))
                        )return false;
                }
            }

            if (dc == 0 || dr == 0) {
                if (dc != 0) {
                    for (int i = 1; i < abs(dc); i ++) {

                        if (((!board.getPiece(fromcol + i, fromrow).isEmpty()) && (dc > 0))||
                        ((!board.getPiece(fromcol - i, fromrow).isEmpty()) && (dc < 0)))
                            return false;
                    }
                }
                if (dr != 0) {
                    for (int i = 1; i < abs(dr); i ++) {

                        if (((!board.getPiece(fromcol, fromrow+i).isEmpty()) && (dr > 0))||
                        ((!board.getPiece(fromcol, fromrow-i).isEmpty()) && (dr < 0)))
                            return false;
                    }
                }
            }
            //TODO: inchek vizsgálat
            return true;
        case PieceType::KING:
            if (abs(dc) <= 1 or abs(dr) <= 1) {
                if (p.color == PieceColor::WHITE) {wkingcol = tocol; wkingrow = torow;}
                else {bkingcol = tocol; bkingrow = torow;}
                //TODO: inchek vizsgálat
                return true;
            }
            return false;
        default:break;
    }

    //TODO: inchek vizsgálat
    return true;
}

bool Game::incheck(Piece k){

    for (int i = 0; i < 64; i ++) {
        const int col = (i % 8);
        const int row = (i / 8);

        if ((islegal(col, row, wkingcol, wkingrow,board.getPiece(col, row), k)
                    && (k.color == PieceColor::WHITE)) ||
                (islegal(col, row, bkingcol, bkingrow,board.getPiece(col, row), k)
                && (k.color == PieceColor::BLACK))) {
            return true;
        }}
    return false;
}