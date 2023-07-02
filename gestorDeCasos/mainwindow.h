#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

/**
 * @file mainwindow.h
 *
 * @brief Declara la clase MainWindow y el espacio de nombres Ui.
 */
namespace Ui {
class MainWindow;
}

/**
 * @class MainWindow
 *
 * @brief Representa la ventana principal de la aplicación.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Construye un objeto MainWindow.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruye el objeto MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Maneja la señal clicked del botón "nuevoCasoBottom".
     */
    void on_nuevoCasoBottom_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton".
     */
    void on_pushButton_clicked();

    /**
     * @brief Maneja la señal clicked del botón "fechasBT".
     */
    void on_fechasBT_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_eliminar".
     */
    void on_pushButton_eliminar_clicked();
    /**
     * @brief Maneja la señal clicked del botón "pushButton_2".
     */
    void on_pushButton_2_clicked();
    /**
     * @brief Maneja la señal clicked del botón "pushButton_3".
     */
    void on_pushButton_3_clicked();
    /**
     * @brief Maneja la señal clicked del botón "pushButton_Pagos".
     */
    void on_pushButton_Pagos_clicked();

private:
    Ui::MainWindow *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de MainWindow
};

#endif // MAINWINDOW_H
