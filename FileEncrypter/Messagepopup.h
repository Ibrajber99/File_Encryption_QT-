#ifndef MESSAGEPOPUP_H
#define MESSAGEPOPUP_H

#include <QDialog>

namespace Ui {
class MessagePopup;
}

class MessagePopup : public QDialog
{
    Q_OBJECT

public:
    explicit MessagePopup(QWidget *parent = nullptr);
    void setMessage(QString &s);
    ~MessagePopup();

private:
    Ui::MessagePopup *ui;
};

#endif // MESSAGEPOPUP_H
