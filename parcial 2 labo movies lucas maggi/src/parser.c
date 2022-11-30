#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "parser.h"
#include "movies.h"
#include "validaciones.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_loadFile(FILE* pFile, LinkedList* movieList)
{
	int todoOk = 0;
	eMovie* peliculas;
	char id[30];
	char titulo[100];
	char genero[30];
	char duracion[30];

	if(movieList != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, genero, duracion);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, genero, duracion)== 4)
			{
				peliculas = movie_newParam(id, titulo, genero, duracion);

				if(peliculas != NULL)
				{
					ll_add(movieList, peliculas);
					todoOk = 1;
				}
			}

		}while(!feof(pFile));
	}

	return todoOk;
}
int parser_saveFile(FILE* pFile, LinkedList* movieList)
{
    int retorno = 0;
    char encabezado [50]="id_peli,titulo,genero,duracion\n";
    int len;
    eMovie* auxMovie = NULL;
    int id;
    char genero[50];
    char titulo[50];
    int duracion;
    if (pFile != NULL && movieList != NULL)
    {
        fprintf(pFile,encabezado);
        len = ll_len(movieList);
        for (int i = 0; i < len; i++)
        {
            auxMovie = (eMovie*)ll_get(movieList,i);
            if( (mov_getId(auxMovie,&id) && mov_getTitulo(auxMovie,titulo) && mov_getGenero(auxMovie,genero) && mov_getDuracion(auxMovie,&duracion)))
            {
                fprintf(pFile,"%d,%s,%s,%d\n",id,titulo,genero,duracion);
                retorno ++;
            }
            else
            {
                printf("Hubo algun error en la carga de informacion");
                break;
            }
        }
    }
    return retorno;
}
