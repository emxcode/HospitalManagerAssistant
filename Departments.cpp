#include "Departments.h"

Departments::Departments()
{

}

void Departments::surviceRequested(QString data, QString id)
{
    if(data.contains("Room Used"))
    {
        if(m_rooms.getFreeRoomValue() > 0)
        {
            m_rooms.getMeNewRoom();
            m_rooms.setInDocumentRooms(id);
        }
    }
    if(data.contains("Dentis Used"))
    {
        m_dentis.setInDocumentRooms(id);
    }
    if(data.contains("Radiology Used"))
    {
        m_radiology.setInDocumentRooms(id);
    }
    if(data.contains("Surgery Used"))
    {
        m_surgery.setInDocumentRooms(id);
    }
    if(data.contains("Pharmecy Used"))
    {
        m_pharmecy.setInDocumentRooms(id);
    }


}

int Departments::getRoomStatus()
{
    return m_rooms.getUsedRoomValue();
}


