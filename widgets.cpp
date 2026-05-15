#include "widgets.hpp"
#include "graphics.hpp"
#include "myapp.hpp"
using namespace genv;

Widget::Widget(MyApp * parent, const int _x, const int _y, const int _sx, const int _sy) : parent(parent), x(_x), y(_y), sx(_sx), sy(_sy) {
    parent->register_ws(this);
}

bool Widget::is_selected(const int mx, const int my)
{
    return mx> x && mx< x + sx && my> y && my< y+ sy;
}