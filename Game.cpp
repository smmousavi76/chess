#include "Game.h"
#include <iostream>
#include "Client.h"
Game::Game()
{
    bool d=1;
    client = new Client(d);
}

void Game::start()
{
    client->start();
    main();
    close();
}

void Game::main()
{

    while(!events.Close)
    {
        update.getEvent(events.mouseEvent,data);
        client->cycle(data);
        events = client->getEvent();
    }

}

void Game::refreshUpdate()
{
    while(!events.Close)
    {
        update.getEvent(events.mouseEvent,data);
    }
}

void Game::refreshClient()
{
    while(!events.Close)
    {
        client->cycle(data);
    }
}

void Game::close()
{
    client->close();
}

Game::~Game()
{
    delete client;
}

