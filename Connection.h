#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#include <SFML/Network.hpp>
#include <SFML/System/Thread.hpp>
#include <queue>



class Connection
{
public:
    bool error;
    bool connected;
private:

    sf::TcpSocket socket;
    sf::Thread sendT;
    sf::Thread receiveT;
    std::queue<sf::Packet> sendQ;
    sf::Mutex sendQmutex;
    std::queue<sf::Packet> receiveQ;
    sf::Mutex receiveQmutex;
    public:
    Connection();
    void start();
    void sendPacket(sf::Packet);
    sf::Packet receivePacket();
    void end();
    private:
    void send();
    void receive();
};



#endif // CONNECTION_H_INCLUDED
