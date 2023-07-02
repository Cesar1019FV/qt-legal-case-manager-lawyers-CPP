#include "fechasadd.h"
#include "ui_fechasadd.h"

/**
 * @file fechasadd.cpp
 *
 * @brief Implementación de la clase fechasadd y sus funciones miembro.
 */

/**
 * @brief Constructor de la clase fechasadd
 */
fechasadd::fechasadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fechasadd)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor de la clase fechasadd
 */
fechasadd::~fechasadd()
{
    delete ui;
}

/**
 * @brief Maneja la señal clicked del botón "Cancelar"
 */
void fechasadd::on_pushButton_2_clicked()
{
    hide(); // Oculta la ventana actual
}

/**
 * @brief Maneja la señal clicked del botón "Confirmar"
 */
void fechasadd::on_pushButton_confirmar_clicked()
{
    QString motivo = ui->lineEdit_Motivo->text();
    QString fechaHora = ui->dateTimeEdit->text();

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/fechas.txt");

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << motivo << "," << fechaHora << "\n";
        file.close();
        QMessageBox::information(this, "Éxito", "Datos guardados correctamente.");
            close(); // Cierra la ventana actual
    }
    else {
        QMessageBox::critical(this, "Error", "Error al abrir el archivo.");
        close(); // Cierra la ventana actual
    }
}
