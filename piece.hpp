//
// Created by papai on 2026. 05. 15..
//

#ifndef CLIONGRAPHICSKIT_PIECE_HPP
#define CLIONGRAPHICSKIT_PIECE_HPP
#include "widgets.hpp"

// még lesz leszármazott, ráadásul 6
class Piece: public Widget{
    protected:
        bool white;
    public:
    Piece(MyApp*, int, int, int, int, bool);
    ~Piece() override;
    void draw() const override;
    void handle(genv::event ev) override;

};


#endif //CLIONGRAPHICSKIT_PIECE_HPP