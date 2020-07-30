#include "Messagepopup.h"
#include "ui_messagepopup.h"

MessagePopup::MessagePopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessagePopup)
{
    ui->setupUi(this);
}

void MessagePopup::setMessage(QString &s)
{
    ui->popMessTxt->setText(s);
}

MessagePopup::~MessagePopup()
{
    delete ui;
}
