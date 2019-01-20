#include "canvas.h"
#include "inmemoryrepository.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QVariantMap>


void InMemoryRepository::save(Canvas canvas, QString path)
{
    QJsonObject canvasJson;
    QJsonArray boxesJson;
    for (int i=0; i<81; i++)
    {
        boxesJson << *canvas.getBall(i);
    }
    canvasJson.insert("score", canvas.getScore());
    canvasJson.insert("boxes", boxesJson);

    QJsonDocument doc_save(canvasJson);
    QFile save_file(path);
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug() << "failed to open save file";
         exit(1);
    }
    QString json_string = doc_save.toJson();
    save_file.write(json_string.toLocal8Bit());
    save_file.close();
}

void InMemoryRepository::save(QList<int> leaders)
{
    QJsonObject leadersJson;
    QJsonArray leadersListJson;
    for (int i=0; i<leaders.size(); i++)
    {
        leadersListJson << leaders.at(i);
    }
    leadersJson.insert("scores", leadersListJson);
    QJsonDocument doc_save(leadersJson);
    QFile save_file("../leaders.txt");
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug() << "failed to open save file";
         exit(1);
    }
    QString json_string = doc_save.toJson();
    save_file.write(json_string.toLocal8Bit());
    save_file.close();

}

Canvas InMemoryRepository::load(QString path)
{
  QVariantMap root_map = loadFile(path);
  int score = root_map["score"].toInt();
  QVariantList inv_list = root_map["boxes"].toList();
  std::array<int, 81> boxes;
  for (int i=0; i<81; i++)
  {
      boxes[unsigned(i)] = inv_list.at(i).toInt();
  }
  Canvas *loadCanvas = new Canvas(boxes, score);

  return *loadCanvas;


}

void InMemoryRepository::save(Coordinate c)
{
    QJsonObject coordinateJson;
    coordinateJson.insert("x", c.x);
    coordinateJson.insert("y", c.y);
    QJsonDocument doc_save(coordinateJson);
    QFile save_file("../coordinate.txt");
    if(!save_file.open(QIODevice::WriteOnly)){
        qDebug() << "failed to open save file";
         exit(1);
    }
    QString json_string = doc_save.toJson();
    save_file.write(json_string.toLocal8Bit());
    save_file.close();

}

Coordinate InMemoryRepository::loadCoordinate()
{
  QVariantMap root_map = loadFile("../coordinate.txt");
  int x = root_map["x"].toInt();
  int y = root_map["y"].toInt();

  return Coordinate(x,y);
}

QList<int> InMemoryRepository::loadLeaders()
{
  QVariantMap root_map = loadFile("../leaders.txt");
  QVariantList inv_list = root_map["scores"].toList();
  QList<int> leaders;
  for (int i=0; i<10; i++)
  {
      leaders << inv_list.at(i).toInt();
  }
  return leaders;
}

QVariantMap InMemoryRepository::loadFile(QString path)
{
    QFile file_obj(path);

    if(!file_obj.open(QIODevice::ReadOnly)){

        qDebug()<<"Failed to open ";
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();
    auto json_doc=QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!json_doc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    QJsonObject json_obj=json_doc.object();

    if(json_obj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        exit(4);
    }

  QVariantMap root_map = json_obj.toVariantMap();
  return root_map;

}
