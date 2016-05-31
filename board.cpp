 #include "Board.h"
 Board::Board(int h, int w)
    {
        Height = h;
        Width = w;
        cells = new Cell**[Height];
        for(int i=0;i<Height;i++)
            cells[i]= new Cell*[Width];
        for(h=0;h<Height;h++)
            for(w=0;w<Width;w++)
            {
                cells[h][w]= new Cell((h*(Width+1)+w)%2,100);
                cells[h][w]->setPosition(w*100, h*100);
            }
    }

     void Board::draw(sf::RenderTarget& target, sf::RenderStates states)
    {
        for(int h=0;h<Height;h++)
            for(int w=0;w<Width;w++)
            {
                target.draw(*cells[h][w]);
            }
    }
