#include "Connection.h"
#include <iostream>




Connection::Connection() : receiveT(&Connection::receive, this), sendT(&Connection::send, this)
{
    connected = false;
    error = false;
}

void Connection::start()
{

    sf::TcpListener listener;
    if (listener.listen(53000) != sf::Socket::Done)
    {

        std::cerr <<"Cant Start Listening on Port " <<53000 <<"\n";
        error = true;
        return;
    }
    // accept a new connection
    if (listener.accept(socket) != sf::Socket::Done)
    {
        // error...

        std::cerr <<"connection Number"  <<"Cant accept tcp Connection\n";
        error = true;
        return;
    }
    connected = true;
    std::cout <<"Client "  <<" successfuly Connected to Serrver\n";
    receiveT.launch();
    sendT.launch();
}

void Connection::receive()
{
    while(connected)
    {
        sf::Packet packet;
        socket.receive(packet);
        receiveQmutex.lock();
        receiveQ.push(packet);
        receiveQmutex.unlock();
    }
}

void Connection::send()
{
    while(connected)
    {
        sf::Packet packet;
        sendQmutex.lock();
        while(sendQ.empty())
        {
            sendQmutex.unlock();
            sf::sleep(sf::milliseconds(10));
            sendQmutex.lock();
        }
        packet = sendQ.front();
        sendQ.pop();
        sendQmutex.unlock();
        socket.send(packet);
    }
}

void Connection::sendPacket(sf::Packet packet)
{
    sendQmutex.lock();
    sendQ.push(packet);
    sendQmutex.unlock();
}

sf::Packet Connection::receivePacket()
{
    sf::Packet packet;
    receiveQmutex.lock();
    if(!receiveQ.empty())
    {
        packet = receiveQ.front();
        receiveQ.pop();
    }
    receiveQmutex.unlock();
    return packet;
}


