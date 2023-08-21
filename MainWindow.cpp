#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillUiData();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPatientDataInUI(QString data)
{
    ui->textEditPatientData->clear();
    ui->textEditPatientData->setText(data);
    ui->labelPatientID->setText(patientId);
}
void MainWindow::setPatientSurviceDataInUI(QString data)
{
    ui->textEditRecived->clear();
    ui->textEditRecived->setText(data);
    ui->labelPatientID_2->setText(patientId);
}

void MainWindow::setRoomStatus(int usedRoom)
{
    ui->labelAllRooms->setText("100");
    ui->labelUsedRooms->setText(QString::number(usedRoom));
    ui->labelFreeRooms->setText(QString::number(100-usedRoom));
}

void MainWindow::setPatientFound(bool value)
{
    patientFound = value;
}


void MainWindow::on_pushButtonFindPatient_clicked()
{
    QString patientId = ui->lineEditPatientIdFound->text();
    Q_EMIT sigFindPatientId(patientId);
}


void MainWindow::on_pushButtonRegisterNewPatient_clicked()
{
    QString patientName = ui->lineEditPatientNameReg->text();
    QString patientID = ui->lineEditPatieantIDReg->text();
    QString patientGender;
    QString patientAge = ui->dateTimeBirthDay->text();

    if(ui->radioButtonMaleGender->isChecked()) patientGender = "Male";
    else if(ui->radioButtonFemaleGender->isChecked()) patientGender = "Female";
    else if(ui->radioButtonOtherGender->isChecked()) patientGender = "Other Gender";

    ui->lineEditPatieantIDReg->clear();
    ui->dateTimeBirthDay->clear();
    ui->lineEditPatientNameReg->clear();

    Q_EMIT sigCreatNewPatient(patientID, patientAge, patientName, patientGender);

}

void MainWindow::on_pushButtonCreatPersonal_clicked()
{
    QString personlName, personalID, PersonalSpecialist, timeShift;
    personlName = ui->lineEditRegPersonalID->text();
    personalID = ui->lineEditRegPersonalID->text();
    PersonalSpecialist = ui->comboBoxPersonalSpecialist->currentText();
    if(ui->checkBoxSat->isChecked())      timeShift += "Saturday - ";
    if(ui->checkBoxSun->isChecked())      timeShift += "Sunday - ";
    if(ui->checkBoxMon->isChecked())      timeShift += "Monday - ";
    if(ui->checkBoxTue->isChecked())      timeShift += "Tuesday - ";
    if(ui->checkBoxWed->isChecked())      timeShift += "Wednesday - ";
    if(ui->checkBoxThu->isChecked())      timeShift += "Thursday - ";
    if(ui->checkBoxFri->isChecked())      timeShift += "Friday - ";
    if(ui->checkBoxMorning->isChecked())  timeShift += "/ Morning Shift ";
    if(ui->checkBoxAfternoon->isChecked())timeShift += "/ Afternoon Shift";
    if(ui->checkBoxNight->isChecked())    timeShift += "/ Night Shift ";

    ui->checkBoxSat->setChecked(false);
    ui->checkBoxSun->setChecked(false);
    ui->checkBoxMon->setChecked(false);
    ui->checkBoxTue->setChecked(false);
    ui->checkBoxWed->setChecked(false);
    ui->checkBoxThu->setChecked(false);
    ui->checkBoxFri->setChecked(false);
    ui->checkBoxMorning->setChecked(false);
    ui->checkBoxAfternoon->setChecked(false);
    ui->checkBoxNight->setChecked(false);
    ui->lineEditRegPersonalName->clear();
    ui->lineEditRegPersonalID->clear();


    Q_EMIT sigNewPersonalCreated(personlName, personalID, PersonalSpecialist, timeShift);
    qDebug() << personlName << personalID << PersonalSpecialist << timeShift;

}

void MainWindow::fillUiData()
{
  ui->comboBoxPersonalSpecialist->addItem("Nurse");
  ui->comboBoxPersonalSpecialist->addItem("Emergency Medicine Specialists");
  ui->comboBoxPersonalSpecialist->addItem("Family Physicians");
  ui->comboBoxPersonalSpecialist->addItem("Cardiologists");
  ui->comboBoxPersonalSpecialist->addItem("Pharmecy");
  ui->comboBoxPersonalSpecialist->addItem("Dermatologists");
  ui->comboBoxPersonalSpecialist->addItem("Radiologist");
  ui->comboBoxPersonalSpecialist->addItem("Employee");

}

QString MainWindow::getPatientId() const
{
    return patientId;
}

void MainWindow::setPatientId(const QString &value)
{
    patientId = value;
}

void MainWindow::setPersonalDataInTextEdit(QString data)
{
    ui->textEditPersonalData->clear();
    ui->textEditPersonalData->setText(data);
}


