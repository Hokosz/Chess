//
// Created by papai on 2026. 04. 20..
//

#include "button.hpp"
#include "graphics.hpp"

using namespace genv;

Button::Button(MyApp *parent, const int _x, const int _y, const int _sx, const int _sy, const std::string& _label, std::function<void()> on_click)
    : Widget(parent, _x, _y, _sx, _sy), label(_label), on_click(on_click)
{
}

void Button::draw() const {
    gout.load_font("../liberationSans-Regular.ttf", 20);

    gout << color(200, 200, 200);

    gout << move_to(x, y)
         << box(sx, sy);

    gout << move_to(x, y)
         << color(0, 0, 0)
         << text(label);
}

void Button::handle(const event ev) {
    if (ev.type == ev_mouse &&
        ev.button == btn_left &&
        is_selected(ev.pos_x, ev.pos_y))
    {
        if (on_click) on_click();
    }
}

void Button::set_label(const std::string& s) {
    label = s;
}


std::string Button::get_label() const {
    return label;
}


