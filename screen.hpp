//
// Created by papai on 2026. 05. 13..
//

#ifndef CLIONGRAPHICSKIT_SCREEN_HPP
#define CLIONGRAPHICSKIT_SCREEN_HPP

#include "widgets.hpp"

class Screen final : public Widget {
protected:
    std::string value;

public:
    Screen(MyApp* parent,
             int x, int y,
             int sx, int sy,
             std::string value);

    void draw() const override;
    void handle(genv::event ev) override;

    void set_value(const std::string &text);
};


#endif //CLIONGRAPHICSKIT_SCREEN_HPP