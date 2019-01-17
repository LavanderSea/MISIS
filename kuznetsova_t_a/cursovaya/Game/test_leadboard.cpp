#include "leadboard.h"
#include "test_leadboard.h"
#include "inmemoryrepository.h"
#include <QTest>

test_leadboard::test_leadboard()
{

}

void test_leadboard::testUpdatingLeaders()
{
    LeadBoard testleadboard;
    QList<int> list ={8,4,4,3,2,1,0,0,0,0};
    testleadboard.Load(list);
    testleadboard.UpdateLeaders(5);
    QList<int> expected_list ={8,5,4,4,3,2,1,0,0,0};
    QCOMPARE(expected_list, testleadboard.getLeaders());

    QList<int> list_2 ={4,4,4,3,2,1,0,0,0,0};
    testleadboard.Load(list_2);
    testleadboard.UpdateLeaders(5);
    QList<int> expected_list_2 ={5,4,4,4,3,2,1,0,0,0};
    QCOMPARE(expected_list_2, testleadboard.getLeaders());

    QList<int> list_3 ={0,0,0,0,0,0,0,0,0,0};
    testleadboard.Load(list_3);
    testleadboard.UpdateLeaders(5);
    QList<int> expected_list_3 ={5,0,0,0,0,0,0,0,0,0};
    QCOMPARE(expected_list_3, testleadboard.getLeaders());

    QList<int> list_4 ={9,9,9,9,9,9,9,9,9,9};
    testleadboard.Load(list_4);
    testleadboard.UpdateLeaders(5);
    QCOMPARE(list_4, testleadboard.getLeaders());

    QList<int> list_5 ={9,9,9,9,9,9,9,9,9,4};
    testleadboard.Load(list_5);
    testleadboard.UpdateLeaders(5);
    QList<int> expected_list_5 ={9,9,9,9,9,9,9,9,9,5};
    QCOMPARE(expected_list_5, testleadboard.getLeaders());

}

void test_leadboard::testLoading()
{
    LeadBoard testleadboard;
    QList<int> list_1 ={0,0,0,0,0,0,0,0,0,0};
    QList<int> list_2 ={0,0,7,0,0,8,0,99,0,0};
    QList<int> expected_list_2 = {99,8,7,0,0,0,0,0,0,0};
    QList<int> list_3 ={1,2,0,3,0,4,0,4,0,8};
    QList<int> expected_list_3 ={8,4,4,3,2,1,0,0,0,0};
    testleadboard.Load(list_1);
    QCOMPARE(list_1, testleadboard.getLeaders());
    testleadboard.Load(list_2);
    QCOMPARE(expected_list_2, testleadboard.getLeaders());
    testleadboard.Load(list_3);
    QCOMPARE(expected_list_3, testleadboard.getLeaders());
}

void test_leadboard::testRepository()
{
    LeadBoard testleadboard;
    QList<int> expected_list ={4,4,4,3,2,1,0,0,0,0};
    testleadboard.Load(expected_list);
    InMemoryRepository::save(testleadboard.getLeaders());
    QList<int> list = InMemoryRepository::loadLeaders();
    QCOMPARE(expected_list, list);

}


