#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"


iniciarsesion::iniciarsesion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::iniciarsesion)
{
    ui->setupUi(this);
}

iniciarsesion::~iniciarsesion()
{
    delete ui;
}

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


void iniciarsesion::on_pushButton_continuar_clicked()
{
    QString username = ui->lineEdit_usuario->text();
    QString password = ui->lineEdit_Contrasena->text();

    if (buscarUsuarioContrasena(username, password)) {
        QMessageBox::information(this, "Inicio de Sesion", "El nombre de usuario y contrasena son correctos");
        hide();
        // aqui se debe escribir el codigo que pase a la pagina principal
    }
    else {
        QMessageBox::information(this, "Inicio de Sesion", "El nombre de usuario y contrasena no son correctos");
    }

}


void iniciarsesion::on_pushButton_Registrarse_clicked()
{
    SingUp = new singup(this);
    SingUp->show();
}

