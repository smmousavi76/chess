#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Event.h"
#include "Data.h"
#include "Board.h"
#include <SFML/Network.hpp>


class Client
{
    sf::ContextSettings setting;
    sf::RenderWindow* window;
    sf::Event event;
    std::vector<sf::RectangleShape> boardLines;
    std::vector<sf::Texture> pieceTexture;
    Board* board;
    void makeBoard();
    void loadTexture();
public:
    Data data;
    Client(bool s);
    ~Client();
    void start();
    void cycle(Data data);
    Event getEvent();
    void close();

};

#endif // CLIENT_H_INCLUDED
