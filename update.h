#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include "Player.h"
#include "MouseEvent.h"
#include "Data.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Client.h"

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
    void translate_socket();
    void send_socket();
    void WhichPiece();

    std::vector<CPiece *> write(std::string recieved);
    std::string read(std::vector <CPiece> send);

    };

#endif // UPDATE_H_INCLUDED
