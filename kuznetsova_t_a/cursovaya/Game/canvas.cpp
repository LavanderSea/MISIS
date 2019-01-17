#include "canvas.h"

Box *Canvas::getClicked_box() const
{
    return clicked_box;
}

void Canvas::setClicked_box(Box *value)
{
    clicked_box = value;
}

void Canvas::setEmptyClicked_box()
{
    Box* emptyBox = new Box();
    emptyBox->setNumber(-1);
    emptyBox->setClicked(false);
    clicked_box = emptyBox;
}

int Canvas::getScore() const
{
    return score;
}

void Canvas::setScore(int value)
{
    score = value;
}

void Canvas::clear()
{
    setEmptyClicked_box();
    this->score = 0;
    std::array<int, 81> balls;
    for (int i =0; i<81; i++)
    {
        balls[unsigned(i)] = -1;
    }
    this->boxes = balls;
    count_of_empty_balls = 0;

}

int Canvas::getCount_of_empty_balls() const
{
    return count_of_empty_balls;

}

Canvas::Canvas()
{
    this->score = 0;
    std::array<int, 81> balls;
    for (int i =0; i<81; i++)
    {
        balls[unsigned(i)] = -1;
    }
    this->boxes = balls;
}

Canvas::Canvas(const Canvas &canvas)
{
    this->score = canvas.score;
    this->boxes = canvas.boxes;
}

Canvas::Canvas(std::array<int, 81>& balls, int score)
{
    this->score = score;
    this->boxes = balls;
}


void Canvas::AddPoints(int count)
{
    score += 600 + (count - 5) * 100;
}

void Canvas::DeleteBall(int x, int y)
{
    boxes[unsigned(Index(x, y))] = -1;
}

void Canvas::DeleteBall(Coordinate c)
{
    boxes[unsigned(Index(c))] = -1;
}

void Canvas::DeleteBall(int index)
{
    boxes[unsigned(index)] = -1;
}

void Canvas::DeleteBalls(QList<int> balls)
{
    while (!balls.empty())
    {
        DeleteBall(balls.back());
        balls.pop_back();        
    }
}

int * Canvas::getBall(int x, int y)
{
    if (x>8 || y>8 ||x<0||y<0)
        return new int(-2);
    return &boxes[unsigned(Index(x, y))];
}
int * Canvas::getBall(Coordinate c)
{
    if (c.x>8 || c.y>8 ||c.x<0||c.y<0)
       return new int(-2);
    return &boxes[unsigned(Index(c))];
}

int *Canvas::getBall(int index)
{
    if (index < 0 || index >80)
        return new int(-2);
    return &boxes[unsigned(index)];
}

void Canvas::countOfEmptyBalls()
{
    QList<int> emptyBalls;
    for (int i = 0; i< 81; i++)
    {
        if (isBoxEmpty(i))
        {
            emptyBalls.push_back(i);
        }
    }
    count_of_empty_balls = emptyBalls.size();
}

bool Canvas::isBoxEmpty(int index)
{
    return (boxes[unsigned(index)] == -1);
}


int Canvas::Index(int row, int column)
{
    return row + (column * 9);
}

int Canvas::Index(Coordinate coordinate)
{
    int row = coordinate.x;
    int column = coordinate.y;
    return row + (column * 9);
}

Coordinate Canvas::ParseIndex(int index)
{
    int row = index % 9;
    int column = index / 9;
    return Coordinate(row, column);
}

QList<int> Canvas::Bfs(Coordinate start, Coordinate finish)
{
    int s = Index(start);
    int f = Index(finish);

    QQueue<int> queue;
    queue.push_back(s);
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
        int box = queue.front();
        queue.pop_front();
        if (!used[box])
        {
            if(box == f)
            {
                status =true;
                break;
            }
            else
            {
                used[box] = true;
                Coordinate tempC = ParseIndex(box);

                if (tempC.y +1 <9)
                {
                    if(!used[Index(tempC.plusY(1))] && isBoxEmpty(Index(tempC.plusY(1)))) queue.push_back(Index(tempC.plusY(1)));
                    if (prev[Index(tempC.plusY(1))] == -1) prev[Index(tempC.x, tempC.y +1)] = box;
                }
                if (tempC.y -1>=0)
                {
                    if(!used[Index(tempC.plusY(-1))]&& isBoxEmpty(Index(tempC.plusY(-1)))) queue.push_back(Index(tempC.plusY(-1)));
                    if (prev[Index(tempC.plusY(-1))] == -1) prev[Index(tempC.plusY(-1))] = box;
                }
                if (tempC.x +1<9)
                {
                    if(!used[Index(tempC.plusX(1))]&& isBoxEmpty(Index(tempC.plusX(1)))) queue.push_back(Index(tempC.plusX(1)));
                    if (prev[Index(tempC.plusX(1))] == -1) prev[Index(tempC.plusX(1))] = box;
                }
                if (tempC.x -1>=0)
                {
                    if(!used[Index(tempC.plusX(-1) )]&& isBoxEmpty(Index(tempC.plusX(-1)))) queue.push_back(Index(tempC.plusX(-1)));
                    if (prev[Index(tempC.plusX(-1))] == -1) prev[Index(tempC.plusX(-1))] = box;
                }
            }
        }
    }
    QList<int> result_path;
    if (status)
    {
        int i = f;
        while(s!=prev[i])
        {
            result_path.push_front(i);
            i = prev[i];
        }
        result_path.push_front(i);
        result_path.push_front(s);

    }
    return result_path;

}

