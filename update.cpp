#include "Update.h"

Update::Update(int mt): connection(mt)
{
    myTurn = mt;
    count=0;
    for(int i=0; i<2; i++)
        player[i] = new Player(i);
        int i;
        //cout<<" player \n";
       // cin>>i;
    playerTurn = 0;
    phase = -1;
    req.from.xPos=-1;
    req.from.yPos=-1;
    req.to.xPos=-1;
    req.to.yPos=-1;

}

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
    Piece *a,*b,*c;
    char data[6];//= {'1', '2', '3', '4', '5','6'};
    bool flag=1;
    ///send "data" using socket
    //char data[6];
    sf::Packet packet;
    packet << req;

    connection.sendPacket(packet);
    playerTurn=(playerTurn+1)%2;
}

void Update::recieveData(Data& data)
{
    if(connection.haveInQ() == 0)
    {
        return;
    }
    sf::Packet packet = connection.receivePacket();
    Request tmp;
    packet >> tmp;
    cout<<tmp.from.xPos<<" "<<tmp.from.yPos<<" "<<tmp.to.xPos<<" "<<tmp.to.yPos <<"\tHOOOORA!\n";

    Piece* from = whichPiece(tmp.from);
    Piece* to = whichPiece(tmp.to);

    if(to == nullptr)
    {
        from->move(tmp.to);

        data.possibleMoves.clear();
        this->makeData(data);
    }
    else
    {
        from->move(tmp.to);
        player[(playerTurn+1)%2]->remove(to);

        data.possibleMoves.clear();
        this->makeData(data);
    }

    playerTurn=(playerTurn+1)%2;
}

void Update::start()
{
    connection.start();
    cout <<"START func END\n";
    return ;

}

void Update::getEvent(MouseEvent& mouse,Data& data)
{
    if(phase == -1)
    {
        this->prepair();
        this->makeData(data);
        phaseChanger();
        return;

    }
    std::cout<<playerTurn<<endl;
    if(playerTurn  != myTurn)
    {
        recieveData(data);
        std::cout<<playerTurn<<endl;
    }
    else if(mouse.clicked)
    {
        count++;
        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        if(phase == 0) ///Phase Select Mine Piece
        {
            if(target != nullptr)
                if(target->owner == myTurn)
                {
                    for(auto po : target->PossibleMove(target->owner))
                    {
                        Piece* tmp = whichPiece(po);
                        if(tmp==nullptr)
                        {
                            if(check1(target, po))
                                data.possibleMoves.push_back(po);
                        }
                        else if(tmp->owner!= target->owner)
                        {
                            if(check1(target, po))
                                data.possibleMoves.push_back(po);


                        }
                    }
                    if(data.possibleMoves.size()>0)
                    {
                        std::cout <<data.possibleMoves.size() <<"\n";
                        for(auto po:data.possibleMoves)
                        {
                            std::cout <<po.xPos <<" " <<po.yPos <<"\n";
                        }
                        lastTarget = target;
                        phaseChanger();
                    }
                }
        }
        if(phase == 1)
        {
            bool flag = false;
            for(int i=0; i<data.possibleMoves.size(); i++)
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
                    req.from = lastTarget->pos;
                    req.to = mouse.pos;
                    lastTarget->move(mouse.pos);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    req.from = lastTarget->pos;
                    req.to = target->pos;
                    lastTarget->move(mouse.pos);
                    player[(playerTurn+1)%2]->remove(target);
                    this->makeData(data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    playerChanger();
                }
            }
        }

    }
//    a.terminate();
    return;


}

