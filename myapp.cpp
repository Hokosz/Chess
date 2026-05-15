//
// Created by papai on 2026. 04. 15..
//

#include "myapp.hpp"
#include <fstream>
#include <iostream>

#include "graphics.hpp"
#include "widgets.hpp"


using namespace std;
using namespace genv;

MyApp::MyApp(const int width, const int height) : width(width), height(height) {
    gout.open(width, height);
} ;


void MyApp::register_ws(Widget *w) {
    ws.push_back(w);
}

void MyApp::event_loop() const {
    event ev;
    int focus = -1;
    while (gin >> ev) {

        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (size_t i = 0; i < ws.size(); i++) {
                if (ws[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                }
            }
        }

        if (focus != -1) {
            ws[focus]->handle(ev);
        }

        gout << move_to(0, 0)
             << color(0, 0, 0)
             << box(width, height);

        for (Widget* w : ws) {
            w->draw();
        }

        gout << refresh;
    }
}
