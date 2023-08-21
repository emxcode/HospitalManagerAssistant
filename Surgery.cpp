#include "Surgery.h"

Surgery::Surgery()
{

}

void Surgery::setInDocumentRooms(QString patientId)
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
                stream << "Survice Type:" << "Surgery Used.";
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
                stream << "Survice Type:" << "Surgery Used.";
                stream << "ID: " << patientId << endl;
                stream << "Time: " << getTime() <<endl;
                stream <<"------------";

                file.close();
            }
        }
    }
}

QString Surgery::getTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    return  currentDateTimeString;
}
