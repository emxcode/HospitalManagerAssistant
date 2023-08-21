#ifndef PHARMACY_H
#define PHARMACY_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
class Pharmacy
{
public:
    Pharmacy();

    void setInDocumentRooms(QString patientId);
    QString getTime();

public:

};

#endif // PHARMACY_H
