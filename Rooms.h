#ifndef ROOMS_H
#define ROOMS_H
#include <QString>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

class Rooms
{
public:
    Rooms();

    const int m_totalRoomNumber = 100;
    int m_freeRoom;
    int m_usedRoom;

    void getMeNewRoom();

    int getFreeRoomValue() const;
    void setFreeRoom(int getFreeRoomValue);
    int getUsedRoomValue() const;
    void setUsedRoom(int getUsedRoomValue);
    void setInDocumentRooms(QString patientId);
    QString getTime();
};

#endif // ROOMS_H
