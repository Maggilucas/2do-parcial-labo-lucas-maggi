#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"

Jugador* jug_new()
{
	Jugador* pJugador = NULL;

	pJugador = (Jugador*) malloc(sizeof(Jugador));

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	int todoOk=0;
	pJugador = jug_new();

	if(pJugador!=NULL)
	{
		if(jug_setId(pJugador, atoi(idStr)) == 0)
		{
			if(jug_setNombreCompleto(pJugador, nombreCompletoStr) == 0)
			{
				if(jug_setPosicion(pJugador, posicionStr)== 0)
				{
					if(jug_setNacionalidad(pJugador,nacionalidadStr)== 0)
					{
						if(jug_setEdad(pJugador, atoi(edadStr))== 0)
						{
							if(jug_setIdSeleccion(pJugador, atoi(idSelccionStr))== 0)
							{
								todoOk=1;
							}
						}
					}
				}
			}
		}
	}

	if(todoOk != 1)
	{
		pJugador= NULL;
	}

	return pJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

////////////// SETTERS///////////////////////
int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

		if(this != NULL && id > 0)
		{
			this->id = id;
			retorno = 0;
		}

		return retorno;
}
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}

	return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 0;
	}

	return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}

	return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}

	return retorno;
}
/////////// GETTERS/////////////////////////
int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}

	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int BuscarIdJugador(LinkedList* this, int id)
{
	int todoOk = 0;
	int tamanio;
	int idJugador;
	Jugador* auxJugador;
	if(this != NULL && id > 0)
	{
		tamanio = ll_len(this);
		for(int i = 0; i < tamanio; i++)
		{
			auxJugador = (Jugador*)ll_get(this, i);
			if(jug_getId(auxJugador,&idJugador) == 0)
			{
				if(idJugador == id)
				{
					todoOk = i;
					break;
				}
			}

		}
	}

	return todoOk;
}

void MostrarJugador(Jugador* jugador)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if(jugador != NULL)
	{
		if(jug_getId(jugador,&id) == 0)
		{
			if(jug_getNombreCompleto(jugador,nombreCompleto) == 0)
			{
				if(jug_getEdad(jugador,&edad) == 0)
				{
					if(jug_getPosicion(jugador,posicion) == 0)
					{
						if(jug_getNacionalidad(jugador,nacionalidad) == 0)
						{
							if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
							{
								printf("\n%-16d %-25s %-24s %-16d %-25s %d \n",id,nombreCompleto,posicion,edad,nacionalidad,idSeleccion);
							}
						}
					}
				}
			}
		}
	}
}

void MostrarJugadorPais(Jugador* jugador, char* pais)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];

	if(jugador != NULL)
	{
		if(jug_getId(jugador,&id) == 0)
		{
			if(jug_getNombreCompleto(jugador,nombreCompleto) == 0)
			{
				if(jug_getEdad(jugador,&edad) == 0)
				{
					if(jug_getPosicion(jugador,posicion) == 0)
					{
						if(jug_getNacionalidad(jugador,nacionalidad) == 0)
						{

							printf("%-16d %-25s %-24s %-16d %-25s %s \n",id,nombreCompleto,posicion,edad,nacionalidad,pais);

						}
					}
				}
			}
		}
	}
}

int cargarAchivoId()
{
	int todoOk = 0;
	int id;
	FILE* archivo = NULL;
	FILE* AuxArchivo = NULL;
	char idStr[8];

	archivo = fopen("idsincremental.csv","r");
	if(archivo != NULL)
	{
		fscanf(archivo,"%[^\n]\n",idStr);
		todoOk = 1;
		id = atoi(idStr);
	}
	else
	{
		todoOk = 0;
	}
	fclose(archivo);
	if(todoOk == 1)
	{
		AuxArchivo = fopen("idsinclementalAux.csv","w");
		if(AuxArchivo != NULL)
		{
			fprintf(AuxArchivo, "%d",id);
		}
		else
		{
			todoOk = 0;
		}
		fclose(AuxArchivo);
	}
	return todoOk;
}

