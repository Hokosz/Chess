#ifndef DROPDOWN_HPP
#define DROPDOWN_HPP

#include "widgets.hpp"
#include <vector>
#include <string>

class Dropdown final : public Widget {
    protected:
    std::vector<std::string> items;

    int visible_count;
    int selected_index;
    int scroll_offset;
    bool opened;

public:
    Dropdown(MyApp* parent,
             int x, int y,
             int sx, int sy,
             const std::vector<std::string>& items,
             int visible_count);

    void draw() const override;
    void handle(genv::event ev) override;

    std::string value() const;
};

#endif
