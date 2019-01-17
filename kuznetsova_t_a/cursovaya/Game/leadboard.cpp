#include "leadboard.h"
#include "ui_leadboard.h"
#include <QDebug>

LeadBoard::LeadBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeadBoard)
{
    ui->setupUi(this);
    this->setWindowTitle("Leader board");
    initializeLabels();
    UpdateView(0);
}

LeadBoard::~LeadBoard()
{
    delete ui;
}

void LeadBoard::UpdateLeaders(int score)
{
    int left = 0;
    int right = countOfLeaders-1;
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2; // 9-0 /2 = 4
        if (leaders.front()<=score)
        {
            Insert(score, 0);
            UpdateView(0);
            break;
        }
        if (leaders.back()>=score)
            break;
        if (leaders[mid]>=score && leaders[mid+1]<=score)// l[4] =2 5>2 3>5 false
        {
            Insert(score, mid+1);
            UpdateView(mid+1);
            break;
        }
        if (leaders[mid]<score)
            right = mid;
        else
            left = mid + 1;
    }

}

void LeadBoard::initializeLabels()
{
    for (int i=0; i<countOfLeaders;i++)
    {
        labels << new QLabel();
        ui->leadersList->addWidget(labels.at(i));
    }
}

void LeadBoard::Load(QList<int> leaders)
{
    if (!isSort(leaders))
    {
        leaders = sort(leaders);
    }
    if (leaders.size() < countOfLeaders)
    {
        for (int i = 0; i<countOfLeaders-leaders.size();i++)
        {
            leaders.push_back(0);
        }
    }
    for (int i=0; i<countOfLeaders; i++)
    {
        this->leaders[i] = leaders.at(i);
    }
    UpdateView(0);
}

QList<int> LeadBoard::getLeaders()
{
    QList<int> list;
    for (int i=0; i<countOfLeaders; i++)
    {
        list<<leaders[i];
    }
    return list;
}

void LeadBoard::on_closeLeadBoardButton_clicked()
{
    this->close();
}

void LeadBoard::UpdateView(int index)
{
    for (int i=index; i<countOfLeaders;i++)
    {
        labels.at(i)->setText(QString::number(leaders[unsigned(i)]));
    }
}

void LeadBoard::Insert(int score,int index)
{
    for (int i=countOfLeaders-2; i>index; i--)
    {
        leaders[i+1] = leaders[i];
    }
    leaders[index] = score;

}

bool LeadBoard::isSort(QList<int> list)
{
    bool flag = true;
    for(int i=1; i<countOfLeaders; i++)
    {
        flag = flag && (list[i-1]>= list[i]);
    }
    return flag;

}

QList<int> LeadBoard::sort(QList<int>numbers)
{
    int tmp;
    for (int i = 1, j; i < numbers.size(); ++i) // цикл проходов, i - номер прохода
    {
        tmp = numbers[i];
        for (j = i - 1; j >= 0 && numbers[j] < tmp; --j) // поиск места элемента в готовой последовательности
            numbers[j + 1] = numbers[j];    // сдвигаем элемент направо, пока не дошли
        numbers[j + 1] = tmp; // место найдено, вставить элемент
    }
    return numbers;

}
