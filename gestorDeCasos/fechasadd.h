#ifndef FECHASADD_H
#define FECHASADD_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QMessageBox>

/**
 * @file fechasadd.h
 *
 * @brief Declara la clase fechasadd y el espacio de nombres Ui.
 */
namespace Ui {
class fechasadd; ///< Declaración anticipada de la clase fechasadd
}

/**
 * @class fechasadd
 *
 * @brief Representa un diálogo de agregado de fechas.
 */
class fechasadd : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construye un objeto fechasadd.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit fechasadd(QWidget *parent = nullptr);
    /**
     * @brief Destruye el objeto fechasadd.
     */
    ~fechasadd();

private slots:
    /**
     * @brief Maneja la señal clicked del botón "pushButton_2".
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_confirmar".
     */
    void on_pushButton_confirmar_clicked();

private:
    Ui::fechasadd *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de fechasadd
};

#endif // FECHASADD_H
