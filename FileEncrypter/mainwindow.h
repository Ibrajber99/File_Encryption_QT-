#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Ceasercipher.h"
#include <QtMultimedia/QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CeaserCipher *cipher;
    void onClickEncrypt();
    void onClickDecrypt();
    void locateFile();
    QString file_Name;
    QMediaPlayer *player;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
