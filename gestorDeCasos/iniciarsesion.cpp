/**
 * @file iniciarsesion.h
 * @brief This file contains the definition of the iniciarsesion class.
 */

#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"

/**
 * @brief Constructor de la clase iniciarsesion.
 * @param parent Puntero al widget padre.
 */
iniciarsesion::iniciarsesion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::iniciarsesion)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor de la clase iniciarsesion.
 */
iniciarsesion::~iniciarsesion()
{
    delete ui;
}

/**
 * @brief Función para buscar un usuario y contraseña en un archivo.
 * @param usuario El nombre de usuario a buscar.
 * @param contrasena La contraseña a buscar.
 * @return Devuelve true si se encontró el usuario y contraseña, false en caso contrario.
 */
bool buscarUsuarioContrasena(const QString& usuario, const QString& contrasena) {
    QFile archivo(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "//usuarios.txt");

    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&archivo);
        while (!stream.atEnd()) {
            QString linea = stream.readLine();
            QStringList datos = linea.split(",");
            if (datos.size() == 2) {
                QString usuarioArchivo = datos.at(0);
                QString contrasenaArchivo = datos.at(1);
                if (usuario == usuarioArchivo && contrasena == contrasenaArchivo) {
                    archivo.close();
                    qDebug() << "Usuario y contraseña encontrados en el archivo.";
                    return true;
                }
            }
        }
        archivo.close();
        qDebug() << "Usuario y contraseña no encontrados en el archivo.";
    } else {
        qDebug() << "Error al abrir el archivo.";
    }

    return false;
}

/**
 * @brief Slot para manejar el evento del botón "Continuar".
 */
void iniciarsesion::on_pushButton_continuar_clicked()
{
    QString username = ui->lineEdit_usuario->text();
    QString password = ui->lineEdit_Contrasena->text();

    if (buscarUsuarioContrasena(username, password)) {
        QMessageBox::information(this, "Inicio de Sesion", "El nombre de usuario y contraseña son correctos");
        hide();
        // aquí se debe escribir el código para navegar a la página principal
    }
    else {
        QMessageBox::information(this, "Inicio de Sesion", "El nombre de usuario y contraseña no son correctos");
    }
}

/**
 * @brief Slot para manejar el evento del botón "Registrarse".
 */
void iniciarsesion::on_pushButton_Registrarse_clicked()
{
    SingUp = new singup(this);
    SingUp->show();
}
