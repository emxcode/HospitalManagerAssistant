#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPatientDataInUI(QString data);
    bool patientFound;

    void setPatientFound(bool value);

    void setPatientId(const QString &value);

    void setPersonalDataInTextEdit(QString data);

    QString getPatientId() const;

    void setPatientSurviceDataInUI(QString data);

    void setRoomStatus(int usedRoom);

private slots:
    void on_pushButtonFindPatient_clicked();


    void on_pushButtonRegisterNewPatient_clicked();

    void on_pushButtonCreatPersonal_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonFindPersonal_clicked();

    void on_pushButtonRecivedSurvices_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonUpdata_clicked();

private:
    Ui::MainWindow *ui;
    void fillUiData();
    QString patientId;


Q_SIGNALS:
    void sigFindPatientId(QString patientId);
    void sigCreatNewPatient(QString id, QString age, QString name,QString gender);
    void sigNewPersonalCreated(QString personlName, QString personalID, QString PersonalSpecialist, QString timeShift);
    void sigDoctorEventCreated(QString doctorDef);
    void sigFindPersonalData(QString id);
    void sigServicesUsed(QString data);
    void sigGetRoomStatus();
};
#endif // MAINWINDOW_H
