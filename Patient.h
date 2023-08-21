#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

class Patient
{
public:
    Patient();

public:
    void addNewPatientToList(QString patientID,
                             QString patientName,
                             QString patientAge,
                             QString patientGender);
    bool findPatientInList(QString PatientID);
    bool findPatientInSurviceList(QString patientID);
    QString readDataInOtherFile(QString patientId);
    QString readDataInSurviceFile(QString patientId);
    QString getTime();
    bool doctorEventCreated(QString patientId, QString data);


private:
    int patientIDFound;

};

#endif // PATIENT_H
