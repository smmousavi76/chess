#include "Game.h"
#include <iostream>
#include "Client.h"
Game::Game()
{

    bool d=1;
    client = new Client(d);
    string s;

    cin>>s;
    if(s == "create"){
        update = new Update(0);
    }
    else if(s == "join")
        update = new Update(1);
}

void Game::start()
{
    client->start();
    update->start();
    main();
    close();
}

void Game::main()
{
    while(!events.Close)
    {
        update->getEvent(events.mouseEvent,data);
        client->cycle(data);
        events = client->getEvent();
    }

}

void Game::close()
{
    client->close();
}

Game::~Game()
{
    delete client;
    delete update;
}

