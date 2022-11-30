/*
 * movies.h
 *
 *  Created on: 28 nov. 2022
 *      Author: PC
 */

#ifndef MOVIES_H_
#define MOVIES_H_

#include "LinkedList.h"

typedef struct
{
	int id_peli;
	char titulo[50];
	char genero[20];
	int duracion;
}eMovie;

eMovie* mov_new();

eMovie* movie_newParam(char* idStr, char* titulo, char* genero, char* duracionStr);
void mov_delete(eMovie* this);
////////////// SETTERS///////////////////////
int mov_setId(eMovie* this,int id);
int mov_setTitulo(eMovie* this,char* titulo);
int mov_setGenero(eMovie* this,char* genero);
int mov_setDuracion(eMovie* this,int duracion);
/////////// GETTERS/////////////////////////
int mov_getId(eMovie* this,int* id);
int mov_getTitulo(eMovie* this,char* titulo);
int mov_getGenero(eMovie* this,char* genero);
int mov_getDuracion(eMovie* this,int* duracion);

int mostrarMovie(eMovie* movie);
int mostrarPeliculas(LinkedList* movies);

void* movie_mapDuracion (void* element);
void* movie_mapGenero (void* element);
int movie_filterTerror(void* element);
int movie_filterDrama(void* element);
int movie_filterAccion(void* element);
int movie_filterComedia(void* element);
int movie_filterRomance(void* element);
int movie_filterAventura(void* element);
int movie_filterMusical(void* element);
int movie_filterAnimacion(void* element);
int movie_filterDocumental(void* element);
int movie_filterThriller(void* element);
int movie_filterWestern(void* element);
int movie_sortGeneroAndDuracion(void* a, void* b);

#endif /* MOVIES_H_ */
