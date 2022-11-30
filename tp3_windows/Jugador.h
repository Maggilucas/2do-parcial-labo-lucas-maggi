#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/// @brief pide espacio en memoria
///
/// @return
Jugador* jug_new();

/// @brief setea los valores de los jugadores
///
/// @param idStr
/// @param nombreCompletoStr
/// @param edadStr
/// @param posicionStr
/// @param nacionalidadStr
/// @param idSelccionStr
/// @return
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/// @brief elimina el espacio en memoria de un jugador
///
/// @param this
void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int BuscarIdJugador(LinkedList* this, int id);
void MostrarJugador(Jugador* jugador);
void MostrarJugadorPais(Jugador* jugador, char* pais);
int cargarAchivoId();
int cargarIdJugadorArchivo();
int UltimoId(char* idStr);
int ListarConvocados(LinkedList* pArrayListJugador);

int ordenarPorNacionalidad(void* jugador1,void* jugador2);
int ordenarPorEdad(void* jugador1,void* jugador2);
int ordenarPorNombre(void* jugador1,void* jugador2);

#endif // jug_H_INCLUDED
