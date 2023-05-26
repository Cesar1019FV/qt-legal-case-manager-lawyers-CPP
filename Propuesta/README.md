# Propuesta de proyecto final (APP DESKTOP)
En este archivo README se presenta la propuesta para el proyecto final del curso, donde se muestra la estructura de un software de gestión de casos.

## Pag 1. Inicio de sesión:
Esta es la página inicial, es un inicio de sesión común y corriente que solicita el nombre de usuario y la contraseña del cliente. También incluye una sección para enviar a la página de registro en caso de que el usuario no esté registrado aún en la plataforma. Además, hay un botón de inicio de sesión que verificará en la base de datos local si el usuario existe.

## Pag 2. Registro:
Si el usuario decide ir a la página de registro, encontrará un formulario que solicita el nombre de usuario, un correo electrónico válido, una contraseña y una confirmación de la contraseña. Al final, hay un botón que enviará los datos a la base de datos local y se podrá acceder desde la página de inicio de sesión.

## Pag 3. Home:
En esta página principal, se encuentra un encabezado que da la bienvenida al usuario. Al lado, hay dos botones para "Fechas" y "To-do List" (lista de tareas pendientes), que redirigirán al usuario a sus respectivas páginas. Más abajo, hay una sección llamada "Mis Casos". Aquí se encuentran tres botones para "Nuevo caso", "Editar" y "Eliminar caso", que llevarán a páginas específicas para modificar los casos de la página Home. Luego, se muestra un cuadro donde se ordenan y muestran de manera organizada los detalles principales de cada caso: una breve descripción, el delito relacionado, el demandado, el demandante, el expediente judicial y el estado del caso, que puede ser "En proceso" o "Finalizado".

## Pag 4. Nuevo Caso:
Esta página se abre al accionar el widget de "nuevo caso" en la página principal (Home). Aquí se solicitan las mismas características del caso que se muestran en la página Home, excepto el estado del caso, que se establece automáticamente como "En proceso". Sin embargo, el usuario puede modificarlo en cualquier momento. Al final, hay dos botones para confirmar y uno para cancelar.

## Pag 5. Editar Caso:
En esta sección, se le solicita al usuario seleccionar el caso que desea editar. Una vez seleccionado, se le da la posibilidad de modificar cada campo que se muestra en la sección de Home de cada caso. Ahora también se puede actualizar el estado del caso a "Finalizado". Al final, hay dos botones para confirmar y uno para cancelar la edición.

## Pag 6. Eliminar Caso:
En esta página simple, hay un botón que permite al usuario seleccionar entre todos los casos que tiene. En caso de no haber casos, se le informa al usuario que no hay disponibles. Una vez seleccionado un caso, hay dos botones básicos para confirmar y cancelar la acción. Si se confirma, el caso se eliminará de la base de datos local y no se mostrará en la página principal (Home).

## Pag 7. Fechas pendientes:
Cuando se selecciona el botón de "fechas", se abre una nueva página que muestra primero una sección llamada "Mis fechas pendientes". Aquí se muestra una lista similar a la de Home, pero con detalles adicionales: motivo de la fecha, fecha, hora y lugar asociado al caso relacionado. Esta página se crea principalmente como un método para tener todas las fechas organizadas en un solo lugar, ordenadas de la más reciente a la que falta más tiempo. Esto permite al abogado tener un registro de las fechas de juicios que se llevarán a cabo de manera presencial en una determinada corte.

## Pag 8. Nueva fecha:
Esta sección funciona de manera similar a "nuevo caso". Aquí se solicitan el motivo, la fecha, la hora, el lugar y el caso relacionado. También se solicita obligatoriamente que se envíen los datos de la fecha y la hora al usuario para llevar un registro correcto. Al final, hay dos botones para confirmar y uno para cancelar la acción de agregar una nueva fecha.

## Pag 9. Editar fecha:
Esta sección es similar a "nueva fecha", pero ahora el usuario debe seleccionar la fecha que desea editar. En esta sección, no hay campos obligatorios por completar, lo que le da total libertad al usuario. Al final, hay dos botones para confirmar y uno para cancelar la acción.

## Pag 10. Eliminar fecha:
En esta página simple, se muestra un selector de fechas al usuario, donde puede seleccionar una fecha y luego elegir entre los botones de confirmar y cancelar. Esta opción permite eliminar las fechas pasadas que no son relevantes y simplifica la interfaz.

## Pag 11. To-do List (lista de tareas pendientes):
Esta sección permite al usuario administrar sus tareas pendientes. Los abogados constantemente realizan diversas tareas, como estudiar casos, analizar pruebas, hacer llamadas comerciales y consultas con los clientes, redactar demandas y respuestas oficiales, etc.

En esta sección, los usuarios pueden organizar sus tareas pendientes. Al abrir la página, se muestra una lista de tareas pendientes. Se evita sobrecargar al usuario con columnas adicionales y detalles específicos, ya que las tareas pueden variar mucho y esto puede generar confusión al crear una nueva tarea pendiente. Por último, hay tres botones que se han mencionado en todas las secciones: añadir nueva tarea pendiente, editar tarea pendiente y eliminar tarea pendiente.

## Pag 12. Nuevo pendiente:
En esta sección, se solicita al usuario la información necesaria para agregar una nueva tarea pendiente a la lista. En este caso, solo se requiere el motivo como campo obligatorio. También se incluyen los dos botones mencionados anteriormente: confirmar y cancelar la acción.

## Pag 13. Editar pendiente:
Esta sección solicita datos similares a "nuevo pendiente". Sin embargo, se le pide al usuario que seleccione una tarea pendiente de una lista. Una vez seleccionada una tarea, se permite modificar el motivo y se incluyen los botones de confirmar y cancelar la acción.

## Pag 14. Eliminar pendiente:
En esta página, se permite al usuario seleccionar entre todas sus tareas pendientes previamente agregadas. De esta forma, puede confirmar o cancelar la acción de eliminar una tarea. Si se confirma, la tarea seleccionada se eliminará automáticamente.