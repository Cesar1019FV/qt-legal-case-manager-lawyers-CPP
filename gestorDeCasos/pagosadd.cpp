#include "pagosadd.h"
#include "ui_pagosadd.h"

/**
 * @brief Constructor de la clase pagosadd.
 * @param parent Puntero al widget padre (opcional).
 */
pagosadd::pagosadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pagosadd)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor de la clase pagosadd.
 */
pagosadd::~pagosadd()
{
    delete ui;
}

/**
 * @brief Slot para manejar el evento del botón "Cancelar".
 */
void pagosadd::on_pushButton_Cancel_clicked()
{
    hide();
}

/**
 * @brief Slot para manejar el evento del botón "Guardar".
 */
void pagosadd::on_pushButton_Confirm_clicked()
{
    // Obtener los valores ingresados por el usuario
    QString cliente = ui->lineEdit_cliente->text();
    QString deuda = ui->lineEdit_deuda->text();
    QString abonado = ui->lineEdit_abonado->text();

    try {
        bool ok; // Variable auxiliar para verificar si la conversión fue exitosa
        float deuda2 = deuda.toFloat(&ok); // Convertir la deuda a un número en punto flotante
        float abonado2 = abonado.toFloat(&ok); // Convertir el abonado a un número en punto flotante
        float pendiente = deuda2 - abonado2; // Calcular el monto pendiente

        if (!ok) {
            throw std::invalid_argument("Debe ingresar un valor numérico."); // Lanzar una excepción si la conversión falla
        }

        // Abrir el archivo de pagos para agregar los nuevos datos
        QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/pagos.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << cliente << "," << deuda2 << "," << abonado2 << "," << pendiente << "\n"; // Escribir los datos en el archivo
            file.close();
            QMessageBox::information(this, "Éxito", "Datos guardados correctamente.");
                close();
        } else {
            QMessageBox::critical(this, "Error", "Error al abrir el archivo.");
            close();
        }

    } catch (const std::exception& e) {
        // Ocurrió un error, muestra el mensaje de error al usuario
        qDebug() << "Error: " << e.what();
    }
}
