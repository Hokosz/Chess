//
// Created by papai on 2026. 05. 17..
//

#include "boardwgt.hpp"
#include "graphics.hpp"

using namespace genv;

Boardwgt::Boardwgt(MyApp *parent, Game& g, const int x, const int y, const int sx, const int sy) :
                    Widget(parent, x, y, sx, sy), game(g){
    selectedx = -1;
    selectedy = -1;
    tilesize = sx/8;
}



void Boardwgt::draw() const {
    gout.load_font("LiberationSans-Regular.ttf", 10);
    //tábla
    char colums[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int i = 0; i < 64; i++) {
        //kockák
        gout << move_to(x + (i % 8)* tilesize, y + (i / 8) * tilesize);

        if ((i + (i / 8)) % 2 == 0) {
            gout << color(215, 215, 215);
        }
        else {
            gout << color(117, 95, 75);
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
    const Board& b = game.getBoard();
    for (int i = 0; i < 64; i++) {
        if (Piece p = b.getPiece((i % 8),7 - (i / 8)); !p.isEmpty()) {
            gout << move_to(x + ((i) % 8)* tilesize, y + (i / 8) * tilesize);
            gout << color(0,0,0);
            gout.load_font("OpenChessFont.ttf", 50);

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


void Boardwgt::handle(event ev) {
}
