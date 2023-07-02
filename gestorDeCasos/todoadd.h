#ifndef TODOADD_H
#define TODOADD_H

#include <QDialog>
#include <QStandardPaths>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>


namespace Ui {
class todoadd;
}

class todoadd : public QDialog
{
    Q_OBJECT

public:
    explicit todoadd(QWidget *parent = nullptr);
    ~todoadd();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_Confirm_clicked();

private:
    Ui::todoadd *ui;
};

#endif // TODOADD_H
