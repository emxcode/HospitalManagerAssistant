#include "Controller.h"

Controller::Controller()
{
    m_mainWindow.show();
    initialConnection();
}
Controller::~Controller()
{

}

void Controller::initialConnection()
{
    connect(&m_mainWindow, &MainWindow::sigCreatNewPatient, this, &Controller::sltCreatNewPatient);
    connect(&m_mainWindow, &MainWindow::sigFindPatientId, this,&Controller::sltFindPatientId);
    connect(&m_mainWindow, &MainWindow::sigNewPersonalCreated, this,&Controller::sltNewPersonalCreated);
    connect(&m_mainWindow, &MainWindow::sigDoctorEventCreated, this,&Controller::sltDoctorEventCreated);
    connect(&m_mainWindow, &MainWindow::sigFindPersonalData, this,&Controller::sltFindPersonalData);
    connect(&m_mainWindow, &MainWindow::sigServicesUsed, this,&Controller::sltServicesUsed);
    connect(&m_mainWindow, &MainWindow::sigGetRoomStatus, this,&Controller::sltGetRoomStatus);


}
void Controller::sltCreatNewPatient(QString id, QString age, QString name, QString gender)
{
    m_patient.addNewPatientToList(id, name, age, gender);
}

void Controller::sltFindPatientId(QString patientId)
{
    bool hasPatientIDFound = m_patient.findPatientInList(patientId);
    bool hasPatientIDInSurviceFound = m_patient.findPatientInSurviceList(patientId);
    qDebug() << hasPatientIDFound << hasPatientIDInSurviceFound;

    {
        if(hasPatientIDFound == true)
        {
            m_mainWindow.setPatientDataInUI(m_patient.readDataInOtherFile(patientId));
            m_mainWindow.setPatientFound(true);
            m_mainWindow.setPatientId(patientId);
        }
        else
        {
            m_mainWindow.setPatientDataInUI("Patient Not Found!");
            m_mainWindow.setPatientFound(false);
            m_mainWindow.setPatientId("");
        }
    }

    {
        if(hasPatientIDInSurviceFound == true)
        {
            m_mainWindow.setPatientSurviceDataInUI(m_patient.readDataInSurviceFile(patientId));
            m_mainWindow.setPatientId(patientId);
        }
        else
        {
            m_mainWindow.setPatientSurviceDataInUI("Patient Survice Not Found!");
            //            m_mainWindow.setPatientId("");
        }
    }
}

void Controller::sltNewPersonalCreated(QString personlName, QString personalID, QString PersonalSpecialist, QString timeShift)
{
    m_employee.createNewPersonal(personlName, personalID, PersonalSpecialist, timeShift);
}

void Controller::sltDoctorEventCreated(QString doctorDef)
{
    QString patientId = m_mainWindow.getPatientId();
    bool res = m_patient.doctorEventCreated(patientId, doctorDef);
}

void Controller::sltFindPersonalData(QString id)
{
    bool isPersonalExist = m_employee.findPersonalInList(id);
    if(isPersonalExist)
    {
        m_mainWindow.setPersonalDataInTextEdit(m_employee.getPersonalData());
    }
    else
    {
        m_mainWindow.setPersonalDataInTextEdit("Personal Not Found");
    }
}

void Controller::sltServicesUsed(QString data)
{
    QString patientId = m_mainWindow.getPatientId();
    m_department.surviceRequested(data, patientId);
}

void Controller::sltGetRoomStatus()
{
    m_mainWindow.setRoomStatus( m_department.getRoomStatus());
}

