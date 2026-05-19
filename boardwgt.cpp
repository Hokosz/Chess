//
// Created by papai on 2026. 05. 17..
//

#include "boardwgt.hpp"

#include <iostream>

#include "graphics.hpp"

using namespace genv;

Boardwgt::Boardwgt(MyApp *parent, Game& g, const int x, const int y, const int sx, const int sy) :
                    Widget(parent, x, y, sx, sy), game(g){
    selectedx = -1;
    selectedy = -1;
    tilesize = sx/8;
}



void Boardwgt::draw() const {
    gout.load_font("../LiberationSans-Regular.ttf", 10);
    //tábla
    char colums[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i = 0; i < 64; i++) {
        //kockák
        const int col = (i % 8);
        const int row = (i / 8);
        gout << move_to(x + col * tilesize, y + row * tilesize);

        if ((i + row) % 2 == 0) {
            if (selectedx == col && selectedy == (7 - row)) {
                gout << color(215, 215, 255);
            } else {
                gout << color(215, 215, 215);
            }
        } else {
            if (selectedx == col && selectedy == (7 - row)) {
                gout << color(117, 95, 120);
            } else {
                gout << color(117, 95, 75);
            }
        }
        gout << box(tilesize, tilesize);

    }

    // számozás
    for (int i = 0; i < 8; i++) {
        const bool white = (i % 2 == 0);
        gout << move_to(x + 2, y + 2 + i*tilesize);

        if (white) gout << color(117, 95, 75);
        else gout << color(215, 215, 215);

        gout << text(std::to_string(8-i));

        gout << move_to(x + (tilesize-2) - 8 + i*tilesize, y - 12 + 8*tilesize);

        if (white) gout << color(215, 215, 215);
        else gout << color(117, 95, 75);

        gout << text(colums[i]);
    }

    // bábuk
    const Board& b = game.getboard();
    for (int i = 0; i < 64; i++) {
        const int col = (i % 8);
        const int row = (i / 8);
        if (Piece p = b.getPiece(col,7 - row); !p.isEmpty()) {
            gout << move_to(x + col * tilesize, y + row * tilesize);
            gout << color(0,0,0);
            gout.load_font("../OpenChessFont.ttf", 50);

            if (p.color == PieceColor::WHITE) {
                switch (p.type) {
                    case PieceType::PAWN:
                        gout << text('P');
                        break;
                    case PieceType::KNIGHT:
                        gout << text('N');
                        break;
                    case PieceType::BISHOP:
                        gout << text('B');
                        break;
                    case PieceType::ROOK:
                        gout << text('R');
                        break;
                    case PieceType::QUEEN:
                        gout << text('Q');
                        break;
                    case PieceType::KING:
                        gout << text('K');
                        break;
                    default:break;
                }
            }
            else {
                switch (p.type) {
                    case PieceType::PAWN:
                        gout << text('O');
                        break;
                    case PieceType::KNIGHT:
                        gout << text('M');
                        break;
                    case PieceType::BISHOP:
                        gout << text('V');
                        break;
                    case PieceType::ROOK:
                        gout << text('T');
                        break;
                    case PieceType::QUEEN:
                        gout << text('W');
                        break;
                    case PieceType::KING:
                        gout << text('L');
                        break;
                    default:break;
                }
            }
        }
    }
}


void Boardwgt::handle(const event ev) {
    if (ev.type == ev_mouse &&
        ev.button == btn_left &&
        is_selected(ev.pos_x, ev.pos_y)) {

        const int col = (ev.pos_x - x) / tilesize;
        const int row = 7 - (ev.pos_y - y) / tilesize;

        if (selectedx == -1) {
            selectedx = col;
            selectedy = row;
        }
        else {
            game.trymove(selectedx, selectedy, col, row);

            selectedx = selectedy =-1;
        }
        std::cout << selectedx << " " << selectedy << std::endl;
    }
}
