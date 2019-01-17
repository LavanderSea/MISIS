#include "ball.h"


Ball::Ball()//:QGraphicsPixmapItem(parent)
{
    path = "";
    colour_type = 0;
}

Ball::Ball(int clour_type)
{
    setImage(clour_type);
}

Ball::Ball(const Ball &ball)
{
    this->path = ball.path;
    this->colour_type = ball.colour_type;
}

Ball Ball::operator =(Ball &ball_2)
{

    this->path = ball_2.path;
    this->colour_type = ball_2.colour_type;

    return *this;
}



void Ball::setPath(QString path)
{
    this->path = path;
}

int Ball::getColour()
{
    return colour_type;
}

QString Ball::getPath()
{
    return path;
}

