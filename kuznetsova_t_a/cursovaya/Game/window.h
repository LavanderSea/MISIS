#ifndef WINDOW_H
#define WINDOW_H

#include "coordinate.h"

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    void ShowBall(QString path, Coordinate coordinate);
    explicit Window(QWidget *parent = nullptr);
    ~Window();


private slots:
    void on_startGameButton_clicked();

private:
    Ui::Window *ui;
    QGraphicsScene  *scene;
};

#endif // WINDOW_H
