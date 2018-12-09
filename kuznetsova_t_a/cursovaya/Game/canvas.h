#ifndef CANVAS_H
#define CANVAS_H
#include <string>
#include <coordinate.h>
#include <list>
#include <array>
#include <queue>
#include <ball.h>
#include <node.h>

class Canvas
{
private:
    std::array<Ball, 81> balls;
    long int score;
public:
    Canvas();
    Canvas(const Canvas &canvas);
    Canvas(std::array<Ball,  81> &balls, long int score);
    ~Canvas();

    void operator = (Canvas canvas_2);

    void moveBall(Coordinate before_c, Coordinate after_c, int colour); //проверяет можно ли подвинуть шарик(есть ли путь), если да, то двигает
    void AddPoints(int count);

    void DeleteBall(int x, int y);
    void DeleteBall(Coordinate c);    

    void DeleteBalls(std::list<Coordinate> balls);

    Ball *getBall(int x, int y);
    Ball *getBall(Coordinate c);

    int Index(int row, int column);
    Coordinate ParseIndex(int index);

    std::list<int> Bfs(Coordinate start, Coordinate finish);

    bool GenerateRandomBalls();

    bool SearchBallsWithTheSameColour(Coordinate balls_coordinate, int colour_type);

    std::list<Coordinate> SearchVertical(Coordinate balls_coordinate,int colour_type);
    std::list<Coordinate> SearchGorizontal(Coordinate balls_coordinate,int colour_type);
    std::list<Coordinate> SearchByMainDiagonal(Coordinate balls_coordinate,int colour_type);
    std::list<Coordinate> SearchBySideDiagonal(Coordinate balls_coordinate,int colour_type);

};

#endif // CANVAS_H
