#include "canvas.h"

#include <QRandomGenerator>

Canvas::Canvas()
{
    this->score = 0;
    std::array<Ball, 81> balls;
    this->balls = balls;
}

Canvas::Canvas(const Canvas &canvas)
{
    this->score = canvas.score;
    this->balls = canvas.balls;
}

Canvas::Canvas(std::array<Ball, 81>& balls, long int score)
{
    this->score = score;
    this->balls = balls;
}


void Canvas::AddPoints(int count)
{
    score += 600 + (count - 5) * 100;
}

void Canvas::DeleteBall(int x, int y)
{
    balls[unsigned(Index(x, y))] = Ball::Empty();
}

void Canvas::DeleteBall(Coordinate c)
{
    balls[unsigned(Index(c.x, c.y))] = Ball::Empty();
}

void Canvas::DeleteBalls(std::list<Coordinate> balls)
{
    while (!balls.empty())
    {
        DeleteBall(balls.back());
        balls.pop_back();
    }
}

Ball * Canvas::getBall(int x, int y)
{
    return &balls[unsigned(Index(x, y))];
}
Ball * Canvas::getBall(Coordinate c)
{
    return &balls[unsigned(Index(c.x, c.y))];
}

int Canvas::Index(int row, int column)
{
    return column + (row * 9);
}

Coordinate Canvas::ParseIndex(int index)
{
    int row = index % 9;
    int column = index / 9;
    return Coordinate(row, column);
}

std::list<int> Canvas::Bfs(Coordinate start, Coordinate finish)
{
    int s = Index(start.x, start.y);
    int f = Index(finish.x, finish.y);

    std::queue<int> queue;
    queue.push(s);
    int prev[81];
    bool used[81];
    bool status(false);

    for (int i = 0; i<81; i++)
    {
        prev[i] = -1;
        used[i] = false;
    }

    while (!queue.empty())
    {
        int ball = queue.front();
        queue.pop();
        if (!used[ball])
        {
            if(ball == f)
            {
                status =true;
                break;
            }
            else
            {
                used[ball] = true;
                if (ball+1<81)
                {
                    if(!used[ball+1]&& (getBall(ParseIndex(ball+1))->isEmpty())) queue.push(ball+1);
                    if (prev[ball+1] == -1) prev[ball+1] = ball;
                }
                if (ball-1>0)
                {
                    if(!used[ball-1]&& (getBall(ParseIndex(ball-1))->isEmpty())) queue.push(ball-1);
                    if (prev[ball-1] == -1) prev[ball+1] = ball;
                }
                if (ball+9<81)
                {
                    if(!used[ball+9]&& (getBall(ParseIndex(ball+9))->isEmpty())) queue.push(ball+9);
                    if (prev[ball+9] == -1) prev[ball+1] = ball;
                }
                if (ball-9>0)
                {
                    if(!used[ball-9]&& (getBall(ParseIndex(ball-9))->isEmpty())) queue.push(ball-9);
                    if (prev[ball-9] == -1) prev[ball+1] = ball;
                }


            }
        }


    }

    std::list<int> result_path;
    if (status)
    {
        int i = f;
        while(prev[1]!=s)
        {
            result_path.push_front(i);
            i = prev[i];
        }
    }
    return result_path;

}

bool Canvas::GenerateRandomBalls()
{
    QRandomGenerator rGenerator;
    std::vector<Ball> emptyBalls;
    bool result(false);
    for (int i = 0; i< 81; i++)
    {
        if (balls[unsigned(i)].getColour()!=0)
        {
            emptyBalls.push_back(balls[unsigned(i)]);
        }
    }
    int n = 3;
    int count_emptyBalls = signed(emptyBalls.size());
    bool fewEmptyBalls = (signed(emptyBalls.size())<n);
    if (count_emptyBalls < n)
    {
        n = count_emptyBalls;
    }
    int random_number = rGenerator.generate() % 81;
    for (int i = 0; i< n; i++)
    {
        while (balls[unsigned(random_number)].getColour()!=0)
        {
            random_number = rGenerator.generate() % 81;
        }
        int random_colour = rGenerator.generate() % 9;
        balls[unsigned(random_number)] = Ball(random_colour);
        result = SearchBallsWithTheSameColour(ParseIndex(random_number), random_colour)|| result;
    }

    result = result || fewEmptyBalls;
    return result;

}

Canvas::~Canvas()
{

}

void Canvas::operator =(Canvas canvas_2)
{
    this->balls = canvas_2.balls;
    this->score = canvas_2.score;
}

