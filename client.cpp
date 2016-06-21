#include "Client.h"
#include <iostream>

Client::Client()
{
    setting.antialiasingLevel = 4;
    window = new sf::RenderWindow(sf::VideoMode(800,800), "Chess " , sf::Style::Default, setting);
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
    window->draw(*board);
    std::cout <<data.pieces.size() <<"\n";
    for(int i=0;i<data.pieces.size();i++)
    {
        sf::Sprite sprite;
        sprite.setTexture(pieceTexture[data.pieces[i]->typeId]);
        sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
        sprite.setPosition(data.pieces[i]->pos.xPos*100+50, data.pieces[i]->pos.yPos*100+50);
        if(data.pieces[i]->owner)
            ;
           // sprite.setRotation(180);
        else
            sprite.setRotation(0);
            window->draw(sprite);
    }



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
    pieceTexture.clear();
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Bishop.png");//type id =0
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Knight.png");//1
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/King.png");//2
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Queen.png");//3
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Rook.png");//4
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Pawn.png");//5
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Bishop2.png");
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Knight2.png");
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/King2.png");
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Queen2.png");
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Rook2.png");
    pieceTexture.push_back(sf::Texture());
    pieceTexture.back().loadFromFile("Pics/Pawn2.png");

}

void Client::makeBoard()
{
    board = new Board(8,8);
    sf::RectangleShape r(sf::Vector2f(100,100));
    r.setFillColor(sf::Color::White);
}
