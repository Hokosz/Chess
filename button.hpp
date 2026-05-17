//
// Created by papai on 2026. 04. 20..
//

#ifndef CLIONGRAPHICSKIT_BUTTON_HPP
#define CLIONGRAPHICSKIT_BUTTON_HPP


#include "widgets.hpp"
#include <functional>
#include <string>

class Button final : public Widget {
protected:
    std::string label;

public:
    Button(MyApp *parent, int _x, int _y, int _sx, int _sy, const std::string& _label, std::function<void()> on_click);

    void draw() const override;

    void handle(genv::event ev) override;

    void set_label(const std::string &s);

    std::string get_label() const;

    std::function<void()> on_click;


};


#endif //CLIONGRAPHICSKIT_BUTTON_HPP