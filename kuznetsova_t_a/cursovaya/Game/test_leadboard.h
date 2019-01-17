#ifndef TEST_LEADBOARD_H
#define TEST_LEADBOARD_H

#include <QObject>

class test_leadboard: public QObject
{
    Q_OBJECT
public:
    test_leadboard();
private slots:
    void testUpdatingLeaders();
    void testLoading();
    void testRepository();

};

#endif // TEST_LEADBOARD_H
