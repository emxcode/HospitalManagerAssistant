#include "Dentis.h"

Dentis::Dentis()
{

}

void Dentis::setInDocumentRooms(QString patientId)
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
                stream << "Survice Type:" << "Dentis Used.";
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
                stream << "Survice Type:" << "Dentis Used.";
                stream << "ID: " << patientId << endl;
                stream << "Time: " << getTime() <<endl;
                stream <<"------------";

                file.close();
            }
        }
    }
}

QString Dentis::getTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    return  currentDateTimeString;
}
