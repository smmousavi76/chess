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
        data[0]='0';
    if(b->owner==1)
        data[0]='1';
        data[1]=b->typeId+48;
        data[2]=req.from.xPos+48;
        data[3]=req.from.yPos+48;
        data[4]=req.to.xPos+48;
        data[5]=req.to.yPos+48;

    sf::IpAddress recipient = "192.168.1.106";
    unsigned short port = 54000;
    socket.send(data, 100, recipient, port);
}
void Update::recieveData()
{

    Piece *a,*b;
    char data[30];
    std::size_t received;
    bool flag=1;
    string st="192.168.200.1";
    sf::IpAddress sender=st;
    unsigned short port=54000;
    socket.receive(data, 30, received, sender, port);

    int a_data,b_data,c_data,d_data,e_data;
    int owner=a->owner;
    if(data[0]=='0')
    a->owner=0;
    if(data[0]=='1')
    a->owner=1;
    a_data=data[1];//1=typeid
    b_data=data[2];//2=xpos from
    c_data=data[3];//3=ypos from
    d_data=data[4];//4 xpos to
    e_data=data[5];//5= ypos to

    a->typeId=a_data-48;
    b->typeId=a->typeId;
    a->pos.xPos=b_data-48;
    a->pos.yPos=c_data-48;
    b->pos.xPos=d_data-48;
    b->pos.yPos=e_data-48;

    for(int i=0;i<=player[owner]->pieces.size();i++)
    {
        if(player[owner]->pieces[i]->typeId==a->typeId&&player[owner]->pieces[i]->pos.xPos==a->pos.xPos&&player[owner]->pieces[i]->pos.yPos==a->pos.yPos)
        {
            player[owner]->pieces[i]->pos.xPos==b->pos.xPos;
            player[owner]->pieces[i]->pos.yPos==b->pos.yPos;

    }
        return ;
}

}

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
    ///recieveData();
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
