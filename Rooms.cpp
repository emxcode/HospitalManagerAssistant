#include "Rooms.h"

Rooms::Rooms()
{
    m_freeRoom = 100;
    m_usedRoom = 0;
}

void Rooms::getMeNewRoom()
{
    m_freeRoom --;
    m_usedRoom ++;
}

int Rooms::getUsedRoomValue() const
{
    return m_usedRoom;
}

void Rooms::setUsedRoom(int usedRoom)
{
    m_usedRoom = usedRoom;
}

void Rooms::setInDocumentRooms(QString patientId)
{
    {
        QString path = "./Survices/";
        QDir dir;
        if(!dir.exists(path)) dir.mkpath(path);
        QFile file(path + patientId+".txt");
        if(!file.exists())
        {
            if(file.open(QIODevice::WriteOnly))
            {
                QTextStream stream(&file);
                stream << "Survice Type:" << "Room Used.";
                stream << "ID: " << patientId << endl;
                stream << "Time: " << getTime() <<endl;
                stream <<"------------";

                file.close();
            }
        }
        else
        {
            if(file.open(QIODevice::Append))
            {
                QTextStream stream(&file);
                stream << "Survice Type:" << "Room Used.";
                stream << "ID: " << patientId << endl;
                stream << "Time: " << getTime() <<endl;
                stream <<"------------";

                file.close();
            }
        }
    }
}

QString Rooms::getTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    return  currentDateTimeString;
}

int Rooms::getFreeRoomValue() const
{
    return m_freeRoom;
}

void Rooms::setFreeRoom(int freeRoom)
{
    m_freeRoom = freeRoom;
}



