#include "Client.h"
#include <iostream>
#include "Board.h"
Client::Client()
{
    setting.antialiasingLevel = 4;
    window = new sf::RenderWindow(sf::VideoMode(800,800), "Chess " , sf::Style::Close, setting);
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
    Board* board = new Board(8,8);
    sf::RectangleShape r(sf::Vector2f(100,100));
    r.setFillColor(sf::Color::White);
       while(1)
       {
        window->draw(*board);
        window->display();
       }


}
