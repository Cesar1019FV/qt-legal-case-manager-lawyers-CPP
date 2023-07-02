#ifndef PAGOS_H
#define PAGOS_H

#include <QDialog>
#include <QStandardPaths>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

/**
 * @file pagos.h
 *
 * @brief Declara la clase pagos y el espacio de nombres Ui.
 */

namespace Ui {
class pagos; ///< Declaración anticipada de la clase pagos
}

/**
 * @class pagos
 *
 * @brief Representa un diálogo de gestión de pagos.
 */
class pagos : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Construye un objeto pagos.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit pagos(QWidget *parent = nullptr);

    /**
     * @brief Destruye el objeto pagos.
     */
    ~pagos();

private slots:

    /**
     * @brief Maneja la señal clicked del botón "pushButton_anadir".
     */
    void on_pushButton_anadir_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_Borrar".
     */
    void on_pushButton_Borrar_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_3".
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_Salir".
     */
    void on_pushButton_Salir_clicked();

private:
    Ui::pagos *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de pagos
};


#endif // PAGOS_H
