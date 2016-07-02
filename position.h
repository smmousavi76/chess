#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include <SFML/Network.hpp>

struct Posiotion
{
    sf::Uint8 xPos;
    sf::Uint8 yPos;
    bool operator==(Posiotion pos)
    {
        if(xPos == pos.xPos && yPos == pos.yPos)
        return true;
        return false;
    }
    Posiotion()
    {

    }
    Posiotion(sf::Uint8 x, sf::Uint8 y)
    {
        xPos=x;
        yPos=y;
    }

};
sf::Packet& operator <<(sf::Packet& packet, const Posiotion& pos);
sf::Packet& operator >>(sf::Packet& packet, Posiotion& pos);

#endif // POSITION_H_INCLUDED
