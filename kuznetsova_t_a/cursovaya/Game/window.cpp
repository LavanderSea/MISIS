#include "window.h"
#include "ui_window.h"
#include "inmemoryrepository.h"
#include "leadboard.h"


Coordinate Window::ParseIndex(int index)
{
    int row = index % 9;
    int column = index / 9;
    return Coordinate(row, column);
}

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)    
{
    ui->setupUi(this);
    this->setFixedSize(501,561);
    createCanvas();
    loadLeadBoard();

    initializeStartButton();
    initializeScoreLabel();
    initializeGridLayout();

    ui->score->setText("0");
}


Window::~Window()
{
    delete ui;
}


void Window::on_startGameButton_clicked()
{
    startGame();
}

void Window::initializeGridLayout()
{
    ui->gridLayoutWidget->setFixedSize(405,405);
    ui->gridLayoutWidget->move(48,48);

    for(int i = 0; i<81; i++)
    {
        Coordinate c = ParseIndex(i);
        labels << new Box();
        labels.at(i)->setFixedSize(40,40);
        labels.at(i)->setColour(-1);
        labels.at(i)->setNumber(i);
        ui->gridLayout->addWidget(labels.at(i), c.x, c.y);
        labels.at(i)->installEventFilter(this);
    }
}

void Window::startGame()
{
    canvas->clear();
    canvas->GenerateRandomBalls();
    showBoxes();
    ui->score->setText("0");
    ui->startGameButton->setText("Start again");
}

void Window::finishGame()
{
   leadBoard->UpdateLeaders(canvas->getScore());
    InMemoryRepository::save(leadBoard->getLeaders());
    ui->startGameButton->setText("Start new game");
}

void Window::showBoxes()
{
    for (int i=0; i<81; i++)
    {
        if (labels.at(i)->getColour()!=*canvas->getBall(i))
        {           
            labels.at(i)->setHasBall(*canvas->getBall(i)!=-1);
            labels.at(i)->setColour(*canvas->getBall(i));
        }
    }

}

void Window::nextStep()
{
    canvas->GenerateRandomBalls();
}

void Window::createCanvas()
{
    canvas = new Canvas();
    canvas->setEmptyClicked_box();
    canvas->setScore(0);
}

void Window::initializeStartButton()
{
    ui->startGameButton->setFixedSize(101, 40);
    ui->startGameButton->move(200, 470);
}

void Window::initializeScoreLabel()
{
    ui->score->setText("0");
}

void Window::showScore()
{
    ui->score->setText(QString::number(canvas->getScore()));
}

void Window::loadLeadBoard()
{
    leadBoard = new LeadBoard();
    leadBoard->Load(InMemoryRepository::loadLeaders());
}

bool Window::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        if (Box *box = qobject_cast<Box *>(object))
        {
            {
                if (!(canvas->getClicked_box()->getClicked()) && !box->getClicked()) //первый клик
                {
                    if (box->getHasBall()) //клетка содержит шарик
                    {
                        box->setClicked(true);
                        canvas->setClicked_box(box);//выбираем шарик
                    }

                }
                else if (canvas->getClicked_box() == box) //снимаем выбор шарика
                {
                    canvas->setEmptyClicked_box();
                    box->setClicked(false);

                }
                else if (canvas->getClicked_box()->getClicked() && !(box->getClicked()) )//пробуем переместить шарик на выбранную клетку
                {
                    if (!(box->getHasBall())) //если клетка не содержит шарик
                    {
                        int colour = canvas->getClicked_box()->getColour();
                        Coordinate before_coordinate = ParseIndex(canvas->getClicked_box()->getNumber());
                        Coordinate after_coordinate = ParseIndex(box->getNumber());                        
                        if (!(canvas->moveBall(before_coordinate,after_coordinate,colour))) //если ход не завершен
                        {
                            nextStep();
                            if (canvas->getCount_of_empty_balls()<1)
                                finishGame();
                        }
                        canvas->getClicked_box()->setClicked(false);
                        canvas->setEmptyClicked_box();
                        box->setClicked(false);                        
                        showBoxes();
                        showScore();
                    }
                    else
                    {
                        canvas->getClicked_box()->setClicked(false);
                        canvas->setClicked_box(box);
                        box->setClicked(true);
                    }


                }
            }
        }
    }

    return false;
}




void Window::on_saveGameButton_clicked()
{
    InMemoryRepository::save(*canvas);
}

void Window::on_loadGameButton_clicked()
{
    std::array<int, 81> boxes;
    Canvas loaded = InMemoryRepository::load();
    for (int i=0; i<81; i++)
    {
        boxes[i] = *loaded.getBall(i);
    }
    canvas = new Canvas(boxes, loaded.getScore());
    canvas->setEmptyClicked_box();
    canvas->countOfEmptyBalls();
    showBoxes();
    showScore();
}

void Window::on_leadBoardButton_clicked()
{
    leadBoard->show();

}
