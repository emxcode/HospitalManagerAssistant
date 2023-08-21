#ifndef SURGERY_H
#define SURGERY_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

class Surgery
{
public:
    Surgery();

    void setInDocumentRooms(QString patientId);
    QString getTime();
};

#endif // SURGERY_H
