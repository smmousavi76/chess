#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include "Player.h"
#include "MouseEvent.h"
#include "Data.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Client.h"
#include "Player.h"
#include <cstring>
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
    bool translate_socket(string recieved);
   bool send_socket(Data data);
    void WhichPiece();
    void makeData(Data& data);
    void Attack(Piece *target ,Data data);

   Data string_to_vector(string a);
    string vector_to_string(Data data);
    int check(int a);

    string char_to_string(char *a);
    char * string_to_char(string a);

    };

#endif // UPDATE_H_INCLUDED
