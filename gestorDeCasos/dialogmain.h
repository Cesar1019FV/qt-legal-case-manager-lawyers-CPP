#ifndef DIALOGMAIN_H
#define DIALOGMAIN_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QStandardPaths>

/**
 * @file dialogmain.h
 *
 * @brief Declara la clase DialogMain y el espacio de nombres Ui.
 */

namespace Ui {
class DialogMain; ///< Declaración anticipada de la clase DialogMain
}

/**
 * @class DialogMain
 *
 * @brief Representa un diálogo principal de la aplicación.
 */
class DialogMain : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construye un objeto DialogMain.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit DialogMain(QWidget *parent = nullptr);
    /**
     * @brief Destruye el objeto DialogMain.
     */
    ~DialogMain();

    /**
     * @brief Obtiene los datos proporcionados a la tabla principal.
     *
     * @return los datos como QString.
     */
    QString caso() const;
    QString delito() const;
    QString demandado() const;
    QString demandante() const;
    QString expediente() const;

private slots:
    /**
     * @brief Maneja la señal accepted del cuadro de botones (buttonBox).
     */
    void on_buttonBox_accepted();
    /**
     * @brief Maneja la señal rejected del cuadro de botones (buttonBox).
     */
    void on_buttonBox_rejected();

private:
    Ui::DialogMain *ui;
};

#endif // DIALOGMAIN_H
