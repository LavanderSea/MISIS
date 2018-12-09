#include <QApplication>
#include "window.h"
#include "canvas.h"
#include "test.h"
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Window w;
  //w.ShowBall(Test::TestLoadindImage(),Coordinate(0,0));
  w.show();

  if (!Test::TestBallCorrectPathReturn()) return -1;
  if (!Test::TestDeleteBallsMethod()) return -1;

  return a.exec();
}
