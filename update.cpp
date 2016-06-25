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
        playerTurn = 0;
        phase = -1;
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
    if(mouse.clicked)
    {
        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        if(phase == 0) ///Phase Select Mine Piece
        {
            if(target != nullptr)
                if(target->owner == playerTurn)
                {
                    for(auto po : target->PossibleMove(target->owner))
                    {
                       // std::cout«"po \n ";
                        Piece *a;
                        //std::cout«"po 2 \n ";
                        a=whichPiece(po);
                        //std::cout«"po 3 \n";
                        if(a!=nullptr)
                        {
                            if(a->owner!=target->owner)
                            {
                                   data.possibleMoves.push_back(po);
                            }
                        }
                        else
                        {
                            data.possibleMoves.push_back(po);
                        }
                    }
                    if(data.possibleMoves.size()>0)
                    {
                        lastTarget = target;
                        phaseChanger();
                    }
                }
        }
        if(phase == 1)
        {
            std::cout<<" clicked 5  ";
            bool flag = false;
            for(int i=0;i<data.possibleMoves.size();i++)
                if(mouse.pos == data.possibleMoves[i])
                {
                    flag = true;
                    break;
                }
            if(flag)
            {
                target = whichPiece(mouse.pos);
                if(target == nullptr)
                {
                    lastTarget->move(mouse.pos);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    lastTarget->move(mouse.pos);
                    player[playerTurn]->Attack(target,data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }

            }
        }
    }
    target->start();
    return;
}

bool Update::finish()
{
    if(player[2]->Piece_Count==0||player[1]->Piece_Count==0)
        return 1;
    else return 0;
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

/*
std::vector<CPiece *> Update::write(std::string recieved);
{

}
std::string Update::read(std::vector <CPiece> send);
{

}
*/
