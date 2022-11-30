///
///
/// @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
///
/// @param path
/// @param pArrayListJugador
/// @return
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);


/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
///
/// @param path
/// @param pArrayListJugador
/// @return
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Alta de jugadores carga los datos y agrega jugadores
///
/// @param pArrayListJugador
/// @return
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// @brief edita los datos de jugadores cargados
///
/// @param pArrayListJugador
/// @return
int controller_editarJugador(LinkedList* pArrayListJugador);
/// @brief elimina un jugador cargado
///
/// @param pArrayListJugador
/// @return
int controller_removerJugador(LinkedList* pArrayListJugador);

/// @brief lista los jugadores cargados
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// @brief ordena los jugadores por distintos cricterios
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
///
/// @param path
/// @param pArrayListJugador
/// @return
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Guarda los datos de los jugadores en el archivo binario.
///
/// @param path
/// @param pArrayListJugador
/// @return
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de las selecciones desde el archivo jugadores.csv (modo texto).
///
/// @param path
/// @param pArrayListSeleccion
/// @return
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// @brief lista las selecciones cargadas
///
/// @param pArrayListSeleccion
/// @return
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
/// @brief ordena las selecciones por distintos cricterios
///
/// @param pArrayListSeleccion
/// @return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Guarda los datos de las selecciones en el archivo jugadores.csv (modo texto).
///
/// @param path
/// @param pArrayListSeleccion
/// @return
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/// @brief lista todos los jugadores,selecciones y convocados
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_ListarTodo(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief asigna o borra como convocado un jugador
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_convocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief asigna como convocado un jugador
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_altaConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief borra a un convocado y lo deja como no convocado
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_bajaConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief genera un archivo binario de convocados
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return
int controller_generarBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
