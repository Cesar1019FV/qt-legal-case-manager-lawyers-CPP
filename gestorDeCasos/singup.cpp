#include "singup.h"
#include "ui_singup.h"

/**
 * @brief Constructor de la clase singup.
 * @param parent Puntero al widget padre.
 */
singup::singup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singup)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor de la clase singup.
 */
singup::~singup()
{
    delete ui;
}

/**
 * @brief Slot para manejar el evento del botón "Guardar".
 */
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
