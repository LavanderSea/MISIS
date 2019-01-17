#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
    int x;
    int y;
    Coordinate();
    Coordinate(int X,int Y);
    Coordinate(const Coordinate &coordinate);
    void setCoordinate(int X, int Y);

    ~Coordinate();
    void operator =(Coordinate &c);


    bool operator > (Coordinate &c);

    bool operator == (const Coordinate &c);

    void operator ++(int);
    void operator --(int);

    void operator ++();
    void operator --();

    Coordinate plusX(int);
    Coordinate plusY(int);

};

bool operator == (const Coordinate &c1,const Coordinate c2);
bool operator < (const Coordinate &c1,const Coordinate c2);

#endif // COORDINATE_H
