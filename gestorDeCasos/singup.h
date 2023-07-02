#ifndef SINGUP_H
#define SINGUP_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QMessageBox>

namespace Ui {
class singup;
}

/**
 * @class singup
 * @brief Clase que representa la ventana de registro.
 *
 * Esta clase hereda de QDialog y proporciona funcionalidad para guardar datos de usuario y contraseña en un archivo.
 */
class singup : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase singup.
     * @param parent Puntero al widget padre.
     */
    explicit singup(QWidget *parent = nullptr);

    /**
     * @brief Destructor de la clase singup.
     */
    ~singup();

private slots:
    /**
     * @brief Slot para manejar el evento del botón "Guardar".
     */
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::singup *ui; /**< Puntero a la interfaz de usuario de la ventana de registro. */

};

#endif // SINGUP_H
