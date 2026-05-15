//
// Created by papai on 2026. 05. 13..
//

#include "screen.hpp"
#include "graphics.hpp"

using namespace genv;

Screen::Screen(MyApp *parent, const int x, const int y, const int sx, const int sy, std::string _value) :
                Widget(parent, x, y, sx, sy), value(_value) {
}
void Screen::draw() const{
    gout.load_font("digital-7.ttf", 50);
    gout << color(255, 255, 255)
    << move_to(x, y)
    << box(sx, sy)
    << color(0,0,0)
    << move_to(x+sx-gout.twidth(value), y+5)
    << text(value);
}

void Screen::handle(event ev){}


void Screen::set_value(const std::string &text) {
    value = text;
}

