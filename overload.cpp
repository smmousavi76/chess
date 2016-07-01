#include "Position.h"
#include "Request.h"
sf::Packet& operator <<(sf::Packet& packet, const Request& req)
{
    return packet << req.from<< req.to;
}

sf::Packet& operator >>(sf::Packet& packet, Request& req)
{
    return packet >> req.from>>req.to;
}
sf::Packet& operator <<(sf::Packet& packet, const Posiotion& pos)
{
    return packet << pos.xPos<< pos.yPos;
}

sf::Packet& operator >>(sf::Packet& packet, Posiotion& pos)
{
    return packet >> pos.xPos>>pos.yPos;
}