int cargarIdJugadorArchivo()
{
	int todoOk = 0;
	int id;
	char idStr[30];
	FILE* archivo = NULL;
	FILE* AuxArchivo = NULL;


	archivo = fopen("idsinclementalAux.csv","r");

	if(archivo != NULL)
	{
		fscanf(archivo,"%[^\n]\n",idStr);
		todoOk = 1;

		id = atoi(idStr);
	}
	else
	{
		printf("\nNo entra a la lectura");
	}
	fclose(archivo);
	if(todoOk == 1)
	{
		AuxArchivo = fopen("idsinclemental.csv","w");
		if(AuxArchivo != NULL)
		{
			fprintf(AuxArchivo, "%d",id);
		}
		else
		{
			todoOk = 0;
		}
		fclose(archivo);
	}
	return todoOk;
}


int UltimoId(char* idStr)
{
	int todoOk = 0;
	int id;
	FILE* archivo = NULL;
	FILE* AuxArchivo = NULL;


	archivo = fopen("idsinclementalAux.csv","r");

	if(archivo != NULL)
	{
		fscanf(archivo,"%[^\n]\n",idStr);
		todoOk = 1;

		id = atoi(idStr);
	}
	else
	{
		printf("\nNo entra a la lectura");
	}
	fclose(archivo);
	if(todoOk == 1)
	{
		id++;
		AuxArchivo = fopen("idsinclementalAux.csv","w");
		if(AuxArchivo != NULL)
		{
			fprintf(AuxArchivo, "%d",id);
		}
		else
		{
			todoOk = 0;
		}
		fclose(archivo);
	}
	return todoOk;
}

int ordenarPorNacionalidad(void* jugador1,void* jugador2)
{
	int todoOk = 0;
	Jugador* jugadorUno = (Jugador*)jugador1;
	Jugador* jugadorDos = (Jugador*)jugador2;
	char nacionalidadUno[30];
	char nacionalidadDos[30];
	if(jug_getNacionalidad(jugadorUno,nacionalidadUno) == 0)
	{
		if(jug_getNacionalidad(jugadorDos,nacionalidadDos) == 0)
		{
			if(stricmp(nacionalidadUno,nacionalidadDos) > 0)
			{
				todoOk = 1;
			}
			else
			{
				if(stricmp(nacionalidadUno,nacionalidadDos) < 0)
				{
					todoOk = -1;
				}
			}
		}
	}
	return todoOk;
}

int ordenarPorEdad(void* jugador1,void* jugador2)
{
	int todoOk = 0;
	Jugador* jugadorUno = (Jugador*)jugador1;
	Jugador* jugadorDos = (Jugador*)jugador2;
	int edadUno;
	int edadDos;
	if(jug_getEdad(jugadorUno,&edadUno) == 0)
	{
		if(jug_getEdad(jugadorDos,&edadDos) == 0)
		{
			if(edadUno > edadDos)
			{
				todoOk = 1;
			}
			else
			{
				if(edadUno < edadDos)
				{
					todoOk = -1;
				}
			}
		}
	}
	return todoOk;
}

int ordenarPorNombre(void* jugador1,void* jugador2)
{
	int todoOk = 0;
	Jugador* jugadorUno = (Jugador*)jugador1;
	Jugador* jugadorDos = (Jugador*)jugador2;
	char nombreUno[100];
	char nombreDos[100];
	if(jug_getNombreCompleto(jugadorUno,nombreUno) == 0)
	{
		if(jug_getNombreCompleto(jugadorDos,nombreDos) == 0)
		{
			if(stricmp(nombreUno,nombreDos) > 0)
			{
				todoOk = 1;
			}
			else
			{
				if(stricmp(nombreUno,nombreDos) < 0)
				{
					todoOk = -1;
				}
			}
		}
	}
	return todoOk;
}

int ListarConvocados(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int idSeleccion;
	int cantidad;
	Jugador* jugador;
	cantidad = ll_len(pArrayListJugador);
	for(int i = 0; i<cantidad;i++)
	{
		jugador = (Jugador*) ll_get(pArrayListJugador, i);
		if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
		{
			if(idSeleccion != 0)
			{
				MostrarJugador(jugador);
				todoOk = 1;
			}
		}

	}
	return todoOk;
}
