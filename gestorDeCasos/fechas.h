#ifndef FECHAS_H
#define FECHAS_H

#include <QDialog>
#include <QStandardPaths>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
/**
 * @file fechas.h
 *
 * @brief Declara la clase fechas y el espacio de nombres Ui.
 */
namespace Ui {
class fechas; ///< Declaración anticipada de la clase fechas
}
/**
 * @class fechas
 *
 * @brief Representa un diálogo de gestión de fechas.
 */
class fechas : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construye un objeto fechas.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit fechas(QWidget *parent = nullptr);

    /**
     * @brief Destruye el objeto fechas.
     */
    ~fechas();

private slots:
    /**
     * @brief Maneja la señal clicked del botón "pushButton_Salir".
     */
    void on_pushButton_Salir_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_eliminar".
     */
    void on_pushButton_eliminar_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_nueva".
     */
    void on_pushButton_nueva_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_actualizar".
     */
    void on_pushButton_actualizar_clicked();

private:
    Ui::fechas *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de fechas
};

#endif // FECHAS_H
