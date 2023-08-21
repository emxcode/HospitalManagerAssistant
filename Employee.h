#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Doctors.h"
#include "Nurse.h"
#include <QString>


class Employee
{
public:
    Employee();

    Doctors m_doctor;
    Nurse m_nurse;

    void createNewPersonal(QString name, QString Id, QString specialist, QString timeShift);
    bool findPersonalInList(QString id);

    QString getPersonalData() const;

private:
    void addNewEmployeeTolist(QString name, QString Id, QString specialist, QString timeShift);
    QString m_personaldata;
    void readEmployeeDataFromFile(QString patientId);



};

#endif // EMPLOYEE_H
