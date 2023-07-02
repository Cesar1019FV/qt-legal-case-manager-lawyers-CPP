#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "singup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class iniciarsesion; }
QT_END_NAMESPACE

/**
 * @class iniciarsesion
 * @brief Clase que representa la ventana de inicio de sesión.
 *
 * Esta clase hereda de QDialog y proporciona funcionalidad para iniciar sesión, buscar usuarios y contraseñas en un archivo,
 * y navegar a la página de registro.
 */
class iniciarsesion : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase iniciarsesion.
     * @param parent Puntero al widget padre.
     */
    iniciarsesion(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase iniciarsesion.
     */
    ~iniciarsesion();

private slots:
    /**
     * @brief Slot para manejar el evento del botón "Continuar".
     */
    void on_pushButton_continuar_clicked();

    /**
     * @brief Slot para manejar el evento del botón "Registrarse".
     */
    void on_pushButton_Registrarse_clicked();

    /**
     * @brief Slot para manejar el evento del botón "Salir".
     */
    void on_pushButton_salir_clicked();

private:
    Ui::iniciarsesion *ui; /**< Puntero a la interfaz de usuario de la ventana de inicio de sesión. */
    singup *SingUp; /**< Puntero a la ventana de registro. */
};

#endif // INICIARSESION_H
