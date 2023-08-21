#ifndef RADIOLOGY_H
#define RADIOLOGY_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

class Radiology
{
public:
    Radiology();

    void setInDocumentRooms(QString patientId);
    QString getTime();
};

#endif // RADIOLOGY_H