void Canvas::moveBall(Coordinate before_c, Coordinate after_c, int colour) //гарантируется, что выбран шарик, и что клетка куда переставляется пустая
{
    std::list<int> path = Bfs(before_c, after_c);
    if (!path.empty())
    {
        //перемещаем шарик(анимация)
        Ball tempBall = balls[unsigned(Index(before_c.x, before_c.y))];
        balls[unsigned(Index(after_c.x,after_c.y))] = tempBall;
        DeleteBall(before_c);
        if (!SearchBallsWithTheSameColour(after_c, colour))
        {
            //завершаем ход
        }
    }

}
std::list<Coordinate> Canvas::SearchVertical(Coordinate     balls_coordinate, int colour)
{
    std::list<Coordinate> balls;
    int anotherColour;
    Ball * tempBall = new Ball();
    for (int i = balls_coordinate.y; i<9; i++)
    {
        tempBall = getBall(balls_coordinate.x, i);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(Coordinate(balls_coordinate.x, i));
       }
    }

    for (int i = balls_coordinate.y; i>0; i--)
    {
        tempBall = getBall(balls_coordinate.x, i);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(Coordinate(balls_coordinate.x, i));
       }
    }
    return balls;
}
std::list<Coordinate> Canvas::SearchGorizontal(Coordinate balls_coordinate, int colour)
{
    std::list<Coordinate> balls;
    int anotherColour;
    Ball * tempBall = new Ball();
    for (int i = balls_coordinate.x; i<9; i++)
    {
        tempBall = getBall(i,balls_coordinate.y);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(Coordinate(i,balls_coordinate.y));
       }
    }

    for (int i = balls_coordinate.x; i>0; i--)
    {
        tempBall = getBall(i, balls_coordinate.y);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(Coordinate(i,balls_coordinate.y));
       }
    }
    return balls;
}
std::list<Coordinate> Canvas::SearchByMainDiagonal(Coordinate balls_coordinate, int colour)
{
    std::list<Coordinate> balls;
    int anotherColour;
    Ball * tempBall = new Ball();
    Coordinate maxCoordinate(9,9);
    Coordinate minCoordinate(0,0);
    for (Coordinate c = balls_coordinate; c<maxCoordinate; c++)
    {
        tempBall = getBall(c);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(c);
       }
    }

    for (Coordinate c = balls_coordinate; c>minCoordinate; c--)
    {
        tempBall = getBall(c);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(c);
       }
    }
    return balls;
}
std::list<Coordinate> Canvas::SearchBySideDiagonal(Coordinate balls_coordinate, int colour)
{
    std::list<Coordinate> balls;
    int anotherColour;
    Ball * tempBall = new Ball();
    Coordinate maxCoordinate(9,9);
    Coordinate minCoordinate(0,0);
    for (Coordinate c = balls_coordinate; c<maxCoordinate; ++c)
    {
        tempBall = getBall(c);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(c);
       }
    }

    for (Coordinate c = balls_coordinate; c>minCoordinate; --c)
    {
        tempBall = getBall(c);
        anotherColour = tempBall->getColour();
       if (anotherColour == colour)
       {
          balls.push_back(c);
       }
    }
    return balls;
}


bool Canvas::SearchBallsWithTheSameColour(Coordinate balls_coordinate, int colour)
{
    std::list<Coordinate> verticalBalls = SearchVertical(balls_coordinate,colour);
    std::list<Coordinate> gorizontalBalls = SearchGorizontal(balls_coordinate,colour);
    std::list<Coordinate> mainDiagonalBalls = SearchByMainDiagonal(balls_coordinate,colour);
    std::list<Coordinate> sideDiagonalBalls = SearchBySideDiagonal(balls_coordinate,colour);
    int deletedBallsCount(0);
    if(verticalBalls.size()>=4)
    {
        DeleteBalls(verticalBalls);
        deletedBallsCount += verticalBalls.size();
    }
    if(gorizontalBalls.size()>=4)
    {
        DeleteBalls(gorizontalBalls);
        deletedBallsCount += gorizontalBalls.size();
    }
    if(mainDiagonalBalls.size()>=4)
    {
        DeleteBalls(mainDiagonalBalls);
        deletedBallsCount += mainDiagonalBalls.size();
    }
    if(sideDiagonalBalls.size()>=4)
    {
        DeleteBalls(sideDiagonalBalls);
        deletedBallsCount += sideDiagonalBalls.size();
    }

    if (deletedBallsCount!=0)
    {
        DeleteBall(balls_coordinate);
        deletedBallsCount++;
        AddPoints(deletedBallsCount);
        return true;
    }
    return false;

}

