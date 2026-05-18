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

bool Game::trymove(int fromcol, int fromrow, int tocol, int torow)
{
    Piece p = board.getPiece(fromcol, fromrow);
    Piece q = board.getPiece(tocol, torow);

    if (p.isEmpty())
        return false;

    if (!islegal(fromcol, fromrow, tocol, torow, p, q, true))
        return false;

    Piece oldFrom = p;
    Piece oldTo = q;
    int oldWkc = wkingcol, oldWkr = wkingrow;
    int oldBkc = bkingcol, oldBkr = bkingrow;

    board.setPiece(tocol, torow, p);
    board.setPiece(fromcol, fromrow, Piece());

    if (p.type == PieceType::KING) {
        if (p.color == PieceColor::WHITE) { wkingcol = tocol; wkingrow = torow; }
        else { bkingcol = tocol; bkingrow = torow; }
    }

    bool illegal = incheck();

    if (illegal) {
        board.setPiece(fromcol, fromrow, oldFrom);
        board.setPiece(tocol,   torow,   oldTo);
        wkingcol = oldWkc; wkingrow = oldWkr;
        bkingcol = oldBkc; bkingrow = oldBkr;
        return false;
    }

    white_move = !white_move;
    return true;
}

bool Game::islegal(const int fromcol, const int fromrow,
                   const int tocol,   const int torow,
                   const Piece p, const Piece q,
                   bool checkTurn)
{
    if (checkTurn) {
        if ((white_move && p.color != PieceColor::WHITE) ||
            (!white_move && p.color != PieceColor::BLACK))
            return false;
    }

    if (p.color == q.color)
        return false;

    const int dc = tocol - fromcol;
    const int dr = torow - fromrow;

    switch (p.type) {

        case PieceType::PAWN: {
            bool ok = false;

            if (p.color == PieceColor::WHITE) {
                if (dc == 0 && dr == 1 && q.isEmpty()) ok = true;
                if (!ok && abs(dc) == 1 && dr == 1 && !q.isEmpty()) ok = true;
                if (!ok && dc == 0 && fromrow == 1 && dr == 2 && q.isEmpty()) ok = true;
                return ok;
            }

            if (p.color == PieceColor::BLACK) {
                if (dc == 0 && dr == -1 && q.isEmpty()) ok = true;
                if (!ok && abs(dc) == 1 && dr == -1 && !q.isEmpty()) ok = true;
                if (!ok && dc == 0 && fromrow == 6 && dr == -2 && q.isEmpty()) ok = true;
                return ok;
            }

            return false;
        }

        case PieceType::KNIGHT:
            if ((abs(dc) == 2 && abs(dr) == 1) ||
                (abs(dc) == 1 && abs(dr) == 2)) {
                return true;
            }
            return false;

        case PieceType::ROOK:
            if (dc != 0 && dr != 0) {
                return false;
            }

            if (dc != 0) {
                for (int i = 1; i < abs(dc); i++) {
                    if (((!board.getPiece(fromcol + i, fromrow).isEmpty()) && (dc > 0)) ||
                        ((!board.getPiece(fromcol - i, fromrow).isEmpty()) && (dc < 0)))
                        return false;
                }
            }

            if (dr != 0) {
                for (int i = 1; i < abs(dr); i++) {
                    if (((!board.getPiece(fromcol, fromrow + i).isEmpty()) && (dr > 0)) ||
                        ((!board.getPiece(fromcol, fromrow - i).isEmpty()) && (dr < 0)))
                        return false;
                }
            }

            return true;

        case PieceType::BISHOP:
            if (abs(dc) != abs(dr)) {
                return false;
            }

            for (int i = 1; i < abs(dr); i++) {
                if (
                    ((!board.getPiece(fromcol + i, fromrow + i).isEmpty()) && (dc > 0 && dr > 0)) ||
                    ((!board.getPiece(fromcol + i, fromrow - i).isEmpty()) && (dc > 0 && dr < 0)) ||
                    ((!board.getPiece(fromcol - i, fromrow + i).isEmpty()) && (dc < 0 && dr > 0)) ||
                    ((!board.getPiece(fromcol - i, fromrow - i).isEmpty()) && (dc < 0 && dr < 0))
                ) return false;
            }

            return true;

        case PieceType::QUEEN:
            if ((abs(dc) != abs(dr)) && dc != 0 && dr != 0)
                return false;

            if (abs(dc) == abs(dr)) {
                for (int i = 1; i < abs(dr); i++) {
                    if (
                        ((!board.getPiece(fromcol + i, fromrow + i).isEmpty()) && (dc > 0 && dr > 0)) ||
                        ((!board.getPiece(fromcol + i, fromrow - i).isEmpty()) && (dc > 0 && dr < 0)) ||
                        ((!board.getPiece(fromcol - i, fromrow + i).isEmpty()) && (dc < 0 && dr > 0)) ||
                        ((!board.getPiece(fromcol - i, fromrow - i).isEmpty()) && (dc < 0 && dr < 0))
                    ) return false;
                }
            }

            if (dc == 0 || dr == 0) {
                if (dc != 0) {
                    for (int i = 1; i < abs(dc); i++) {
                        if (((!board.getPiece(fromcol + i, fromrow).isEmpty()) && (dc > 0)) ||
                            ((!board.getPiece(fromcol - i, fromrow).isEmpty()) && (dc < 0)))
                            return false;
                    }
                }
                if (dr != 0) {
                    for (int i = 1; i < abs(dr); i++) {
                        if (((!board.getPiece(fromcol, fromrow + i).isEmpty()) && (dr > 0)) ||
                            ((!board.getPiece(fromcol, fromrow - i).isEmpty()) && (dr < 0)))
                            return false;
                    }
                }
            }

            return true;

        case PieceType::KING:
            if (abs(dc) <= 1 && abs(dr) <= 1) {
                return true;
            }
            return false;

        default:
            break;
    }

    return false;
}



bool Game::incheck(){
    Piece k;
    int kcol, krow;

    if (white_move) {
        k = board.getPiece(wkingcol, wkingrow);
        kcol = wkingcol;
        krow = wkingrow;
    } else {
        k = board.getPiece(bkingcol, bkingrow);
        kcol = bkingcol;
        krow = bkingrow;
    }

    for (int i = 0; i < 64; i ++) {
        const int col = (i % 8);
        const int row = (i / 8);

        Piece attacker = board.getPiece(col, row);
        if (attacker.isEmpty()) continue;

        if (k.color == PieceColor::WHITE &&
            attacker.color == PieceColor::BLACK &&
            islegal(col, row, kcol, krow, attacker, k, false)) {
            return true;
            }

        if (k.color == PieceColor::BLACK &&
            attacker.color == PieceColor::WHITE &&
            islegal(col, row, kcol, krow, attacker, k, false)) {
            return true;
            }
    }
    return false;
}