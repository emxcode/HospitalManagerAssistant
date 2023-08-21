#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MainWindow.h"
#include "Patient.h"
#include "QObject"
#include "GlobalDataStructure.h"
#include "Employee.h"
#include "Departments.h"

class Controller : public QObject
{
   Q_OBJECT

public:
    explicit Controller();
    ~Controller();
private:
    MainWindow m_mainWindow;
    Patient m_patient;
    Employee m_employee;
    Departments m_department;

    void initialConnection();

public Q_SLOTS:
    void sltCreatNewPatient(QString id, QString age, QString name,QString gender);
    void sltFindPatientId(QString patientId);
    void sltNewPersonalCreated(QString personlName, QString personalID, QString PersonalSpecialist, QString timeShift);
    void sltDoctorEventCreated(QString doctorDef);
    void sltFindPersonalData(QString id);
    void sltServicesUsed(QString data);
    void sltGetRoomStatus();


};

#endif // CONTROLLER_H
