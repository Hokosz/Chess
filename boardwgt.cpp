//
// Created by papai on 2026. 05. 17..
//

#include "boardwgt.hpp"
#include "graphics.hpp"

using namespace genv;

Boardwgt::Boardwgt(MyApp *parent, const int x, const int y, const int sx, const int sy) :
                    Widget(parent, x, y, sx, sy){
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
            gout << color(40, 40, 40);
        }
        gout << box(tilesize, tilesize);

    }

    // számozás
    for (int i = 0; i < 8; i++) {
        const bool white = (i % 2 == 0);
        gout << move_to(x + 2, y + 2 + i*tilesize);

        if (white) gout << color(40, 40, 40);
        else gout << color(215, 215, 215);

        gout << text(std::to_string(i+1));

        gout << move_to(x + (tilesize-2) - 8 + i*tilesize, y - 12 + 8*tilesize);

        if (white) gout << color(215, 215, 215);
        else gout << color(40, 40, 40);

        gout << text(colums[i]);
    }
}
void Boardwgt::handle(event ev) {
}
