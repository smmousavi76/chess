#include "Client.h"
#include <iostream>

Client::Client()
{
    setting.antialiasingLevel = 4;
    window = new sf::RenderWindow(sf::VideoMode(700,900), "Chess " , sf::Style::Close, setting);
    window->setFramerateLimit(30);

}

Client::~Client()
{
    delete window;
}

void Client::start()
{
  makeBoard();
    loadTexture();
}

void Client::cycle(Data data)
{
    window->clear();


        //window->draw(sprite);


    window->display();
}

Event Client::getEvent()
{
    Event events;
    while(window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            events.Close = true;
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            events.mouseEvent.clicked = true;
        }
        if(event.type == sf::Event::MouseMoved)
        {
            events.mouseEvent.pos.xPos = event.mouseMove.x;
            events.mouseEvent.pos.yPos = event.mouseMove.y;
        }
    }
    return events;
}

void Client::close()
{
    window->close();
}

void Client::loadTexture()
{

}

void Client::makeBoard()
{

}
