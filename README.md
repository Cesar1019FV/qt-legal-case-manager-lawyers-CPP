# proyectoFinal-IE0217-2023-Ciclo1
En este repositorio se alojará el proyecto final del curso de Estructuras abstractas de datos y algoritmos del estudiante César Andrés Fonseca Villegas de carnet C12959

## Funcionamiento general de la aplicación
La presente aplicación es un gestor de casos para abogados, la razón para escoger esta propuesta de aplicación es para facilitarle a los abogados el poder administrar los casos que tienen en proceso, además de poder administrar de mejor manera las fechas pendientes para juicos, audiencias, etc, facilitarles el manejo de tareas pendientes, ya sea realización de escritos, citas con clientes, presentación de demandas, o cualquier otra actividad que necesiten realizar, ademas que también se busca facilitarles administrar las cuotas y las deudas de los clientes, para verificar cuales clientes no hayan realizado los pagos completos o revisar que clientes ya cancelaron todas sus cuotas de pago.

## Inicio de sesión y registro de usuarios
Una vez se inicia la aplicación, se despliega la primera ventana la cual es del inicio de sesión, en esta ventana se nos solicitarán dos datos, los cuales son Usuario, y Contraseña del usuario, los cuales en un archivo txt verificará su existencia, en caso de no existir estos datos en el archivo, imprimirá el mensaje "El nombre de usuario y contraseña no son correctos", y en caso de ser correctos, imprimirá que los datos son validos y le permitirá al usuario acceder a la siguiente ventana. 

![img inicio de sesion](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/iniciosesion.jpg)

Ademas de esto, también hay presentes tres botones funcionales, los cuales son los de "Salir", que cierra completamente el programa, el botón "Continuar" que realiza la verificación de los datos del inicio de sesión para enviarlo a la siguiente pagina, y por ultimo el botón de "Registrarse" el cual envía a una segunda ventana al usuario el cual le solicita el nombre de usuario y la contraseña al usuario, acompañado de un botón de confirmar y un botón de cancelar, estos para cumplir la funcion de cancelar o añadir los datos al archivo txt

![registro](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/registro.jpg)

## Pagina principal
Explicando la fución principal de esta ventana, esta ventana está especializada para administrar los casos en su forma más fundamental, en esta ventana se muestran los casos activos ingresados por el usuario, los cuales se muestran en un TableWidget  los cuales se dividen en "Caso" donde se coloca un nombre identificador para el caso, "Delito", "demandado", "demandante y "expediente", estos datos son fundamentales cuando se realiza un proceso judicial, esto debido a que en el encabezado de cada escrito, demanda, o contestación, se debe por protocolo judicial, colocar estos datos, ya que con estos se almacenan y se identifican los distintos casos, por lo que el tenerlos a la mano es fundamental, ya que estos datos suelen en estar expedientes que pueden exeder las 500 paginas, y esto les deja de manera muy simple acceder a estos datos de uso diario en cada caso.

![pagina principal](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/pagina%20principal.jpg)

Se presentan cuatro botones principales, el de "eliminar", el cual se encarga de eliminar algun caso seleccionado por el usuario de forma bastante simple, el botón "actualizar", este botón se agregó para facilitar el desarrollo y presionarlo cada vez que se agregue un nuevo caso, este aparezca en la tabla, "salir" para cerrar el programa por completo, y por ultimo se presenta el botón de "Nuevo Caso", este botón abre una nueva ventana, que pide cada uno de los datos de la tabla mencionados anteriormente, con dos botones para confirmar o cancelar los datos para que se agreguen a el archivo txt y se muestren en la tabla una vez se actualice.

![nuevo caso](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/nuevo%20caso.jpg) 

## To do List
Esta es la sección de Lista de tareas por hacer, en esta sección se muestra una ventana simple, en esta ventana se mostrarán anotaciones que haga el usuario, se muestra una linea en la cual puede escribir su anotación o tarea, y con el botón "añadir" esta automaticamente se añadirá a la tabla presente en la ventana, el usuario tendrá la posibilidad de ediatr la nota haciendo doble click sobre esta, además que tendrá dos botones de "eliminar" y "eliminar todo", los cuales eliminarán de forma permanente cada anotación realizada en la tabla.

