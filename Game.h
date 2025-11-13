#ifndef GAME_H
#define GAME_H
#include "Connection.h"

namespace game{
    static Connection connection;

    void registerMe();
    void ready();
    void getShips();
    void sendBoard();
    void getUpdates();
    void getBoard();
    void sendMove();
}

#endif