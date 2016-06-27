#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Client.h"
#include "Event.h"
#include "Update.h"
#include "Data.h"

class Game
{
    Client* client;
    Event events;
    Update *update;
    Data data;
    void refreshClient();
    void refreshUpdate();
public:
    Game();
    ~Game();
    void start();
    void main();
    void close();

};


#endif // GAME_H_INCLUDED
