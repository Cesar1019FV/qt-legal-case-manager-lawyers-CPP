#ifndef TODOLIST_H
#define TODOLIST_H

#include <QDialog>
#include <QStandardPaths>
#include <QFile>
#include <QMessageBox>

/**
 * @file toDoList.h
 *
 * @brief Declara la clase toDoList y el espacio de nombres Ui.
 */

namespace Ui {
class toDoList; ///< Declaración anticipada de la clase toDoList
}

/**
 * @class toDoList
 *
 * @brief Representa un diálogo de lista de tareas pendientes.
 */
class toDoList : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construye un objeto toDoList.
     *
     * @param parent El widget padre (por defecto: nullptr).
     */
    explicit toDoList(QWidget *parent = nullptr);

    /**
     * @brief Destruye el objeto toDoList.
     */
    ~toDoList();

private slots:
    /**
     * @brief Maneja la señal clicked del botón "pushButton_ToDo".
     */
    void on_pushButton_ToDo_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_EliminarToDo".
     */
    void on_pushButton_EliminarToDo_clicked();

    /**
     * @brief Maneja la señal clicked del botón "pushButton_EliminarToDoAll".
     */
    void on_pushButton_EliminarToDoAll_clicked();

    void on_pushButton_Actualizar_clicked();

    void on_pushButton_Cerrar_clicked();

private:
    Ui::toDoList *ui; ///< Puntero a la instancia de la interfaz de usuario (UI) de toDoList
};


#endif // TODOLIST_H
