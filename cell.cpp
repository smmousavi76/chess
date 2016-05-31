#include "Cell.h"
 Cell::Cell(bool c,int size) : rectangle(sf::Vector2f(size,size))
    {
        color = c;
        if(c)
        {
            rectangle.setFillColor(sf::Color::Black);
        }
        else
        {
            rectangle.setFillColor(sf::Color::White);
        }
    }
    bool Cell::getColor()
    {
        return color;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *=getTransform();
        target.draw(rectangle, states);
    }