void MainWindow::on_pushButtonAdd_clicked()
{
    bool isPharmacyUsed =  ui->checkBoxPharmecyNeed->isChecked();
    bool isSurgeryUsed =   ui->checkBoxSurgeryNeed->isChecked();
    bool isRadiologyUsed = ui->checkBoxRadiologyNeed->isChecked();
    bool isDentisUsed =    ui->checkBoxDentisNeed->isChecked();
    bool isRoomUsed =      ui->checkBoxRoomNeed->isChecked();

    QString DoctoDef = ui->textEditDoctorDef->toPlainText();
    QString data = "\n" +DoctoDef;

    ui->textEditDoctorDef->clear();
    ui->checkBoxPharmecyNeed->setChecked(false);
    ui->checkBoxSurgeryNeed->setChecked(false);
    ui->checkBoxRadiologyNeed->setChecked(false);
    ui->checkBoxDentisNeed->setChecked(false);
    ui->checkBoxRoomNeed->setChecked(false);

    if(isPharmacyUsed) data += "\n Pharmecy Need.";
    if(isSurgeryUsed) data += "\n Surgery Need.";
    if(isRadiologyUsed) data += "\n Radiology Need.";
    if(isDentisUsed) data += "\n Dentis Need.";
    if(isRoomUsed) data += "\n Room Need.";

    Q_EMIT sigDoctorEventCreated(data);

}

void MainWindow::on_pushButtonFindPersonal_clicked()
{
    QString personalData = ui->lineEditPersonalID->text();
    Q_EMIT sigFindPersonalData(personalData);
}

void MainWindow::on_pushButtonRecivedSurvices_clicked()
{
  bool isPharmacyUsed =  ui->checkBoxParmecyUsed->isChecked();
  bool isSurgeryUsed =   ui->checkBoxSurgeryUsed->isChecked();
  bool isRadiologyUsed = ui->checkBoxRadiologyUsed->isChecked();
  bool isDentisUsed =    ui->checkBoxDantisUsed->isChecked();
  bool isRoomUsed =      ui->checkBoxRoomUsed->isChecked();


  QString DoctoDef = ui->textEditRecived->toPlainText();
  QString data = "\n" +DoctoDef;

  ui->textEditRecived->clear();
  ui->checkBoxParmecyUsed->setChecked(false);
  ui->checkBoxSurgeryUsed->setChecked(false);
  ui->checkBoxRadiologyUsed->setChecked(false);
  ui->checkBoxDantisUsed->setChecked(false);
  ui->checkBoxRoomUsed->setChecked(false);

  if(isPharmacyUsed ) data += "\n Pharmecy Used.";
  if(isSurgeryUsed  ) data += "\n Surgery Used.";
  if(isRadiologyUsed) data += "\n Radiology Used.";
  if(isDentisUsed   ) data += "\n Dentis Used.";
  if(isRoomUsed     ) data += "\n Room Used.";

  Q_EMIT sigServicesUsed(data);

}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEditRecived->clear();
    ui->textEditDoctorDef->clear();
    ui->textEditPatientData->clear();
    ui->textEditPersonalData->clear();

    ui->lineEditPersonalID->clear();
    ui->lineEditPatieantIDReg->clear();
    ui->lineEditRegPersonalID->clear();
    ui->lineEditPatientIdFound->clear();
    ui->lineEditPatientNameReg->clear();
    ui->lineEditRegPersonalName->clear();

    ui->textEditRecived->clear();
    ui->checkBoxParmecyUsed->setChecked(false);
    ui->checkBoxSurgeryUsed->setChecked(false);
    ui->checkBoxRadiologyUsed->setChecked(false);
    ui->checkBoxDantisUsed->setChecked(false);
    ui->checkBoxRoomUsed->setChecked(false);

    ui->textEditDoctorDef->clear();
    ui->checkBoxPharmecyNeed->setChecked(false);
    ui->checkBoxSurgeryNeed->setChecked(false);
    ui->checkBoxRadiologyNeed->setChecked(false);
    ui->checkBoxDentisNeed->setChecked(false);
    ui->checkBoxRoomNeed->setChecked(false);


    ui->checkBoxSat->setChecked(false);
    ui->checkBoxSun->setChecked(false);
    ui->checkBoxMon->setChecked(false);
    ui->checkBoxTue->setChecked(false);
    ui->checkBoxWed->setChecked(false);
    ui->checkBoxThu->setChecked(false);
    ui->checkBoxFri->setChecked(false);
    ui->checkBoxMorning->setChecked(false);
    ui->checkBoxAfternoon->setChecked(false);
    ui->checkBoxNight->setChecked(false);

}

void MainWindow::on_pushButtonUpdata_clicked()
{
    sigGetRoomStatus();
}
