#ifndef DENTIS_H
#define DENTIS_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

class Dentis
{
public:
    Dentis();

    void setInDocumentRooms(QString patientId);
    QString getTime();
};

#endif // DENTIS_H
