#ifndef DOCTORS_H
#define DOCTORS_H
#include<QString>
#include<QDir>
#include<QTextStream>
#include<QFile>

class Doctors
{
public:
    Doctors();

public:
    void addNewDoctorToList(QString name,QString id, QString specialist,QString timeShift);
    bool isDoctorCreated(QString personalId);
    QString readDoctorDataFromFile(QString patientId);
private:
    void addNewDoctorTolist(QString name,QString id, QString specialist, QString timeShift);
};

#endif // DOCTORS_H
