#include "todolist.h"
#include "ui_todolist.h"
#include "todoadd.h"

/**
 * @brief Función para limpiar el contenido de un archivo.
 * @param filePath Ruta del archivo que se desea limpiar.
 */
void clearFile(const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << "";
        file.close();
    }
}

/**
 * @brief Constructor de la clase toDoList.
 * @param parent Puntero al widget padre.
 */
toDoList::toDoList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::toDoList)
{
    ui->setupUi(this);
    setWindowTitle("Lista de tareas por hacer");

    // Abrir el archivo toDoList.txt en modo lectura y escritura
    QFile files(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoList.txt");

    if (!files.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", files.errorString());
    }

    QTextStream in(&files);

    // Leer el contenido del archivo línea por línea y agregarlo al listWidget
    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget_ToDo);
        ui->listWidget_ToDo->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
    files.close();
}

toDoList::~toDoList()
{
    delete ui;

    // Abrir el archivo toDoList.txt en modo lectura y escritura
    QFile files(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoList.txt");

    if (!files.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", files.errorString());
    }

    QTextStream out(&files);

    // Guardar el contenido del listWidget en el archivo
    for (int i = 0; i < ui->listWidget_ToDo->count(); ++i){
        out << ui->listWidget_ToDo->item(i)->text() << "\n";
    }
    files.close();
}

/**
 * @brief Slot para manejar el evento del botón "Agregar tarea".
 */
void toDoList::on_pushButton_ToDo_clicked()
{

    todoadd tda(this);
    tda.exec();
}

/**
 * @brief Slot para manejar el evento del botón "Eliminar tarea".
 */
void toDoList::on_pushButton_EliminarToDo_clicked()
{
    // Eliminar la línea seleccionada del listWidget
    QListWidgetItem* item = ui->listWidget_ToDo->takeItem(ui->listWidget_ToDo->currentRow());
    QString itemText = item->text();
    delete item;

    // Eliminar la línea correspondiente del archivo
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoList.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        QStringList lines;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (line != itemText) {
                lines << line;
            }
        }
        file.resize(0);
        for (const QString& line : lines) {
            stream << line << "\n";
        }
        file.close();
    }
}

/**
 * @brief Slot para manejar el evento del botón "Eliminar todas las tareas".
 */
void toDoList::on_pushButton_EliminarToDoAll_clicked()
{
    // Limpiar el listWidget y vaciar el archivo toDoList.txt
    ui->listWidget_ToDo->clear();
    clearFile(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoList.txt");
}



/**
 * @brief Slot para manejar el evento del botón "Actualizar".
 */
void toDoList::on_pushButton_Actualizar_clicked()
{
    // Cerrar la ventana actual
    close();

    // Crear una nueva instancia de la ventana y mostrarla
    toDoList *newToDo = new toDoList();
    newToDo->show();
}

/**
 * @brief Slot para manejar el evento del botón "Cerrar".
 */
void toDoList::on_pushButton_Cerrar_clicked()
{
    hide();
}

