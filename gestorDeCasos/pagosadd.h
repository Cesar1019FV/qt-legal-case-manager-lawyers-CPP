#ifndef PAGOSADD_H
#define PAGOSADD_H

#include <QDialog>
#include <QStandardPaths>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

/**
 * @file pagosadd.h
 *
 * @brief Declara la clase pagosadd y el espacio de nombres Ui.
 */

namespace Ui {
class pagosadd; ///< Declaración anticipada de la clase pagosadd
}

/**
 * @class pagosadd
 *
 * @brief Representa un diálogo de agregado de pagos.
 */
class pagosadd : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construye un objeto pagosadd.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit pagosadd(QWidget *parent = nullptr);

    /**
     * @brief Destruye el objeto pagosadd.
     */
    ~pagosadd();

private slots:
    /**
     * @brief Maneja la señal clicked del botón "pushButton_Cancel".
     */
    void on_pushButton_Cancel_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_Confirm".
     */
    void on_pushButton_Confirm_clicked();

private:
    Ui::pagosadd *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de pagosadd
};


#endif // PAGOSADD_H
