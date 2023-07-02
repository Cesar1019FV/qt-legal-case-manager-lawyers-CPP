#include "iniciarsesion.h"
#include "singup.h"
#include <QApplication>

/**
 * @brief Punto de entrada principal del programa.
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Arreglo de cadenas de caracteres que representan los argumentos de la línea de comandos.
 * @return Código de salida del programa.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); /**< Objeto de aplicación Qt. */
    a.setStyle("fusion");
    iniciarsesion w; /**< Objeto de la clase iniciarsesion. */
    w.show(); /**< Mostrar la ventana de inicio de sesión. */

    return a.exec(); /**< Ejecutar el ciclo de eventos de la aplicación. */
}
