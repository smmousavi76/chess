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

bool Update::playerChanger()
{
    Piece *a,*b,*c;
    char data[30];
    ///send "data" using socket
    b=whichPiece(req.from);
    data[0]=b->owner;
    data[1]=b->pos.xPos;
    data[2]=b->pos.yPos;
    if (socket.send(data, 30) != sf::Socket::Done)
    {
     cout<<" error in sending data \n";
    }
    if (socket.send(data, 30) == sf::Socket::Done)
    {
     cout<<" sending is ok \n";
    }
    playerTurn = (playerTurn+1)%2;
    ///get new data
    std::size_t received;
    bool flag;
    if (socket.receive(data, 100, received) != sf::Socket::Done)
    {
        cout<< "error in receieved data  \n";
        flag=0;

    }
    else flag=1;

    req.to.xPos=data[1];
    req.to.yPos=data[2];
    int owner=data[0];
//    Piece *c;
    Posiotion pos;
     pos.xPos=req.to.xPos;
     pos.yPos=req.to.yPos;
    c=whichPiece(pos);
    c->owner=owner;


    for(int i=0;i<=player[owner]->pieces.size();i++)
    {
        if(player[owner]->pieces[i]==c)
        {
            player[owner]->pieces[i]=c;
        }
    }

    playerTurn = (playerTurn+1)%2;
}

//bool Update::recieveData()
//{
  //  char data[30];

//}
Update::Update()
{

    count=0;
    for(int i=0; i<2; i++)
        player[i] = new Player(i);
        int i;
        //cout<<" player \n";
       // cin>>i;
    playerTurn = 1;
    phase = -1;


}

void Update::start()
{
    if(true)///PlayerId
    {
        sf::Socket::Status status = socket.connect("192.168.1.106", 5400);
        if (status != sf::Socket::Done)
        {
            std::cout <<"Cant Connect To Server\n";
            return;
        }


        sf::TcpListener listener;

        // bind the listener to a port
        if (listener.listen(5400) != sf::Socket::Done)
        {
            std::cout <<"Cant Listen on this Port\n";
        }
        // accept a new connection
        sf::TcpSocket socket;
        if (listener.accept(socket) != sf::Socket::Done)
        {
            std::cout <<"Cant Accept connection from Client\n";
        }
    }
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
    if(recieveData());
    if(mouse.clicked)
    {
        count++;
        translatePos(mouse.pos);
        target = whichPiece(mouse.pos);
        if(phase == 0) ///Phase Select Mine Piece
        {
            if(target != nullptr)
                if(target->owner == playerTurn)
                {
                    for(auto po : target->PossibleMove(target->owner))
                    {
                        Piece *a;
                        a=whichPiece(po);
                        if(a!=nullptr)
                        {
                            if(a->owner!=target->owner)
                            {
                                ///pawn attack bishop
                                if(a->typeId!=3||a->typeId!=9||a->typeId!=2 ||a->typeId!=8)
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
                    lastTarget->move(mouse.pos);
                    data.possibleMoves.clear();
                    phaseChanger();
                    cout <<".";
                    req.from = lastTarget->pos;
                    req.to = mouse.pos;
                    playerChanger();
                }
                else if(target->owner == (playerTurn+1)%2)
                {
                    lastTarget->move(mouse.pos);
                    player[(playerTurn+1)%2]->remove(target);
                    this->makeData(data);
                    data.possibleMoves.clear();
                    phaseChanger();
                    req.from = lastTarget->pos;
                    req.to = target->pos;
                    playerChanger();
                }
            }
        }
    }
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
