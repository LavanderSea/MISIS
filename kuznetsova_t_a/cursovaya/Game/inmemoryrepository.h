#ifndef INMEMORYREPOSITORY_H
#define INMEMORYREPOSITORY_H

#include "canvas.h"
#include <QList>



class InMemoryRepository
{
public:
    InMemoryRepository() = default;
    static void save(Canvas canvas, QString path);
    static void save(QList<int> leaders);
    static Canvas load(QString path);
    static void save(Coordinate c);
    static Coordinate loadCoordinate();
    static QList<int> loadLeaders();
private:
    static  QVariantMap loadFile(QString path);
};

#endif // INMEMORYREPOSITORY_H
