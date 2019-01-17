#include "coordinate.h"


Coordinate::Coordinate()
{
    x = 0;
    y = 0;
}

Coordinate::Coordinate(int X,int Y)
{
    x = X;
    y = Y;
}

Coordinate::Coordinate(const Coordinate &coordinate)
{
    this->x = coordinate.x;
    this->y = coordinate.y;
}
void Coordinate::setCoordinate(int X, int Y)
{
    x = X;
    y = Y;
}

Coordinate::~Coordinate()
{
    x = 0;
    y = 0;
}

void Coordinate::operator =(Coordinate &c)
{
    x = c.x;
    y = c.y;
}

bool Coordinate::operator > (Coordinate &c)
{
    if (x <= c.x && y <= c.y)
    {
        return false;
    }
    return true;

}

bool Coordinate::operator ==(const Coordinate &c)
{
    return (c.x==x)&&(c.y==y);

}
void Coordinate::operator ++(int)
{
    x--;
    y++;
}
void Coordinate::operator --(int)
{
    x++;
    y--;
}
void Coordinate::operator ++()
{
    x++;
    y++;

}
void Coordinate::operator --()
{
    x--;
    y--;
}

Coordinate Coordinate::plusX(int count)
{
    return Coordinate(x+count, y);
}

Coordinate Coordinate::plusY(int count)
{
    return Coordinate(x, y+count);
}

bool operator ==(const Coordinate &c1, const Coordinate c2)
{
    return (c1.x==c2.x)&&(c2.y==c1.y);
}

bool operator <(const Coordinate &c1, const Coordinate c2)
{
    return (c1.x < c2.x || c1.y < c2.y);

}
