#include "box.h"

int Box::getColour() const
{
    return colour;
}

void Box::setColour(int value)
{
    colour = value;
    QPixmap tempPixmap;
    QString path;
    switch (colour)
        {
            case 1: path = "../Images/Ellipse.png";
                    break;
            case 2: path = "../Images/Ellipse-1.png";
                    break;
            case 3: path = "../Images/Ellipse-2.png";
                    break;
            case 4: path = "../Images/Ellipse-3.png";
                    break;
            case 5: path = "../Images/Ellipse-4.png";
                    break;
            case 6: path = "../Images/Ellipse-5.png";
                    break;
            case 7: path = "../Images/Ellipse-6.png";
                    break;
            case 8: path = "../Images/Ellipse-7.png";
                    break;
            case 9: path = "../Images/Ellipse-8.png";
                    break;
            default:
                    path = "../Images/Rectangle.png";
                    break;
        }
    tempPixmap.load(path);
    this->setPixmap(tempPixmap);

}

bool Box::getHasBall() const
{
    return hasBall;
}

void Box::setHasBall(bool value)
{
    hasBall = value;
}

bool Box::getClicked()
{
    return isClicked;
}

int Box::getNumber()
{
    return Number;
}

void Box::setNumber(int value)
{
    Number = value;
}


void Box::setClicked(bool value)
{
    isClicked = value;
}


