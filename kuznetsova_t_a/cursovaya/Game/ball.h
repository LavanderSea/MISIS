#ifndef BALL_H
#define BALL_H
#include <QString>
#include <coordinate.h>
#include <string>

class Ball
{
private:
    QString path;
    int colour_type;
public:    
    Ball();
    Ball(int colour_type);
    void operator = (Ball ball_2);
    int getColour();
    QString getPath();
    static Ball Empty();
    bool isEmpty();

};

#endif // BALL_H
