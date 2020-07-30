#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Messagepopup.h"
#include "Ceasercipher.h"
#include<QString>
#include<QFileDialog>
#include<QDir>
#include<QMessageBox>
#include <QtMultimedia/QMediaPlayer>
#include<windows.h>
#include<mmsystem.h>
#include<QtMultimedia/QSound>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    cipher = new CeaserCipher;
    ui->setupUi(this);
    this->setStyleSheet(QString("Background-color:#3d5c5c"));
    ui->label->setStyleSheet(QString("border-image:url(:/new/encImage.png)"));
    ui->EncryptBtn->setStyleSheet(QString("background-color:red"));
    ui->DecryptBtn->setStyleSheet(QString("background-color:green"));
    ui->locateBtn->setStyleSheet(QString("background-color:#33D1B9"));
    ui->footerLbl->setText(ui->footerLbl->text() + 0xA9);
    connect(ui->EncryptBtn,&QPushButton::clicked,this,[this](){onClickEncrypt();});
    connect(ui->DecryptBtn,&QPushButton::clicked,this,[this](){onClickDecrypt();});
    connect(ui->locateBtn,&QPushButton::clicked,this,[this](){locateFile();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickEncrypt()
{
   if(cipher->validateFile(file_Name)){
       cipher->encryptFile();
   }

}
void MainWindow::onClickDecrypt()
{
    if(cipher->validateFile(file_Name)){
        cipher->decryptFile();
    }
}
void MainWindow::locateFile(){
    file_Name = QFileDialog::getOpenFileName(this,"Open a file",QDir::homePath());
}

