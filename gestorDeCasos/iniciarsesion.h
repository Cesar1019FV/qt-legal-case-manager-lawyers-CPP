#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "singup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class iniciarsesion; }
QT_END_NAMESPACE

class iniciarsesion : public QDialog
{
    Q_OBJECT

public:
    iniciarsesion(QWidget *parent = nullptr);
    ~iniciarsesion();

private slots:
    void on_pushButton_continuar_clicked();

    void on_pushButton_Registrarse_clicked();

private:
    Ui::iniciarsesion *ui;
    singup *SingUp;
};
#endif // INICIARSESION_H
