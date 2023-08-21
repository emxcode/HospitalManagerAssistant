#include "Patient.h"

Patient::Patient()
{

}

void Patient::addNewPatientToList(QString patientID,
                                  QString patientName,
                                  QString patientAge,
                                  QString patientGender)
{

    {
        QString path = "./PatientFile/";
        QDir dir;
        if(!dir.exists(path)) dir.mkpath(path);
        QFile file(path + patientID+".txt");
        if(!file.exists())
        {
            if(file.open(QIODevice::WriteOnly))
            {
                QTextStream stream(&file);
                stream << "ID: " << patientID << endl;
                stream << "Name: " << patientName <<endl;
                stream << "Sex: " << patientGender << endl;
                stream << "Age: " << patientAge << endl;
                file.close();
            }
        }
    }

}

bool Patient::findPatientInList(QString PatientID)
{
    QString path = "./PatientFile/";
    QDir dir;
    QFile file(path + PatientID + ".txt");
    if(file.exists()) return true;
    else return false;
}

bool Patient::findPatientInSurviceList(QString patientID)
{
    QString path = "./Survices/";
    QDir dir;
    QFile file(path + patientID + ".txt");
    if(file.exists()) return true;
    else return false;
}
QString Patient::readDataInOtherFile(QString patientId)
{
    QString path = "./PatientFile/";
    QString data;
    QDir dir;
    QFile file(path + patientId + ".txt");
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            data = file.readAll();
        }
    }
    return data;
}

QString Patient::readDataInSurviceFile(QString patientId)
{
    QString path = "./Survices/";
    QString data;
    QDir dir;
    QFile file(path + patientId + ".txt");
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            data = file.readAll();
        }
    }
    return data;
}

QString Patient::getTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    return  currentDateTimeString;
}

bool Patient::doctorEventCreated(QString patientId, QString data)
{
    QString path = "./PatientFile/";
    QDir dir;
    QFile file(path + patientId + ".txt");
    if(file.exists())
    {
        if(file.open(QIODevice::Append))
        {
            QTextStream stream(&file);
            stream << endl << "-----------------" << endl;
            stream << "Time: " << getTime() <<endl;
            stream << data;
            file.close();
            return true;
        }
    }
    else return false;
}
