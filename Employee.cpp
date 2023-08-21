#include "Employee.h"

Employee::Employee()
{

}

void Employee::createNewPersonal(QString name, QString Id, QString specialist, QString timeShift)
{
    if(specialist == "Nurse")
    {
        m_nurse.CreatNewNurseToList(name, Id ,timeShift);
    }
    else if(specialist == "Employee")
    {
        addNewEmployeeTolist(name, Id, specialist, timeShift);
    }
    else
    {
        m_doctor.addNewDoctorToList(name, Id, specialist,timeShift);
    }

}

void Employee::addNewEmployeeTolist(QString name, QString id, QString specialist, QString timeShift)
{
    {
        QString path = "./EmployeeData/EmployeesData/";
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

void Employee::readEmployeeDataFromFile(QString patientId)
{

    QString path = "./EmployeeData/EmployeesData/";
    QDir dir;
    QFile file(path + patientId + ".txt");
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            m_personaldata = file.readAll();
        }
    }
}

QString Employee::getPersonalData() const
{
    return m_personaldata;
}

bool Employee::findPersonalInList(QString PersonaltID)
{

    QString path1 = "./EmployeeData/EmployeesData/";
    QDir dir;
    QFile file(path1 + PersonaltID + ".txt");

    if(file.exists())
    {
        readEmployeeDataFromFile(PersonaltID);
    }
    else if(m_doctor.isDoctorCreated(PersonaltID))
    {
        m_personaldata = m_doctor.readDoctorDataFromFile(PersonaltID);
    }
    else if(m_nurse.isNurseCreated(PersonaltID))
    {
        m_personaldata = m_nurse.readNurseDataFromFile(PersonaltID);
    }
    else
    {
        return false;
    }
}
