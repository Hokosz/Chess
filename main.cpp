#include "myapp.hpp"
#include "button.hpp"
#include "boardwgt.hpp"

using namespace std;


//renderelés, input a Game-nak


class App final : public MyApp {
protected:
    Boardwgt *boardwgt;
public:
    App(int const width, int const height) : MyApp(width, height){
        boardwgt = new Boardwgt(this, 0, 0, 400, 400);
    }
};

int main()
{
    const App app(600, 800);

    app.event_loop();

    return 0;
}