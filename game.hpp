//
// Created by papai on 2026. 05. 16..
//

#ifndef CLIONGRAPHICSKIT_GAME_HPP
#define CLIONGRAPHICSKIT_GAME_HPP

// lépés, Board hívás, ki jön?, App-tól fogadni a cuccost,
// továbbadni Appnak amit kapott

class Game {
protected:
    bool white_move = true;
public:
    Game();

    virtual ~Game();

    virtual void start();
    virtual void move();
    virtual void end();


};


#endif //CLIONGRAPHICSKIT_GAME_HPP