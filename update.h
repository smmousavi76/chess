#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED
#include <SFML/System.hpp>
#include "Data.h"
#include "Player.h"
#include "Request.h"
#include <iostream>
#include <thread>
#include <SFML/Network.hpp>
#pragma comment(lib, "sfml-network.lib")
#include <queue>
#include <vector>
#include <list>
#include "Connection.h"
#include "Player.h"
using namespace std;
class Update
{
private:
    int movement;  //its a counter that counts every mouse movement and check it with every pieces range to move it or not.
    int playerTurn;
    int myTurn;
    int phase;
    Player *player[2];
    Piece* lastTarget;
    Request req;
    Connection connection;
public:
    Piece* target;
    int  count;
    Update(int mt);
    ~Update();
    void start();
    void getEvent(MouseEvent&,Data&);
    void thread_receive();
    bool check_recieve();
private:
    void translatePos(Posiotion&);
    Piece* whichPiece(Posiotion);
    void prepair();
    void phaseChanger();
    void playerChanger();
    bool finish();
    int remove_piecce();
    void WhichPiece();
    void makeData(Data& data);
    void sendData (char *data);
    void recieveData(Data&);

    bool check(Piece* target, Posiotion pos);

};

#endif // UPDATE_H_INCLUDED
