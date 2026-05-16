#include "myapp.hpp"
#include "button.hpp"
#include <string>

using namespace std;


//renderelés, input a Game-nak


class App final : public MyApp {
protected:

public:
    App(int const width, int const height) : MyApp(width, height){

    }
};

int main()
{
    const App app(600, 800);

    app.event_loop();

    return 0;
}