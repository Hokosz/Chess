//
// Created by papai on 2026. 05. 15..
//

#include "piece.hpp"

using namespace genv;

Piece::Piece(MyApp *parent, const int x, const int y, const int sx, const int sy, const bool white, const char type) :
                Widget(parent, x, y, sx, sy), white(white), type(type){
}

Piece::~Piece() {}

void Piece::move(int x, int y) {

}


void Piece::handle(event ev) {}



