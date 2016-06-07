#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Event.h"
#include "Data.h"

class Client
{
    sf::ContextSettings setting;
    sf::RenderWindow* window;
    sf::Event event;
    std::vector<sf::RectangleShape> boardLines;
    std::vector<sf::Texture> pieceTexture;
    void makeBoard();
    void loadTexture();
public:
    Client();
    ~Client();
    void start();
    void cycle(Data data);
    Event getEvent();
    void close();

};

#endif // CLIENT_H_INCLUDED
