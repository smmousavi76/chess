#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
#include <SFML/Network.hpp>

struct Posiotion
{
    int xPos;
    int yPos;
    bool operator==(Posiotion pos)
    {
        if(xPos == pos.xPos && yPos == pos.yPos)
        return true;
        return false;
    }
    Posiotion()
    {

    }
    Posiotion(int x, int y)
    {
        xPos=x;
        yPos=y;
    }

};
sf::Packet& operator <<(sf::Packet& packet, const Posiotion& pos);
sf::Packet& operator >>(sf::Packet& packet, Posiotion& pos);

#endif // POSITION_H_INCLUDED
