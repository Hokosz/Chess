//
// Created by papai on 2026. 05. 17..
//

#ifndef CLIONGRAPHICSKIT_BOARDWGT_HPP
#define CLIONGRAPHICSKIT_BOARDWGT_HPP

// grafikai megjelenítés

#include "widgets.hpp"
#include "game.hpp"

class Boardwgt final : public Widget{
protected:
    Game& game;
    int selectedx, selectedy;
    int tilesize;
public:
    Boardwgt(MyApp *, Game&, int, int, int, int);
    void draw() const override;
    void handle(genv::event ev) override;


};


#endif //CLIONGRAPHICSKIT_BOARDWGT_HPP