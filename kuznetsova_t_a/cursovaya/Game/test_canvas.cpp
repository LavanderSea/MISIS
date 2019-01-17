#include "test_canvas.h"
#include <QTest>

test_canvas::test_canvas()
{

}

void test_canvas::testParsingIndex()
{
    Canvas test_canvas;
    QCOMPARE(test_canvas.ParseIndex(0), Coordinate(0, 0));
    QCOMPARE(test_canvas.ParseIndex(80), Coordinate(8, 8));
    QCOMPARE(test_canvas.ParseIndex(7), Coordinate(7, 0));

}

void test_canvas::testGetingIndex()
{
    Canvas test_canvas;
    QCOMPARE(test_canvas.Index(Coordinate(0, 0)), 0);
    QCOMPARE(test_canvas.Index(Coordinate(8, 8)), 80);
    QCOMPARE(test_canvas.Index(Coordinate(7, 0)), 7);

}

void test_canvas::testCorrelationPatsingIndexAndIndex()
{
    Canvas test_canvas;
    QCOMPARE(test_canvas.Index(test_canvas.ParseIndex(8)), 8);
    QCOMPARE(test_canvas.Index(test_canvas.ParseIndex(0)), 0);
    QCOMPARE(test_canvas.Index(test_canvas.ParseIndex(80)), 80);


}

void test_canvas::testSearchingVertical()
{
    Canvas test_canvas;
    QList<int> expected_list = {test_canvas.Index(8,0),
                                test_canvas.Index(8,1),
                                test_canvas.Index(8,2),
                                test_canvas.Index(8,3),
                                test_canvas.Index(8,4),
                                test_canvas.Index(8,5),
                                test_canvas.Index(8,6),
                                test_canvas.Index(8,7)};
    QCOMPARE(test_canvas.SearchVertical(Coordinate(8, 8), -1),expected_list);


}

void test_canvas::testSearchingGorizontal()
{
    Canvas test_canvas;
    QList<int> expected_list = {test_canvas.Index(0,8),
                                test_canvas.Index(1,8),
                                test_canvas.Index(2,8),
                                test_canvas.Index(3,8),
                                test_canvas.Index(4,8),
                                test_canvas.Index(5,8),
                                test_canvas.Index(6,8),
                                test_canvas.Index(7,8)};
    QCOMPARE(test_canvas.SearchGorizontal(Coordinate(8, 8), -1),expected_list);

}

void test_canvas::testSearchingBySideDiagonal()
{
    Canvas test_canvas;
    QList<int> expected_list;
    QCOMPARE(test_canvas.SearchBySideDiagonal(Coordinate(0, 8), -1),expected_list);

}
void test_canvas::testSearchingByMainDiagonal()
{
    Canvas test_canvas;
    QList<int> expected_list;
    QCOMPARE(test_canvas.SearchByMainDiagonal(Coordinate(8, 8), -1),expected_list);

}

void test_canvas::testGenerateRandomBalls()
{
    Canvas test_canvas;
    test_canvas.GenerateRandomBalls();
    int count = 0;
    int expected_count = 3;
    for(int i=0; i<81; i++)
    {
        if(!test_canvas.isBoxEmpty(i))
            count++;
    }
    QCOMPARE(count, expected_count);

}

void test_canvas::testBFS()
{
    Canvas test_canvas;
    QList<int> result_list = test_canvas.Bfs(Coordinate(0,0), Coordinate(0,1));
    QList<int> expected_list = {0,9};
    QCOMPARE(result_list, expected_list);
    QList<int> result_list1 = test_canvas.Bfs(Coordinate(0,0), Coordinate(0,2));
    QList<int> expected_list1 = {0,9,18};
    QCOMPARE(result_list1, expected_list1);
    QList<int> result_list2 = test_canvas.Bfs(Coordinate(0,0), Coordinate(0,3));
    QList<int> expected_list2 = {0,9,18, 27};
    QCOMPARE(result_list2, expected_list2);
    QList<int> result_list3 = test_canvas.Bfs(Coordinate(0,0), Coordinate(2,2));
    QList<int> expected_list3 = {0,9,18,19,20};
    QCOMPARE(result_list3, expected_list3);

}
