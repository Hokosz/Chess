#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "myapp.hpp"

//GUI elements, parent of all

class Widget {
protected:
    MyApp * parent;
    int x, y, sx, sy;
public:
    virtual ~Widget() = default;

    Widget(MyApp *parent, int _x, int _y, int _sx, int _sy);

    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

//szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)
//haha megtaláltam :)

#endif // WIDGETS_HPP_INCLUDED
