#include "ball.h"
#include "canvas.h"
#include "test.h"



Test::Test()
{

}

bool Test::TestBallCorrectPathReturn()
{
    QString str = "C:\\Projects\\Qt\\Lines96\\Game\\Ellipse-1.png";
    Ball testBall(2);
    return(testBall.getPath() == str); // QString корректно сравнивает сровки через ==
}

bool Test::TestDeleteBallsMethod()
{
    std::array<Ball, 81> test_balls;
    test_balls[0] = Ball(1);
    test_balls[1] = Ball(2);
    test_balls[2] = Ball(1);

    std::list<Coordinate> deletable_balls_coordinates;
    deletable_balls_coordinates.push_back(Coordinate(0,0));
    deletable_balls_coordinates.push_back(Coordinate(1,0));
    deletable_balls_coordinates.push_back(Coordinate(2,0));

    Canvas test_canvas(test_balls, 0);

    test_canvas.DeleteBalls(deletable_balls_coordinates);

    bool result = (test_canvas.getBall(0,0)->getColour() == 0)&&(test_canvas.getBall(1,0)->getColour() == 0)&&(test_canvas.getBall(1,0)->getColour() == 0);
    return result;


}

QString Test::TestLoadindImage()
{
    Ball test_Ball(2);
    return test_Ball.getPath();

}
