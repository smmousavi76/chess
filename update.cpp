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
                std::cout<<" clicked   ";

        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        client.loadPossibleMoves(target);

        if(phase == 0) ///Phase Select Mine Piece
        {
                            std::cout<<" clicked  2 ";

                            std::cout<<" clicked   2/5";



            if(target != nullptr)

                if(target->owner == playerTurn)
                {
                                    std::cout<<" clicked  3 ";

                    /*
                    for(int i=target->pos.xPos-target->range;i<=target->pos.xPos+target->range;i++)
                    {
                        for(int j=target->pos.yPos-target->range;j<=target->pos.yPos+target->range;j++)
                        {
                            if(i<0 || j<0 || i>=7 || j>=9)
                                continue;
                            bool flag = true;
                            for(int k=0;k<player[playerTurn]->pieces.size();k++)
                            {
                                if(player[playerTurn]->pieces[k]->pos == Posiotion(i,j))
                                    flag = false;
                            }
                            if(flag)
                            {
                                data.possibleMoves.push_back(Posiotion(i,j));
                            }

                        }
                        */
                    }

                    if(data.possibleMoves.size()>0)
                    {
                                        std::cout<<" clicked  4 ";

                        lastTarget = target;
                        phaseChanger();
                    }
                }

            return;
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

                    phaseChanger();
                    playerChanger();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    lastTarget->move(mouse.pos);
                    Attack(target,data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }
            }

        }
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

void Update::Attack(Piece *target ,Data data)
{
        // remove from vector
    //data->pieces.pop

}

