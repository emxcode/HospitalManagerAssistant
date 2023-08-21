#include "Nurse.h"

Nurse::Nurse()
{

}

void Nurse::CreatNewNurseToList(QString name, QString id, QString timeShift)
{
    addNewNurseTolist(name, id, timeShift);
}

bool Nurse::isNurseCreated(QString personalId)
{


    QString path1 =  "./EmployeeData/NurseData/";
    QDir dir;
    QFile file(path1 + personalId + ".txt");
    if(file.exists()) return true;
    else return false;
}

QString Nurse::readNurseDataFromFile(QString patientID)
{
    QString path = "./EmployeeData/NurseData/";
    QDir dir;
    QFile file(path + patientID + ".txt");
    QString data;
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            data = file.readAll();
        }
    }
    return data;
}

void Nurse::addNewNurseTolist(QString name, QString id, QString timeShift)
{
    {
        QString path = "./EmployeeData/NurseData/";
        QDir dir;
        if(!dir.exists(path)) dir.mkpath(path);
        QFile file(path + id+".txt");
        if(file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            stream << "ID: " << id << endl;
            stream << "Name: " << name <<endl;
            stream << "Time Shift: " << timeShift << endl;
            file.close();
        }
    }
}
