#include "dropdown.hpp"

#include <iostream>
#include <ostream>

#include "graphics.hpp"

using namespace genv;

Dropdown::Dropdown(MyApp* parent, int x, int y, int sx, int sy,
                   const std::vector<std::string>& items,
                   const int visible_count)
    : Widget(parent, x, y, sx, sy),
      items(items),
      visible_count(visible_count),
      selected_index(0),
      scroll_offset(0),
      opened(false)
{
}

void Dropdown::draw() const{
    gout << move_to(x, y + sy)
         << color(0, 0, 0)
         << box(sx, visible_count * sy);

    gout << move_to(x, y)
         << color(200, 200, 200)
         << box(sx, sy);

    if (!items.empty()) {
        gout << move_to(x + 4, y + sy/2 + 5)
             << color(0, 0, 0)
             << text(items[selected_index]);
    }

    if (opened) {
        for (int i = 0; i < visible_count; i++) {
            const int idx = scroll_offset + i;
            if (idx >= static_cast<int>(items.size())) break;

            const int iy = y + sy + i * sy;

            gout << move_to(x, iy)
                 << color(230, 230, 230)
                 << box(sx, sy);

            gout << move_to(x + 4, iy + sy/2 + 5)
                 << color(0, 0, 0)
                 << text(items[idx]);
        }
    }
}


void Dropdown::handle(const event ev){
    if (ev.type == ev_mouse &&
        ev.button == btn_left &&
        is_selected(ev.pos_x, ev.pos_y))
    {
        opened = !opened;
        return;
    }

    if (!opened) return;

    // Handle item clicks
    for (int i = 0; i < visible_count; i++) {
        int idx = scroll_offset + i;
        if (idx >= items.size()) break;

        int iy = y + sy + i * sy;

        bool inside =
            ev.pos_x >= x &&
            ev.pos_x <= x + sx &&
            ev.pos_y >= iy &&
            ev.pos_y <= iy + sy;

        if (ev.type == ev_mouse &&
            ev.button == btn_left &&
            inside)
        {
            selected_index = idx;
            opened = false;
            return;
        }
    }

    // Scroll
    if (ev.type == ev_mouse && ev.button == btn_wheelup) {
        if (scroll_offset > 0) scroll_offset--;
    }
    if (ev.type == ev_mouse && ev.button == btn_wheeldown) {
        if (scroll_offset + visible_count < items.size())
            scroll_offset++;
    }
}

std::string Dropdown::value() const {
    return items.empty() ? "" : items[selected_index];
}
