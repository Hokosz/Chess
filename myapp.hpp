//
// Created by papai on 2026. 04. 15..
//

#ifndef CLIONGRAPHICSKIT_MYAPP_HPP
#define CLIONGRAPHICSKIT_MYAPP_HPP
#include <vector>

//event_loop, ablak

class Widget;

class MyApp {
protected:
    std::vector<Widget*> ws;

    int width, height;

public:
    MyApp(int, int);

    void register_ws(Widget *);

    virtual ~MyApp() = default;

    void event_loop() const;
};

#endif //CLIONGRAPHICSKIT_MYAPP_HPP
