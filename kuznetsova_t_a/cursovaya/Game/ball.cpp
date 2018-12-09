#include "ball.h"


Ball::Ball(int colour_type)
{
    this->colour_type = colour_type;
    switch (colour_type)
    {
        case 1: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse.png";
                break;
        case 2: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-1.png";
                break;
        case 3: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-2.png";
                break;
        case 4: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-3.png";
                break;
        case 5: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-4.png";
                break;
        case 6: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-5.png";
                break;
        case 7: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-6.png";
                break;
        case 8: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-7.png";
                break;
        case 9: this->path = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-8.png";
                break;

    }
}

Ball::Ball()
{
    path.clear();
    colour_type = 0;
}

void Ball::operator =(Ball ball_2)
{
    path = ball_2.path;
    colour_type = ball_2.colour_type;
}


int Ball::getColour()
{
    return colour_type;
}

QString Ball::getPath()
{
    return path;
}

Ball Ball::Empty()
{
    return Ball();
}

bool Ball::isEmpty()
{
   return (colour_type == 0);
}
