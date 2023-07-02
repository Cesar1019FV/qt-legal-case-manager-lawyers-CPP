#include "todoadd.h"
#include "ui_todoadd.h"

todoadd::todoadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todoadd)
{
    ui->setupUi(this);
}

todoadd::~todoadd()
{
    delete ui;
}

/**
 * @brief Slot para manejar el evento del botón "Cancelar".
 */
void todoadd::on_pushButton_2_clicked()
{
    hide();
}

/**
 * @brief Slot para manejar el evento del botón "Confirmar".
 */
void todoadd::on_pushButton_Confirm_clicked()
{
    //extrae la variable y la almacena en el archivo txt
    QString task = ui->lineEdit->text();

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoList.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << task << "\n";
        file.close();
        QMessageBox::information(this, "Éxito", "Datos guardados correctamente.");
            close(); // Cierra la ventana actual
    }
    //error en caso de no existir el archivo txt
    else {
        QMessageBox::critical(this, "Error", "Error al abrir el archivo.");
        close(); // Cierra la ventana actual
    }
}

