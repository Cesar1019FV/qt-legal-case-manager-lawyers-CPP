#include "pagos.h"
#include "ui_pagos.h"
#include "pagosadd.h"

/**
 * @brief Llena un widget de tabla con datos obtenidos desde un archivo.
 * @param tableWidget Puntero al widget de tabla que se desea llenar.
 * @param nombreArchivo Nombre del archivo que contiene los datos.
 */
void llenarWidget(QTableWidget* tableWidget, const QString& nombreArchivo) {
    QFile archivo(nombreArchivo);
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        int fila = tableWidget->rowCount(); // Obtener la última fila de la tabla

        while (!stream.atEnd()) {
            QString linea = stream.readLine();
            QStringList datos = linea.split(',');

            if (datos.size() == 4) {
                tableWidget->insertRow(fila); // Insertar una nueva fila
                for (int columna = 0; columna < 4; columna++) {
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
 * @brief Constructor de la clase pagos.
 * @param parent Puntero al widget padre (opcional).
 */
pagos::pagos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pagos)
{
    ui->setupUi(this);
    setWindowTitle("Pagos pendientes");

    // Titulos y columnas de la tabla
    QStringList titulos;
    ui->tableWidget_pagos->setColumnCount(4);
    titulos << "Cliente" << "Monto adeudado" << "Monto abonado" << "Monto pendiente";
    ui->tableWidget_pagos->setHorizontalHeaderLabels(titulos);

    // Ruta del archivo
    QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//pagos.txt";

    // Llenar la tabla desde el archivo
    llenarWidget(ui->tableWidget_pagos, rutaArchivo);

    // Reajustar el tamaño de las columnas
    ui->tableWidget_pagos->setColumnWidth(0, this->width()/3);
    ui->tableWidget_pagos->setColumnWidth(1, this->width()/4);
    ui->tableWidget_pagos->setColumnWidth(2, this->width()/4);
    ui->tableWidget_pagos->setColumnWidth(3, this->width()/4);
}

/**
 * @brief Destructor de la clase pagos.
 */
pagos::~pagos(){
    delete ui;
}

/**
 * @brief Slot para manejar el evento del botón "Añadir".
 */
void pagos::on_pushButton_anadir_clicked()
{
    pagosadd add(this);
    add.exec();
}

/**
 * @brief Slot para manejar el evento del botón "Borrar".
 */
void pagos::on_pushButton_Borrar_clicked()
{
    // Obtener la fila seleccionada
    int filaSeleccionada = ui->tableWidget_pagos->currentRow();

    // Verificar si hay una fila seleccionada
    if (filaSeleccionada >= 0) {
        // Obtener el contenido de la línea en el archivo .txt que corresponde a la fila seleccionada
        QString lineaEliminar;
        QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/pagos.txt";
        QFile texto(rutaArchivo);
        if (texto.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&texto);
            int filaActual = 0;
            while (!in.atEnd()) {
                QString linea = in.readLine();
                if (filaActual != filaSeleccionada) {
                    lineaEliminar += linea + "\n";
                }
                filaActual++;
            }
            texto.close();
        }

        // Eliminar la fila seleccionada del QTableWidget
        ui->tableWidget_pagos->removeRow(filaSeleccionada);

        // Guardar el contenido actualizado en el archivo .txt
        if (texto.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream out(&texto);
            out << lineaEliminar;
            texto.close();
        }
    } else {
        // No se ha seleccionado ninguna fila, mostrar un mensaje de advertencia
        QMessageBox::warning(this, "Eliminar línea", "Por favor, seleccione una línea para eliminar.");
    }
}

/**
 * @brief Slot para manejar el evento del botón "Actualizar".
 */
void pagos::on_pushButton_3_clicked()
{
    // Cerrar la ventana actual
    close();

    // Crear una nueva instancia de la ventana y mostrarla
    pagos *newPagos = new pagos();
    newPagos->show();
}

/**
 * @brief Slot para manejar el evento del botón "Salir".
 */
void pagos::on_pushButton_Salir_clicked()
{
    hide(); // Ocultar ventana
}

