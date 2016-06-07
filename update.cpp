#include "Update.h"
void Update::prepair()
{
    player[0]->prepair();
    player[1]->prepair();

}
void Update::phaseChanger()
{

    phase = (phase+1)%2;

}

void Update::playerChanger()
{
    playerTurn = (playerTurn+1)%2;
}
Update::Update()
{
    for(int i=0;i<2;i++)
        player[i] = new Player(i);
    playerTurn = 0;//first player
    phase = -1; ///Phase Pre
    //del=0;
}

bool Update::finish()
    {
        //if(player[2]->count_piecce==0||player[1]->count_piecce==0)
       //     return 1;
       // else return 0;
    }

Update::~Update()
{

}
void Update::translatePos(Posiotion& pos)
{
    pos.xPos /= 100;
    pos.yPos /= 100;
}
Piece* Update::whichPiece(Posiotion pos)
{
    for (int i=0 ; i<player[playerTurn]->pieces.size() ; i++)
    {
        if(pos == player[playerTurn]->pieces[i]->pos)
        {
            return player[playerTurn]->pieces[i];
        }
    }
    for (int i=0 ; i<player[(playerTurn+1)%2]->pieces.size() ; i++)
    {
        if(pos == player[(playerTurn+1)%2]->pieces[i]->pos)
        {
            return player[(playerTurn+1)%2]->pieces[i];
        }
    }
    return nullptr;
}

void Update::getEvent(MouseEvent& mouse,Data& data)
{
    std::cout <<phase <<"\n";
    if(phase == -1)
    {
        this->prepair();
        for(int j=0;j<2;j++)
        {
            for(int i=0;i<player[j]->pieces.size();i++)
            {

                data.pieces.push_back(player[j]->pieces[i]);

            }

        }

        phaseChanger();
        return;
    }
}
