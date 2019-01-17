#ifndef INMEMORYREPOSITORY_H
#define INMEMORYREPOSITORY_H

#include "canvas.h"
#include <QList>



class InMemoryRepository
{
public:
    InMemoryRepository();
    static void save(Canvas canvas);
    static void save(QList<int> leaders);
    static Canvas load();
    static QList<int> loadLeaders();
};

#endif // INMEMORYREPOSITORY_H
