#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menus.h"
#include "LinkedList.h"
#include "parser.h"
#include "movies.h"
#include "validaciones.h"
#include "controller.h"

int controller_loadFile(char* path,LinkedList* movieList)
{
	int todoOk = -1;
	FILE* pArchivo;

	if(path!=NULL && movieList!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL && path != NULL)
		{
			if(parser_loadFile(pArchivo, movieList)== 1)
			{
				printf("Se cargo con exito\n");
				todoOk=1;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}
	return todoOk;
}

int controller_saveFile(char* path,LinkedList* movieList)
{
    int retorno = 0;
    int saveOk = 0;
    FILE* f = NULL;
    if(path != NULL && movieList != NULL)
    {
        f = fopen(path,"w");
        if (f != NULL)
        {
            saveOk = parser_saveFile(f,movieList);
            if (saveOk >0)
            {
                printf("Se guardaron correctamente %d peliculas\n",saveOk);
            }
        }
        fclose(f);
    }
    return retorno;
}
int controller_printList(LinkedList* movieList)
{
    int retorno = 0;
    int showOk = 0;
    if (movieList != NULL)
    {
        showOk = mostrarPeliculas(movieList);
        if(showOk > 0)
        {
            printf("\n\nSe mostraron un total de %d peliculas.\n",showOk);
            retorno = 1;
        }
    }
    return retorno;
}
int controller_setDuracion(LinkedList* movieList,LinkedList** movieListRating)
{
    int retorno = 0;
    LinkedList* aux;
    if (movieList != NULL && movieListRating != NULL)
    {
        *movieListRating = ll_map(movieList,movie_mapDuracion);
        mostrarPeliculas(*movieListRating);
    	aux= ll_clone(*movieListRating);
    	movieList=aux;
    	ll_deleteLinkedList(aux);
        retorno = 1;
    }
    return retorno;
}
int controller_filterGenero(LinkedList* movieList,LinkedList** arrayListGenre)
{
    int retorno = 0;
    int continuar = 1;
    int opcion;
    LinkedList* aux;


    if (movieList != NULL && arrayListGenre != NULL)
    {
        do
        {
        	opcion = menuFilter();
            switch(opcion)
            {
            case 1:
            	aux= ll_clone(movieList);
            	aux= ll_filter(*arrayListGenre,movie_filterDrama);
                controller_saveFile("Drama.csv",*arrayListGenre);
                mostrarPeliculas(*arrayListGenre);
                break;
            case 2:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterComedia);
				*arrayListGenre = aux;
				controller_saveFile("Comedy.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
                break;
            case 3:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterAccion);
				*arrayListGenre = aux;
				controller_saveFile("Action.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
                break;
            case 4:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterTerror);
				*arrayListGenre = aux;
				controller_saveFile("Horror.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
                break;
            case 5:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterRomance);
				*arrayListGenre = aux;
				controller_saveFile("Romance.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
                break;
            case 6:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterAventura);
				*arrayListGenre = aux;
				controller_saveFile("Adventure.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
            	break;
            case 7:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterMusical);
				*arrayListGenre = aux;
				controller_saveFile("Musical.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
            	break;
            case 8:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterAnimacion);
				*arrayListGenre = aux;
				controller_saveFile("Animation.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
				break;
            case 9:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterDocumental);
				*arrayListGenre = aux;
				controller_saveFile("Documentary.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
				break;
            case 10:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterThriller);
				*arrayListGenre = aux;
				controller_saveFile("Thriller.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
				break;
            case 11:
            	aux= ll_clone(movieList);
				aux= ll_filter(*arrayListGenre,movie_filterWestern);
				*arrayListGenre = aux;
				controller_saveFile("Western.csv",*arrayListGenre);
				mostrarPeliculas(*arrayListGenre);
				break;
            case 12:
				 continuar = 0;
				 ll_deleteLinkedList(aux);
				break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            printf("\n\nSe guardo un archivo con la lista mostrada en pantalla.\n");
            system("pause");
        }
        while (continuar == 1);
    }
    return retorno;
}
int controller_sortMovies(LinkedList* movieList)
{
    int retorno = 0;
    if (movieList != NULL)
    {
        if(ll_sort(movieList,movie_sortGeneroAndDuracion,1) == 0)
        {
        	printf("hola");//no entra
        	mostrarPeliculas(movieList);
            retorno = 1;
        }
    }
    return retorno;
}
