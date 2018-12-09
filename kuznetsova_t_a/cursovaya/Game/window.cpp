#include "window.h"
#include "ui_window.h"

#include <QLabel>
#include <QUrl>

void Window::ShowBall(QString path, Coordinate coordinate)
{
    QPixmap Pixmap;
    Pixmap.load(path);
    QLabel *new_label = new QLabel();
    scene->addWidget(new_label);
    new_label->setPixmap(Pixmap);

}

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);

    QLabel *new_label = new QLabel();
    QPixmap Pixmap;
    Pixmap.load("C:\\Projects\\Qt\\Lines96\\Game\\Ellipse.png");

    scene = new QGraphicsScene();   /// Инициализируем графическую сцену
    ui->Scene->setScene(scene);    /// Устанавливаем графическую сцену в graphicsView
    ui->Scene->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    ui->Scene->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    ui->Scene->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали
    //scene->setSceneRect(-250,-250,500,500);
    scene->addWidget(new_label);/// Устанавливаем область графической сцены
    if (Pixmap.isNull())
    {
        scene->setBackgroundBrush(Qt::black);
    }
    else
    {
        scene->setBackgroundBrush(Qt::gray);
    }
   //
   // Pixmap.
    new_label->setPixmap(Pixmap);

    //new_label->resize(50,50);
    //scene->addPixmap(Pixmap);


    ui->Scene->setVisible(false);
}


Window::~Window()
{
    delete ui;
}


void Window::on_startGameButton_clicked()
{
    ui->startGameButton->setVisible(false);
    ui->Scene->setVisible(true);
    //ui->Scene
}

