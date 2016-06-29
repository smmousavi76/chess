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

bool Update::playerChanger(Posiotion from,Posiotion to)
{
    Piece *a,*b,*c;
    char data[30];
    bool flag=1;
    ///send "data" using socket
    b=whichPiece(req.from);
    if(b->owner==0)
        data[1]='0';
    if(b->owner==1)
        data[1]='1';

        data[0]='1';
        /*
    switch(from.xPos)
    {
        case 1:
        data[2]='0';
        break;
        case 2:
        data[2]='1';
        break;
        case 3:
        data[2]='2';
        break;
        case 4:
        data[2]='3';
        break;
        case 5:
        data[2]='4';
        break;
        case 6:
        data[2]='5';
        break;
        case 7:
        data[2]='6';
        break;
        default :data[2]='7';
        break;
    }
    switch (from.yPos)
    {
        case 1:
        data[3]='0';
        break;
        case 2:
        data[3]='1';
        break;
        case 3:
        data[3]='2';
        break;
        case 4:
        data[3]='3';
        break;
        case 5:
        data[3]='4';
        break;
        case 6:
        data[3]='5';
        break;
        case 7:
        data[3]='6';
        break;
        default: data[3]='7';
        break;
    }
     switch(to.xPos)
    {
        case 1:
        data[4]='0';
        break;
        case 2:
        data[4]='1';
        break;
        case 3:
        data[4]='2';
        break;
        case 4:
        data[4]='3';
        break;
        case 5:
        data[4]='4';
        break;
        case 6:
        data[4]='5';
        break;
        case 7:
        data[4]='6';
        break;
        default :data[4]='7';
        break;
    }
    switch (to.yPos)
    {
        case 1:
        data[5]='0';
        break;
        case 2:
        data[5]='1';
        break;
        case 3:
        data[5]='2';
        break;
        case 4:
        data[5]='3';
        break;
        case 5:
        data[5]='4';
        break;
        case 6:
        data[5]='5';
        break;
        case 7:
        data[5]='6';
        break;
        default: data[5]='7';
        break;
    }



    switch(b->typeId){
    case 1 : data[0]='1';
    break;
    case 2 : data[0]='2';
    break;
    case 3 : data[0]='3';
    break;
    case 4 : data[0]='4';
    break;
    case 5 : data[0]='5';
    break;
    case 6 : data[0]='6';
    break;
    case 7 : data[0]='7';
    break;
    case 8 : data[0]='8';
    break;
    case 9 : data[0]='9';
    break;
    case 10 : data[0]='10';
    break;
    case 11 : data[0]='11';
    break;
    case 12 : data[0]='12';
    break;
    case 13 : data[0]='13';
    break;
    case 14 : data[0]='14';
    break;
    case 15 : data[0]='15';
    break;
    case 16 : data[0]='16';
    break;

    }


    if (socket.send(data, 30) != sf::Socket::Done)
    {
     cout<<" error in sending data \n";
     flag=0;
    }
    if(flag==0)
        return 0;
    else if(flag==1)
        return 1;
*/
    sf::IpAddress recipient = "192.168.1.106";
    unsigned short port = 54000;
    socket.send(data, 100, recipient, port);

//    playerTurn = (playerTurn+1)%2;
}
void Update::recieveData()
{

    Piece *a,*b;
    char data[30];
    std::size_t received;
    bool flag=1;
    /*
   if (socket.receive(data, 100, received) != sf::Socket::Done)
    {
      cout<< "error in receieved data  \n";
      flag=0;

    }
    */
    string st="192.168.1.103";
    sf::IpAddress sender=st;
    unsigned short port;
    socket.receive(data, 30, received, sender, port);

    if(data[1]=='0')
    a->owner=0;
    if(data[1]=='1')
    a->owner=1;
    b->typeId=a->typeId;
    switch(data[2])
    {
    case '0':
    a->pos.xPos=0;
    case '1':
    a->pos.xPos=1;
    case '2':
    a->pos.xPos=2;
    case '3':
    a->pos.xPos=3;
    case '4':
    a->pos.xPos=4;
    case '5':
    a->pos.xPos=5;
    case '6':
    a->pos.xPos=6;
    case '7':
    a->pos.xPos=7;
    }
    switch(data[3])
    {
    case '0':
    a->pos.yPos=0;
    case '1':
    a->pos.yPos=1;
    case '2':
    a->pos.yPos=2;
    case '3':
    a->pos.yPos=3;
    case '4':
    a->pos.yPos=4;
    case '5':
    a->pos.yPos=5;
    case '6':
    a->pos.yPos=6;
    case '7':
    a->pos.yPos=7;
    }
    switch(data[0])
    {
    case '0':
    a->typeId=0;
    case '1':
    a->typeId=1;
    case '2':
    a->typeId=2;
    case '3':
    a->typeId=3;
    case '4':
    a->typeId=4;
    case '5':
    a->typeId=5;
    case '6':
    a->typeId=6;
    case '7':
    a->typeId=7;
    case '8':
    a->typeId=8;
    case '9':
    a->typeId=9;
    case '10':
    a->typeId=10;
    case '11':
    a->typeId=11;
    case '12':
    a->typeId=12;
    case '13':
    a->typeId=13;
    case '14':
    a->typeId=14;
    case '15':
    a->typeId=15;
    }
     switch(data[4])
    {
    case '0':
    b->pos.xPos=0;
    break;
    case '1':
    b->pos.xPos=1;
    break;
    case '2':
    b->pos.xPos=2;
    break;
    case '3':
    b->pos.xPos=3;
    break;
    case '4':
    b->pos.xPos=4;
    break;
    case '5':
    b->pos.xPos=5;
    break;
    case '6':
    b->pos.xPos=6;
    break;
    case '7':
    b->pos.xPos=7;
    break;
    }
    switch(data[5])
    {
    case '0':
    b->pos.yPos=0;
    break;
    case '1':
    b->pos.yPos=1;
    break;
    case '2':
    b->pos.yPos=2;
    break;
    case '3':
    b->pos.yPos=3;
    break;
    case '4':
    b->pos.yPos=4;
    break;
    case '5':
    b->pos.yPos=5;
    break;
     case '6':
    b->pos.yPos=6;
    break;
    case '7':
    b->pos.yPos=7;
    break;
    }
    int owner=a->owner;

    for(int i=0;i<=player[owner]->pieces.size();i++)
    {
        if(player[owner]->pieces[i]->typeId==a->typeId&&player[owner]->pieces[i]->pos.xPos==a->pos.xPos&&player[owner]->pieces[i]->pos.yPos==a->pos.yPos)
        {
            player[owner]->pieces[i]->pos.xPos==b->pos.xPos;
            player[owner]->pieces[i]->pos.yPos==b->pos.yPos;

    }
    }
   // if(flag==1)
    //return 1;
    //else if(flag==0)
        return ;
}

