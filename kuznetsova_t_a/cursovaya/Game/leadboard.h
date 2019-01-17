#ifndef LEADBOARD_H
#define LEADBOARD_H

#include <QDialog>
#include <array>
#include <QLabel>

namespace Ui {
class LeadBoard;
}

class LeadBoard : public QDialog
{
    Q_OBJECT

public:
    explicit LeadBoard(QWidget *parent = nullptr);
    ~LeadBoard();

    void setLeaders(QList<int> leaders);
    QList<int> getLeaders();

    void updateLeaders(int score);
    void initializeLabels();

private slots:
    void on_closeLeadBoardButton_clicked();

private:
    QList<int> sort(QList<int>numbers);
    bool isSort(QList<int>);
    int countOfLeaders = 10;
    Ui::LeadBoard *ui;
    QList<QLabel*> labels;
    std::array<int, 10> leaders ;
    void UpdateView(int);
    void Insert(int, int);

};

#endif // LEADBOARD_H
