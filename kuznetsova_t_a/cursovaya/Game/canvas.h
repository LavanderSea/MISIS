#ifndef CANVAS_H
#define CANVAS_H

#include "box.h"
#include "Random.h"

#include <QWidget>
#include <QList>
#include <coordinate.h>
#include <array>
#include <QDebug>
#include <QQueue>


class Canvas: public QWidget
{
    Q_OBJECT
private:
    std::array<int, 81> boxes;
    int score;
    Box * clicked_box;
    int count_of_empty_balls;
public:
    Canvas();
    Canvas(const Canvas &canvas);
    Canvas(std::array<int,  81> &boxes, int score);
    ~Canvas() = default;

    void operator = (Canvas canvas_2);
    int Score();
    bool moveBall(Coordinate before_c, Coordinate after_c, int colour); //проверяет можно ли подвинуть шарик(есть ли путь), если да, то двигает
    void AddPoints(int count);

    void DeleteBall(int x, int y);
    void DeleteBall(Coordinate c);
    void DeleteBall(int index);

    void DeleteBalls(QList<int> boxes);

    int *getBall(int x, int y);
    int *getBall(Coordinate c);
    int *getBall(int index);

    void countOfEmptyBalls();

    bool isBoxEmpty(int index);

    int Index(int row, int column);
    int Index(Coordinate coordinate);
    Coordinate ParseIndex(int index);

    QList<int> Bfs(Coordinate start, Coordinate finish);

    bool GenerateRandomBalls();    

    bool SearchBallsWithTheSameColour(Coordinate balls_coordinate, int colour_type);

    QList<int> SearchVertical(Coordinate balls_coordinate,int colour_type);
    QList<int> SearchGorizontal(Coordinate balls_coordinate,int colour_type);
    QList<int> SearchByMainDiagonal(Coordinate balls_coordinate,int colour_type);
    QList<int> SearchBySideDiagonal(Coordinate balls_coordinate,int colour_type);

    Box *getClicked_box() const;
    void setClicked_box(Box *value);
    void setEmptyClicked_box();
    int getScore() const;
    void setScore(int value);

    void clear();
    int getCount_of_empty_balls() const;
};

#endif // CANVAS_H
