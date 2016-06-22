#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include "Player.h"
#include "MouseEvent.h"
#include "Data.h"
#include <iostream>
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
    void Attack(Piece *target,Data data );
    void NewPosition();
    void getEvent(MouseEvent&,Data&);
    void translatePos(Posiotion&);
    Piece* whichPiece(Posiotion);
    void prepair();
    void phaseChanger();
    void playerChanger();
    bool finish();
    int remove_piecce();
    void translate_socket();
    void send_socket();
    void WhichPiece();

    };

#endif // UPDATE_H_INCLUDED
