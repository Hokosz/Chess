//
// Created by papai on 2026. 05. 17..
//

#ifndef CLIONGRAPHICSKIT_BOARDWGT_HPP
#define CLIONGRAPHICSKIT_BOARDWGT_HPP

// grafikai megjelenítés

#include "widgets.hpp"

class Boardwgt : public Widget{
protected:
    int selectedx, selectedy;
    int tilesize;
public:
    Boardwgt(MyApp *, int, int, int, int);
    void draw() const override;
    void handle(genv::event ev) override;

};


#endif //CLIONGRAPHICSKIT_BOARDWGT_HPP