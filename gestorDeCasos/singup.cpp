
#include "singup.h"
#include "ui_singup.h"

singup::singup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singup)
{
    ui->setupUi(this);
}

singup::~singup()
{
    delete ui;
}

void singup::on_pushButton_clicked()
{
    QString usuarioRE = ui->lineEdit_userRE->text();
    QString passwordRE = ui->lineEdit_passwordRE->text();

    QFile archivo(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//usuarios.txt");

    if (archivo.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&archivo);
        stream << usuarioRE << "," << passwordRE << "\n";
        archivo.close();
        QMessageBox::information(this, "Éxito", "Datos guardados correctamente en el archivo.");
        hide();
    }
    else {
        QMessageBox::critical(this, "Error", "Error al abrir el archivo.");
        hide();
    }
}

