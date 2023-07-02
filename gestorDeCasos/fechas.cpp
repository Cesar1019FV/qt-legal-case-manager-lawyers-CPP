#include "fechas.h"
#include "ui_fechas.h"
#include "fechasadd.h"

/**
 * @file fechas.cpp
 *
 * @brief Implementación de la clase fechas y sus funciones miembro.
 */

/**
 * @brief Llena la tabla con los datos del archivo.
 *
 * @param tableWidget Puntero al QTableWidget donde se mostrarán los datos.
 * @param nombreArchivo Nombre del archivo que contiene los datos.
 */
void llenarTabla(QTableWidget* tableWidget, const QString& nombreArchivo) {
    QFile archivo(nombreArchivo);
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        int fila = tableWidget->rowCount(); // Obtener la última fila de la tabla

        while (!stream.atEnd()) {
            QString linea = stream.readLine();
            QStringList datos = linea.split(',');

            if (datos.size() == 2) {
                tableWidget->insertRow(fila); // Insertar una nueva fila
                for (int columna = 0; columna < 2; columna++) {
                    QTableWidgetItem* item = new QTableWidgetItem(datos[columna]);
                    tableWidget->setItem(fila, columna, item);
                }
                fila++;
            }
        }

        archivo.close();
    } else {
        qDebug() << "No se pudo abrir el archivo.";
    }
}

/**
 * @brief Constructor de la clase fechas
 */
fechas::fechas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fechas)
{
    ui->setupUi(this);
    setWindowTitle("Fechas pendientes");

    QStringList titulos;
    ui->tableWidget_fechas->setColumnCount(2);
    titulos << "Motivo" << "Fecha";
    ui->tableWidget_fechas->setHorizontalHeaderLabels(titulos);

    // Ruta del archivo
    QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/fechas.txt";

    // Llenar la tabla desde el archivo
    llenarTabla(ui->tableWidget_fechas, rutaArchivo);

    //reajustar el tamano
    ui->tableWidget_fechas->setColumnWidth(0, this->width()/2);
    ui->tableWidget_fechas->setColumnWidth(1, this->width()/2);
}

/**
 * @brief Destructor de la clase fechas
 */
fechas::~fechas()
{
    delete ui;
}

/**
 * @brief Maneja la señal clicked del botón "Salir"
 */
void fechas::on_pushButton_Salir_clicked()
{
    hide(); // Oculta la ventana actual
}

/**
 * @brief Maneja la señal clicked del botón "Eliminar"
 */
void fechas::on_pushButton_eliminar_clicked()
{
    // Obtener la fila seleccionada
    int filaSeleccionada = ui->tableWidget_fechas->currentRow();

    // Verificar si hay una fila seleccionada
    if (filaSeleccionada >= 0) {
        // Obtener el contenido de la línea en el archivo .txt que corresponde a la fila seleccionada
        QString lineaEliminar;
        QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//fechas.txt";
        QFile archivo(rutaArchivo);
        if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&archivo);
            int filaActual = 0;
            while (!in.atEnd()) {
                QString linea = in.readLine();
                if (filaActual != filaSeleccionada) {
                    lineaEliminar += linea + "\n";
                }
                filaActual++;
            }
            archivo.close();
        }

        // Eliminar la fila seleccionada del QTableWidget
        ui->tableWidget_fechas->removeRow(filaSeleccionada);

        // Guardar el contenido actualizado en el archivo .txt
        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream out(&archivo);
            out << lineaEliminar;
            archivo.close();
        }
    } else {
        // No se ha seleccionado ninguna fila, mostrar un mensaje de advertencia
        QMessageBox::warning(this, "Eliminar línea", "Por favor, seleccione una línea para eliminar.");
    }
}

/**
 * @brief Maneja la señal clicked del botón "Nueva"
 */
void fechas::on_pushButton_nueva_clicked()
{
    fechasadd fa(this);
    fa.exec(); // Abre el diálogo de fechasadd
}

/**
 * @brief Maneja la señal clicked del botón "Actualizar"
 */
void fechas::on_pushButton_actualizar_clicked()
{
    // Cerrar la ventana actual
    close();

    // Crear una nueva instancia de la ventana y mostrarla
    fechas *newFecha = new fechas();
    newFecha->show();
}
