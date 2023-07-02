#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogmain.h"
#include "todolist.h"
#include "fechas.h"
#include "pagos.h"

/**
 * @brief Llena una tabla con datos obtenidos desde un archivo.
 * @param tableWidget Puntero a la tabla que se desea llenar.
 * @param nombreArchivo Nombre del archivo que contiene los datos.
 */
void llenarTablaDesdeArchivo(QTableWidget* tableWidget, const QString& nombreArchivo) {
    QFile archivo(nombreArchivo);
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        int fila = tableWidget->rowCount(); // Obtener la última fila de la tabla

        while (!stream.atEnd()) {
            QString linea = stream.readLine();
            QStringList datos = linea.split(',');

            if (datos.size() == 5) {
                tableWidget->insertRow(fila); // Insertar una nueva fila
                for (int columna = 0; columna < 5; columna++) {
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Titulos y columnas de la QTableWidget
    QStringList titulos;
    setWindowTitle("Pagina principal");
    ui->tableWidget->setColumnCount(5);
    titulos << "Caso" << "Delito" << "Demandado" << "Demandante" << "Expediente";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    // Ruta del archivo
    QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/casos.txt";

    // Llenar la tabla desde el archivo
    llenarTablaDesdeArchivo(ui->tableWidget, rutaArchivo);

    // Reajustar el tamaño de las columnas
    ui->tableWidget->setColumnWidth(0, this->width()/3);
    ui->tableWidget->setColumnWidth(1, this->width()/3);
    ui->tableWidget->setColumnWidth(2, this->width()/3);
    ui->tableWidget->setColumnWidth(3, this->width()/3);
    ui->tableWidget->setColumnWidth(4, this->width()/3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
* @brief Ejecución de la ventana nuevo caso
*/
void MainWindow::on_nuevoCasoBottom_clicked()
{
    DialogMain pd(this);
    pd.exec();
}

/**
* @brief Ejecución de la función toDoList
*/
void MainWindow::on_pushButton_clicked()
{
    toDoList td(this);
    td.exec();
}

/**
* @brief Ejecución de la función de Fechas
*/
void MainWindow::on_fechasBT_clicked()
{
    fechas fs(this);
    fs.exec();
}

/**
* @brief Función para eliminar un elemento del QTableWidget
*/
void MainWindow::on_pushButton_eliminar_clicked()
{
    // Obtener la fila seleccionada
    int filaSeleccionada = ui->tableWidget->currentRow();

    // Verificar si hay una fila seleccionada
    if (filaSeleccionada >= 0) {
        // Obtener el contenido de la línea en el archivo .txt que corresponde a la fila seleccionada
        QString lineaEliminar;
        QString rutaArchivo = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/casos.txt";
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
        ui->tableWidget->removeRow(filaSeleccionada);

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
 * @brief Actualiza la tabla mostrando los datos más recientes añadidos.
 */
void MainWindow::on_pushButton_2_clicked()
{
    // Cerrar la ventana actual
    close();

    // Crear una nueva instancia de la ventana y mostrarla
    MainWindow *newWindow = new MainWindow();
    newWindow->show();
}

/**
 * @brief Cierra completamente el programa.
 */
void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

/**
* @brief Ejecutar funcionalidad de Pagos
*/
void MainWindow::on_pushButton_Pagos_clicked()
{
    pagos pg(this);
    pg.exec();
}
