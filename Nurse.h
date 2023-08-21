#ifndef NURSE_H
#define NURSE_H
#include<QString>
#include<QDir>
#include<QTextStream>

class Nurse
{
public:
    Nurse();

public:
    void CreatNewNurseToList(QString name,QString id, QString timeShift);
    bool isNurseCreated(QString personalId);
    QString readNurseDataFromFile(QString patientID);
private:
    void addNewNurseTolist(QString name,QString id, QString timeShift);

};

#endif // NURSE_H
