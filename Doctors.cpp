#include "Doctors.h"

Doctors::Doctors()
{

}

void Doctors::addNewDoctorToList(QString name, QString id, QString specialist, QString timeShift)
{
    addNewDoctorTolist(name, id, specialist,timeShift);
}

bool Doctors::isDoctorCreated(QString personalId)
{

    QString path1 = "./EmployeeData/DoctorsData/";
    QDir dir;
    QFile file(path1 + personalId + ".txt");
    if(file.exists()) return true;
    else return false;

}

QString Doctors::readDoctorDataFromFile(QString patientId)
{

    QString path = "./EmployeeData/DoctorsData/";
    QDir dir;
    QFile file(path + patientId + ".txt");
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

void Doctors::addNewDoctorTolist(QString name, QString id, QString specialist,QString timeShift)
{
    {
        QString path = "./EmployeeData/DoctorsData/";
        QDir dir;
        if(!dir.exists(path)) dir.mkpath(path);
        QFile file(path + id+".txt");

        if(file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            stream << "ID: " << id << endl;
            stream << "Name: " << name <<endl;
            stream << "Specialist: " << specialist <<endl;
            stream << "Time Shift: " << timeShift << endl;
            file.close();
        }
    }
}