void Update::makeData(Data& data)
{
    data.pieces.clear();
    for(int j=0; j<2; j++)
    {
        for(int i=0; i<player[j]->pieces.size(); i++)
        {
            data.pieces.push_back(player[j]->pieces[i]);
        }

    }
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
bool Update::check(Piece* target, Posiotion pos)
{
    if(target->typeId == 4||target->typeId==10) ///Rook
    {
        if(pos.xPos == target->pos.xPos)
        {
            for(int i=min(pos.yPos, target->pos.yPos)+1;i<max(pos.yPos, target->pos.yPos);i++ )
            {
                if(this->whichPiece(Posiotion(pos.xPos, i))!= nullptr)
                    return false;
            }
            return true;
        }
        if(pos.yPos == target->pos.yPos)
        {
            for(int i=min(pos.xPos, target->pos.xPos)+1;i<max(pos.xPos, target->pos.xPos);i++ )
            {
                if(this->whichPiece(Posiotion(i, pos.yPos))!= nullptr)
                    return false;
            }
            return true;

        }

    }

else
    return 1;

}

bool Update::check1(Piece* target, Posiotion pos){
    if(target->typeId == 0||target->typeId==6) ///bishop
    {
        if(pos.xPos > target->pos.xPos && pos.yPos > target->pos.yPos)
        {
            for(int i=1;i<8;i++ ){
                if(this->whichPiece(Posiotion(target->pos.xPos + i, target->pos.yPos+i))!= nullptr)
                    return false;
            }
        }
        if(pos.xPos > target->pos.xPos && pos.yPos < target->pos.yPos)
        {
            for(int i=1;i<8;i++ ){
                if(this->whichPiece(Posiotion(target->pos.xPos + i, target->pos.yPos-i))!= nullptr)
                    return false;

            }
        }
        if(pos.xPos < target->pos.xPos && pos.yPos > target->pos.yPos)
        {
            for(int i=1;i<8;i++ ){
                if(this->whichPiece(Posiotion(target->pos.xPos - i, target->pos.yPos+i))!= nullptr)
                    return false;

            }
        }
        if(pos.xPos < target->pos.xPos && pos.yPos < target->pos.yPos)
        {
            for(int i=1;i<8;i++ ){
                if(this->whichPiece(Posiotion(target->pos.xPos - i, target->pos.yPos-i))!= nullptr)
                    return false;
            }
        }




        if(pos.xPos > target->pos.xPos && pos.yPos > target->pos.yPos)
        {
            for(int i=1;i>0;i-- ){
                if(this->whichPiece(Posiotion(target->pos.xPos + i, target->pos.yPos+i))!= nullptr)
                    return false;
            }
        }
        if(pos.xPos > target->pos.xPos && pos.yPos < target->pos.yPos)
        {
            for(int i=1;i>0;i-- ){
                if(this->whichPiece(Posiotion(target->pos.xPos + i, target->pos.yPos-i))!= nullptr)
                    return false;

            }
        }
        if(pos.xPos < target->pos.xPos && pos.yPos > target->pos.yPos)
        {
            for(int i=1;i>0;i-- ){
                if(this->whichPiece(Posiotion(target->pos.xPos - i, target->pos.yPos+i))!= nullptr)
                    return false;

            }
        }
        if(pos.xPos < target->pos.xPos && pos.yPos < target->pos.yPos)
        {
            for(int i=1;i>0;i-- ){
                if(this->whichPiece(Posiotion(target->pos.xPos - i, target->pos.yPos-i))!= nullptr)
                    return false;
            }
        }












    }
    else
        return 1;
}









bool Update::check2(Piece* target, Posiotion pos)
{
    if(target->typeId == 3||target->typeId==9) ///queen
    {
        if(pos.xPos == target->pos.xPos && pos.yPos == target->pos.yPos)

        {
            for(int i=min(pos.yPos, target->pos.yPos)+1;i<max(pos.yPos, target->pos.yPos);i++ ){

            for(int j=min(pos.xPos, target->pos.xPos)+1;j<max(pos.xPos, target->pos.xPos);j++ )


            {
                if(this->whichPiece(Posiotion(j, i))!= nullptr)
                    return false;
            }}
            return true;
        }
    }
    else
        return 1;
}
