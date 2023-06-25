#ifndef SINGUP_H
#define SINGUP_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QMessageBox>

namespace Ui {
class singup;
}

class singup : public QDialog
{
    Q_OBJECT

public:
    explicit singup(QWidget *parent = nullptr);
    ~singup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::singup *ui;

};

#endif // SINGUP_H