![to do list ](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/toDoList.jpg) 

## Fechas
En esta sección se despliega una ventana similar al de la ventana principal, sin embargo, en esta ventana se despliegan las fechas pendientes, esta sección se debe a una necesidad de almancenar de manera ordenada los juicios, audiencias, fechas limites, etc, que en la profesión de derecho, es necesario tenerlas claras y a mano, esto debido a que estas suelen envarse en un correo de notificaciones el cual no se vuelve a enviar más, y esta correo puede llegar incluso un año antes de que la fecha limite se cumpla o la fecha del juicio se realice, por lo que esta sección permite al abogado almancenar todas estas fechas importantes en un solo lugar y en un formato facil de leer.

![fechas](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/fechas.jpg)

Se muestra una tabla que almacena el "motivo" y la "fecha y hora", en formato am y pm, ademas de haber cuatro botones principañes, el de "eliminar fecha" que funciona de igual forma que el de eliminar caso de la ventana principal, el de "actualizar" que también funciona de la misma manera, y el botón de "nueva fecha", el cual despliegra una ventana el cual solicita al usuario los dos datos de la tabla para luego al actualizar, imprimirlos en esta, y el botón de salir de la ventana.

![img nueva fecha](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/nuevaFecha.jpg) 

## Pagos
Esta es una ventana la cual se despliega y se utiliza para administrar los pagos de clientes, esta ventana no tiene la función se cobrarle a los clientes, sino de llevar un registro de los pagos, las cuotas, y las deudas de los clientes, esto debido a que muchos de los trabajos realizados en derecho, pueden rozar cantidades altas de dinero de inclusio hasta medio millon de colones o más, así que muchas veces se hace que los clientes paguen en tractos para suavizar el gasto, por lo que en esta sección se podría almacenar los montos abonados, el monto adeudado, y el nombre del cliente, ademas de que hace un calculo del monto pendiente en base a los datos recibidos.

![img pagos](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/pagos.jpg) 


Se muestran cuatro botones principales en la ventana, el botón de "borrar" el cual funciona de la misma manera que los anteriores, "actualizar" que sirve igualmente para mostrar los nuevos datos añadidos, el botón de "Salir" el cual cierra la ventana de pagos, y por ultimo el botón de "añadir" el cual despliega una ventana el cual solicita los datos principales para llenar la tabla y así almacenar los datos.

 ![img añadir](https://github.com/Cesar1019FV/proyectoFinal-IE0217-2023-Ciclo1/blob/main/img/a%C3%B1adirpago.jpg) 

## Como ejecutar el programa

### Requisitos de ejecución
La manera de ejecutar el programa es bastante simple, sin embargo se requieren ciertos requisitos antes de ejecutarlo, el primer requisito es tener instalado Qt en el dispositivo donde va a compilar el programa, y junto con este debe estar completamente instalado qmake, el cual es un elemento de Qt, y ademas se debe aclarar que este programa fue programado, debugueado, y probado en Qt 6.5.1, por lo que para evitar errores de versión, se recomienda actualizar el programa en caso de tener una versión anterior.

### Ejecutar
Una vez cumplidos esos requisitos se puede proceder a ejecutar el programa de la siguiente manera:

- Primero deberá clonar el repositorio en una carpeta
- Una vez clonado deberá abrir la terminal de Qt llamada "Qt 6.5.1 (MinGW 11.2.0 64-bit)" en windows, esta normalmente viene instalada junto con Qt 6.5.1, igual servirá con terminales de versiones superiores
- en esta terminal se deberá ubicar en la carpeta llamada "gestorDeCasos" del repo que clonó
- una vez ubicado en la carpeta deberá ejecutar el comando en la terminal *mingw32-make -f Makefile.Main*, una vez ejecutado se compilará el programa, se generaran las dependencias, se generará la documentacion Doxygen, y se abrirá tanto la documentación en el navegador, como el programa.

## License
This work is licensed under a [Creative Commons Attribution 4.0 International License][cc-by].