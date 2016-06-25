#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include "Player.h"
#include "MouseEvent.h"
#include "Data.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Client.h"
#include "Player.h"
using namespace std;
class Update
{
private:
    int movement;  //its a counter that counts every mouse movement and check it with every pieces range to move it or not.
    int playerTurn;
    int phase;
    Player *player[2];
    Piece* lastTarget;

public:
    Piece* target;

    bool del;
    Update();
    ~Update();
    void NewPosition();
    void getEvent(MouseEvent&,Data&);
    void translatePos(Posiotion&);
    Piece* whichPiece(Posiotion);
    void prepair();
    void phaseChanger();
    void playerChanger();
    bool finish();
    int remove_piecce();
    vector <CPiece *> translate_socket(vector<CPiece *> recieved);
    void send_socket(string send,Data data);
    void WhichPiece();
    void makeData(Data& data);
//<<<<<<< Updated upstream

    std::vector<CPiece *> write(std::string recieved);
    std::string read(std::vector <CPiece> send);
//=======
    void Attack(Piece *target ,Data data);
    //vector<CPiece *> write(string recieved);
    string read(Data data );
    int check(int a);
//>>>>>>> Stashed changes

    };

#endif // UPDATE_H_INCLUDED
