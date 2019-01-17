#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QString>
#include <coordinate.h>
class Ball
{
private:
    QString path;
    int colour_type;
public:
    Ball();
    Ball(int clour_type);
    Ball(const Ball &ball);
    Ball operator =(Ball &ball_2);



    void setImage(int colour_type);
    void setPath(QString path);


    //void setCurrentBox(box *box);
    //box *getCurrentBox() ;


    bool getIsPlaced() ;
    void setIsPlaced(bool value);
    //QList <box *> moveLocation();
    //virtual void moves() = 0;

    int getColour();
    QString getPath();

};

#endif // BALL_H
