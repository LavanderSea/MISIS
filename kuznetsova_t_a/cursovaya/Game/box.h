#ifndef BOX_H
#define BOX_H

#include <QLabel>
#include <QMouseEvent>

class Box : public QLabel
{
    Q_OBJECT
public:
    Box(QWidget *parent = nullptr)
        : QLabel(parent)
    {
        Number = -1;
        isClicked = false;
        hasBall = false;
        colour = -1;
    }
    Box(const Box &box);

    void setClicked(bool value);
    int getNumber();
    void setNumber(int value);

    bool getClicked();

    bool getHasBall() const;
    void setHasBall(bool value);

    int getColour() const;
    void setColour(int value);
private:
    int Number;
    bool isClicked;
    bool hasBall;
    int colour;

};

#endif // BOX_H
