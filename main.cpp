#include "myapp.hpp"
#include "button.hpp"
#include <string>

using namespace std;

class App final : public MyApp {
protected:
    vector<Button*> buttons;
public:
    App(int const width, int const height) : MyApp(width, height){
        for (int i = 0; i < 64; ++i) {
            buttons.push_back(new Button(this, 10+(50*(i%8)), 10+(50*(i/8) + 50), 50, 50,
                "B",
                ((i + (i / 8)) % 2 == 0), // sakktábla
                [](){}));
        }
    }
};

int main()
{
    const App app(600, 800);

    app.event_loop();

    return 0;
}