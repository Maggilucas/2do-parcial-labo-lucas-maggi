#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "parser.h"
#include "movies.h"
#include "validaciones.h"
#include "controller.h"
#include "menus.h"
#include "time.h"

eMovie* mov_new()
{
	return (eMovie*) malloc(sizeof(eMovie));
}

eMovie* movie_newParam(char* idStr, char* titulo, char* genero, char* duracionStr)
{

	eMovie* peliculas;
	int todoOk=0;
	peliculas = mov_new();

	if(peliculas!=NULL)
	{
		if(mov_setId(peliculas, atoi(idStr)) == 1)
		{
			if(mov_setTitulo(peliculas, titulo) == 1)
			{
				if(mov_setGenero(peliculas, genero)== 1)
				{
					if(mov_setDuracion(peliculas,atoi(duracionStr))== 1)
					{
						todoOk=1;
					}
				}
			}
		}
	}

	if(todoOk != 1)
	{
		peliculas= NULL;
	}

		return peliculas;
}


void mov_delete(eMovie* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

////////////// SETTERS///////////////////////
int mov_setId(eMovie* this,int id)
{
	int retorno = -1;

		if(this != NULL && id > 0)
		{
			this->id_peli = id;
			retorno = 1;
		}

		return retorno;
}
int mov_setTitulo(eMovie* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 1;
	}

	return retorno;
}
int mov_setGenero(eMovie* this,char* genero)
{
	int retorno = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(this->genero, genero);
		retorno = 1;
	}

	return retorno;
}
int mov_setDuracion(eMovie* this,int duracion)
{
	int retorno = -1;

	if(this != NULL && duracion >= 0)
	{
		this->duracion = duracion;
		retorno = 1;
	}

	return retorno;
}
/////////// GETTERS/////////////////////////
int mov_getId(eMovie* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id_peli;
		retorno = 1;
	}

	return retorno;
}
int mov_getTitulo(eMovie* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 1;
	}

	return retorno;
}
int mov_getGenero(eMovie* this,char* genero)
{
	int retorno = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(genero,this->genero);
		retorno = 1;
	}

	return retorno;
}
int mov_getDuracion(eMovie* this,int* duracion)
{
	int retorno = -1;

	if(this != NULL && duracion != NULL)
	{
		*duracion = this->duracion;
		retorno = 1;
	}

	return retorno;
}


int mostrarMovie(eMovie* movie)
{
    int retorno = 0;
    if (movie != NULL)
    {
        printf("%4d %30s %20s %d\n",movie->id_peli,movie->titulo,movie->genero,movie->duracion);
        retorno = 1;
    }
    return retorno;
}

int mostrarPeliculas(LinkedList* movies)
{
    eMovie* auxMovie = NULL;
    int retorno = 0;
    int len;
    if(movies != NULL)
    {
		len = ll_len(movies);
        printf("  ID                    NOMBRE                  GENERO       DURACION\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < len; i++)
        {
            auxMovie = (eMovie*)ll_get(movies,i);
            if(mostrarMovie(auxMovie)== 1)
            {
                retorno++;
            }
        }
        auxMovie = NULL;
    }
    return retorno;
}

void* movie_mapDuracion (void* element)//asigna rating aleatorio
{
    void* retorno = element;
    eMovie* auxElement = NULL;
    eMovie* auxNewMovie = NULL;
    int duracionRandom;
    auxNewMovie = mov_new();
    if (auxNewMovie != NULL)
    {
        auxElement = (eMovie*)element;
        *auxNewMovie = *auxElement;
        do
        {
        	duracionRandom = rand();
        }
        while (duracionRandom < 100 || duracionRandom >240);
        mov_setDuracion(auxNewMovie,duracionRandom);
        retorno = auxNewMovie;
    }

    return retorno;
}

void* movie_mapGenero (void* element)//asigna genero
{
    void* retorno = element;
    eMovie* auxElement = NULL;
    eMovie* auxNewMovie = NULL;
    int genreRandom;
    auxNewMovie = mov_new();
    char drama[]="Drama";
    char comedia[]="Comedia";
    char accion[]="Accion";
    char terror[]="Terror";
    if (auxNewMovie != NULL)
    {
        auxElement = (eMovie*)element;
        *auxNewMovie = *auxElement;
        genreRandom = 1+rand() % 4;
        switch(genreRandom)
        {
        case 1://drama
        	mov_setGenero(auxNewMovie,drama);
            break;
        case 2://comedia
        	mov_setGenero(auxNewMovie,comedia);
            break;
        case 3://accion
        	mov_setGenero(auxNewMovie,accion);
            break;
        case 4://terror
        	mov_setGenero(auxNewMovie,terror);
            break;
        }
        retorno = auxNewMovie;
    }
    return retorno;
}

//filter
int movie_filterDrama(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Drama")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterComedia(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Comedy")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterAccion(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Action")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int movie_filterTerror(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Horror")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterRomance(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Romance")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterAventura(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Adventure")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterMusical(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Musical")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterAnimacion(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Animacion")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterDocumental(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Documentary")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterThriller(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Thriller")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterWestern(void* element)
{
    int retorno = 0;
    eMovie* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (eMovie*) element;
        if(stricmp(auxMovie->genero,"Western")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
//sort
int movie_sortGeneroAndDuracion(void* a, void* b)
{
    int retorno = 0;
    eMovie* movieA;
    eMovie* movieB;
    if (a != NULL && b != NULL)
    {
      movieA = (eMovie*)a;
      movieB = (eMovie*)b;
      if((stricmp(movieA->genero,movieB->genero)>0) || (stricmp(movieA->genero,movieB->genero) == 0 && movieA->duracion<movieB->duracion))
      {
          retorno = 1;
      }
    }
    return retorno;
}