bool Canvas::GenerateRandomBalls()
{
    QList<int> emptyBalls;
    bool result(false);
    for (int i = 0; i< 81; i++)
    {
        if (isBoxEmpty(i))
        {
            emptyBalls.push_back(i);
        }
    }
    int n = 3;
    int count_emptyBalls = emptyBalls.size();
        count_of_empty_balls = count_emptyBalls;
    if (count_emptyBalls < n)
    {
        n = count_emptyBalls;
    }
    int random_number = Random::get(0,count_emptyBalls-1);
    int random_colour;
    for (int i = 0; i< n; i++)
    {        
        random_colour = Random::get(1,9);
        random_number = Random::get(0,count_emptyBalls-1);
        boxes[unsigned(emptyBalls[random_number])] = random_colour;
        result = SearchBallsWithTheSameColour(ParseIndex(emptyBalls[random_number]), random_colour);
        emptyBalls.removeAt(random_number);
        count_emptyBalls = emptyBalls.size();
        count_of_empty_balls = count_emptyBalls;
    }
    return result;

}

void Canvas::operator =(Canvas canvas_2)
{
    this->boxes = canvas_2.boxes;
    this->score = canvas_2.score;
}

bool Canvas::moveBall(Coordinate before_c, Coordinate after_c, int colour) //гарантируется, что выбран шарик, и что клетка куда переставляется пустая
{
    QList<int> path = Bfs(before_c, after_c);
    if (path.size()!=0)
    {
        boxes[unsigned(Index(after_c))] = colour;
        DeleteBall(before_c);
        if (!SearchBallsWithTheSameColour(after_c, colour))
        {
            return false; //завершение хода, если не нашлись шарики которые можно удалить
        }
        //возвращаем !Search
    }
    return true;//продолжение хода, если были удаленные шарики или не было перемещения

}
QList<int> Canvas::SearchVertical(Coordinate balls_coordinate, int colour)
{
    QList<int> boxes;
    int i = balls_coordinate.y +1;
    while (*getBall(balls_coordinate.x, i) == colour && (i<=8)) {
        boxes.push_back(Index(balls_coordinate.x, i));
        i++;
    }
    i = balls_coordinate.y -1;
    while (*getBall(balls_coordinate.x, i) == colour && (i>=0)) {
        boxes.push_front(Index(balls_coordinate.x, i));
        i--;
    }
    return boxes;
}
QList<int> Canvas::SearchGorizontal(Coordinate balls_coordinate, int colour)
{
    QList<int> boxes;
    int i = balls_coordinate.x +1;
    while (*getBall(i,balls_coordinate.y) == colour && (i<=8)) {
        boxes.push_back(Index(i,balls_coordinate.y));
        i++;
    }
    i = balls_coordinate.x -1;
    while (*getBall(i,balls_coordinate.y) == colour && (i>=0)) {
        boxes.push_front(Index(i,balls_coordinate.y));
        i--;
    }
    return boxes;

}
QList<int> Canvas::SearchByMainDiagonal(Coordinate balls_coordinate, int colour)
{
    QList<int> boxes;
    Coordinate i = balls_coordinate;
    i++;
    while (*getBall(i) == colour && (i.x<9) && (i.y<9)) {
        boxes.push_back(Index(i));
        i++;
    }
    i = balls_coordinate;
    i--;
    while (*getBall(i) == colour && (i.x>=0) && (i.y>=0)) {
        boxes.push_front(Index(i));
        i--;
    }
    return boxes;
}
QList<int> Canvas::SearchBySideDiagonal(Coordinate balls_coordinate, int colour)
{
    QList<int> boxes;
    Coordinate i = balls_coordinate;
    ++i;
    while (*getBall(i) == colour && (i.x>=0) && (i.y<9)) {
        boxes.push_back(Index(i));
        ++i;
    }
    i = balls_coordinate;
    --i;
    while (*getBall(i) == colour && (i.x<9) && (i.y>=0)) {
        boxes.push_front(Index(i));
        --i;
    }
    return boxes;
}

bool Canvas::SearchBallsWithTheSameColour(Coordinate balls_coordinate, int colour)
{
    QList<int> verticalBalls = SearchVertical(balls_coordinate,colour);
    QList<int> gorizontalBalls = SearchGorizontal(balls_coordinate,colour);
    QList<int> mainDiagonalBalls = SearchByMainDiagonal(balls_coordinate,colour);
    QList<int> sideDiagonalBalls = SearchBySideDiagonal(balls_coordinate,colour);
    int deletedBallsCount = 0;

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
        count_of_empty_balls +=deletedBallsCount;
        AddPoints(deletedBallsCount);
        return true;
    }
    return false;

}

