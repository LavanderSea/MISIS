#ifndef WINDOW_H
#define WINDOW_H

#include "box.h"
#include "canvas.h"
#include "coordinate.h"
#include "leadboard.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QUrl>
#include <QVector>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();


    //int Index(int row, int column);
    Coordinate ParseIndex(int index);

private slots:
    void on_startGameButton_clicked();
    void on_saveGameButton_clicked();

    void on_loadGameButton_clicked();

    void on_leadBoardButton_clicked();

private:
    QVector<Box*> labels;
    void initializeGridLayout();
    void startGame();
    void finishGame();
    void showBoxes();
    void nextStep();
    void createCanvas();
    void initializeStartButton();
    void initializeScoreLabel();
    void showScore();
    void loadLeadBoard();
    void loadSaveGame(QString);
    void setWindowGeometry();

    bool eventFilter(QObject *object, QEvent *event);
    Ui::Window *ui;
    LeadBoard *leadBoard;
    Canvas *canvas;
protected:
     void closeEvent(QCloseEvent *event);
};

#endif // WINDOW_H
