#include "dialogmain.h"
#include "ui_dialogmain.h"
#include "mainwindow.h"

/**
 * @file dialogmain.cpp
 *
 * @brief Implementación de la clase DialogMain y sus funciones miembro.
 */

/**
 * @brief Constructor de la clase DialogMain
 */
DialogMain::DialogMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMain)
{
    ui->setupUi(this); // Configura la interfaz de usuario (UI) del diálogo
}

/**
 * @brief Destructor de la clase DialogMain
 */
DialogMain::~DialogMain()
{
    delete ui; // Libera la memoria utilizada por la interfaz de usuario (UI) del diálogo
}

/**
 * @brief Maneja la señal accepted del botón "buttonBox"
 */
void DialogMain::on_buttonBox_accepted()
{
    // Obtiene los valores ingresados en los line edits
    QString caso = ui->lineEdit_caso->text();
    QString delito = ui->lineEdit_delito->text();
    QString demandado = ui->lineEdit_demandado->text();
    QString demandante = ui->lineEdit_demandante->text();
    QString expediente = ui->lineEdit_expediente->text();

    // Crea un objeto QFile para abrir el archivo "casos.txt"
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//casos.txt");

    // Intenta abrir el archivo en modo Append (agregar) y Text (texto)
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        // Escribe los valores en el archivo separados por comas
        stream << caso << "," << delito << "," << demandado << "," << demandante << "," << expediente << "\n";
        file.close(); // Cierra el archivo
        QMessageBox::information(this, "Éxito", "Datos guardados correctamente.");
            hide(); // Oculta el diálogo
    } else {
        QMessageBox::critical(this, "Error", "Error al abrir el archivo.");
        hide(); // Oculta el diálogo
    }

    accepted(); // Emite la señal accepted del diálogo
}

/**
 * @brief Maneja la señal rejected del botón "buttonBox"
 */
void DialogMain::on_buttonBox_rejected()
{
    reject(); // Emite la señal rejected del diálogo
}

