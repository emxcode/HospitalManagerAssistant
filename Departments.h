#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>

#include "Radiology.h"
#include "Pharmacy.h"
#include "Surgery.h"
#include "Rooms.h"
#include "Dentis.h"

class Departments
{
public:
    Departments();

    Radiology m_radiology;
    Pharmacy m_pharmecy;
    Surgery m_surgery;
    Rooms m_rooms;
    Dentis m_dentis;


    void surviceRequested(QString data, QString id);
    void setInDocument(QString patientId);
    int getRoomStatus();
};

#endif // DEPARTMENTS_H