Update::Update()
{

    count=0;
    for(int i=0; i<2; i++)
        player[i] = new Player(i);
        int i;
        //cout<<" player \n";
       // cin>>i;
    playerTurn = 0;
    phase = -1;


}

void Update::start()
{
    if(playerTurn==0)///PlayerId
    {
        /*
        sf::Socket::Status status = socket.connect("172.17.11.71", 10001);

        //127.0,0.1
        if (status != sf::Socket::Done)
        {
            std::cout <<"Cant Connect To Server\n";
            return;
        }
        cout <<"connected to server";
        */

    }
    if(playerTurn==1)
    {
        if (socket.bind(54000) != sf::Socket::Done)
        {
         cout<<"error in recieving \n";        // error...
        }

    /*
        sf::TcpListener listener;
        cout<<"aaaaaaaaaaa";

        // bind the listener to a port
        if (listener.listen(10000) != sf::Socket::Done)
        {
            std::cout <<"Cant Listen on this Port\n";

        }
        // accept a new connection
        sf::TcpSocket socket;
        if (listener.accept(socket) != sf::Socket::Done)
        {
            std::cout <<"Cant Accept connection from Client\n";
        }
        */
    }
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
    //recieveData();
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
                    playerChanger(req.to,req.from);
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
                    playerChanger(req.to,req.from);
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
