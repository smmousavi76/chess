#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Cell.h"
#include <SFML/Graphics.hpp>

class Board:public sf::Drawable
{
private:
    int Height,Width;
    Cell ***cells;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Board(int h,int w);
    ~Board();

};

#endif // CLIENT_H_INCLUDED
