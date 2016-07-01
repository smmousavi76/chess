#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED

#include "Position.h"

struct Request
{
   Posiotion from;
   Posiotion to;
};
sf::Packet& operator >>(sf::Packet& packet, Request& req);
sf::Packet& operator <<(sf::Packet& packet, const Request& req);

#endif // REQUEST_H_INCLUDED
