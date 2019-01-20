#include <QApplication>
#include "window.h"
#include "canvas.h"
#include "test_canvas.h"
#include "inmemoryrepository.h"
#include "test_leadboard.h"
#include <QQmlApplicationEngine>
#include <QTest>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
   Window mainWindow;
   mainWindow.setWindowTitle("Lines96");
   QPixmap Pixmap;
   mainWindow.show();
// return QTest::qExec(new test_canvas, argc, argv);
//return QTest::qExec(new test_leadboard, argc, argv);

 return a.exec();
}
