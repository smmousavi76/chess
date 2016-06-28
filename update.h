#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include "Data.h"
#include "Player.h"
#include "Request.h"
#include <iostream>

#include <SFML/Network.hpp>


using namespace std;
class Update
{
private:
    int movement;  //its a counter that counts every mouse movement and check it with every pieces range to move it or not.
    int playerTurn;
    int phase;
    Player *player[2];
    Piece* lastTarget;
    Request req;
    sf::TcpSocket socket;

public:

    Piece* target;
    int  count;
    Update();
    ~Update();
    void start();
    void getEvent(MouseEvent&,Data&);
private:
    void translatePos(Posiotion&);
    Piece* whichPiece(Posiotion);
    void prepair();
    void phaseChanger();
    bool playerChanger(Posiotion from,Posiotion to);
    bool finish();
    int remove_piecce();
    void WhichPiece();
    void makeData(Data& data);
    void sendData (char *data);
    bool recieveData();
};

#endif // UPDATE_H_INCLUDED
