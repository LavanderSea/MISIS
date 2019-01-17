#ifndef TEST_CANVAS_H
#define TEST_CANVAS_H

#include <QObject>
#include "canvas.h"



class test_canvas: public QObject
{
    Q_OBJECT
public:
    test_canvas();
private slots:
    void testParsingIndex();
    void testGetingIndex();
    void testCorrelationPatsingIndexAndIndex();
    void testSearchingVertical();
    void testSearchingGorizontal();
    void testSearchingBySideDiagonal();
    void testSearchingByMainDiagonal();
    void testGenerateRandomBalls();
    void testBFS();
};

#endif // TEST_CANVAS_H
