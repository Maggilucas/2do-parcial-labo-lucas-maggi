#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	Jugador* jugadores;
	char id[30];
	char nombreCompleto[100];
	char edad[3];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[30];
	if(pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion)== 6)
			{
				jugadores = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

				if(jugadores != NULL)
				{
					ll_add(pArrayListJugador, jugadores);
					todoOk = 1;
				}
			}

		}while(!feof(pFile));
	}

    return todoOk;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListConvocados)
{
	int todoOk = 0;
	if(pFile != NULL)
	{
		if(pArrayListConvocados!= NULL)
		{
			while(1)
			{
				Jugador* jugador = jug_new();
				if(jugador != NULL)
				{
					if(fread(jugador, sizeof(Jugador), 1, pFile) != 0)
					{
						ll_add(pArrayListConvocados, jugador);

					}

					todoOk = 1;
				}
				if(feof(pFile) != 0)
				{
					break;
				}
			}
		}
	}
    return todoOk;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	Seleccion* seleccion;
	char id[30];
	char pais[30];
	char confederacion[30];
	char convocados[30];
	if(pArrayListSeleccion != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados)== 4)
			{
				seleccion = selec_newParametros(id,pais, confederacion, convocados);

				if( seleccion!= NULL)
				{
					ll_add(pArrayListSeleccion, seleccion);
					todoOk = 1;
				}
			}

		}while(!feof(pFile));
	}

    return todoOk;
}

