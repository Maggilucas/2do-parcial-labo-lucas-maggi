#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"


Seleccion* selec_new()
{
	Seleccion* seleccion = NULL;

	seleccion = (Seleccion*) malloc(sizeof(Jugador));

	return seleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccion;
	int todoOk = 0;
	seleccion = selec_new();
	if(seleccion != NULL)
	{
		seleccion->id = atoi(idStr);
		strcpy(seleccion->pais,paisStr);
		strcpy(seleccion->confederacion,confederacionStr);
		seleccion->convocados = atoi(convocadosStr);
		if(seleccion->id > 0 && strlen(seleccion->pais) > 0 && strlen(seleccion->confederacion) > 0 && seleccion->convocados >= 0)
		{
			todoOk = 1;
		}
		if(todoOk != 1)
		{
			seleccion = NULL;
		}
	}


	return seleccion;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int selec_getId(Seleccion* this,int* id)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int todoOk = 0;
	if(this != NULL)
	{
		strcpy(pais,this->pais);
		todoOk = 1;
	}
	return todoOk;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk = 0;
	if(this != NULL)
	{
		strcpy(confederacion,this->confederacion);
		todoOk = 1;
	}
	return todoOk;
}
int selec_setConvocados(Seleccion* this,int convocados)
{
	int todoOk = 0;
	if(this != NULL)
	{
		this->convocados = convocados;
		todoOk = 1;
	}
	return todoOk;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int todoOk = 0;
	if(this != NULL)
	{
		*convocados = this->convocados;
		todoOk = 1;
	}
	return todoOk;
}

void mostrarSeleccion(Seleccion* seleccion)
{

	int id;
	int convocados;
	char pais[30];
	char confederacion[30];
	if(seleccion != NULL)
	{
		if(selec_getId(seleccion,&id) == 1)
		{
			if(selec_getConfederacion(seleccion,confederacion) == 1)
			{
				if(selec_getPais(seleccion,pais) == 1)
				{

					if(selec_getConvocados(seleccion,&convocados) == 1)
					{
						printf("%-16d %-25s %-24s %d \n",id,pais,confederacion,convocados);
					}

				}
			}
		}
	}
}

int buscarIdSeleccion(LinkedList* this, int id)
{
	int todoOk = -1;
	int tamanio;
	int idSeleccion;
	Seleccion* seleccionAux;
	if(this != NULL && id > 0)
	{
		tamanio = ll_len(this);
		for(int i = 0; i < tamanio; i++)
		{
			seleccionAux = (Seleccion*)ll_get(this, i);
			if(selec_getId(seleccionAux,&idSeleccion) == 1)
			{
				if(idSeleccion == id)
				{
					todoOk = i;
					break;
				}
			}

		}
	}

	return todoOk;
}
int restarConvocados(LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	if(pArrayListSeleccion != NULL)
	{
		FILE* pArchivo = NULL;
		int idSeleccion;
		int indiceSeleccion;
		char idSeleccionStr[30];
		Seleccion* seleccion;
		int convocados;
		pArchivo = fopen("seleccionAux.csv","r");
		if(pArchivo != NULL)
		{
			fscanf(pArchivo,"%[^\n]\n",idSeleccionStr);
			idSeleccion = atoi(idSeleccionStr);
			if(idSeleccion > 0)
			{
				indiceSeleccion = buscarIdSeleccion(pArrayListSeleccion,idSeleccion);
				seleccion = (Seleccion*)ll_get(pArrayListSeleccion,indiceSeleccion);
				if(selec_getConvocados(seleccion,&convocados) == 1)
				{
					convocados--;
					if(selec_setConvocados(seleccion,convocados) == 1)
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				todoOk = 1;
			}
		}
		fclose(pArchivo);
	}
	return todoOk;
}
int ordenarPorConfederacion(void* jugador1,void* jugador2)
{
	int retorno = 0;
		Seleccion* seleccionUno = (Seleccion*)jugador1;
		Seleccion* seleccionDos = (Seleccion*)jugador2;
		char confederacionUno[30];
		char confederacionDos[30];
		if(selec_getConfederacion(seleccionUno,confederacionUno) == 1)
		{
			if(selec_getConfederacion(seleccionDos,confederacionDos) == 1)
			{
				if(stricmp(confederacionUno,confederacionDos) > 0)
				{
					retorno = 1;
				}
				else
				{
					if(stricmp(confederacionUno,confederacionDos) < 0)
					{
						retorno = -1;
					}
				}
			}
		}
		return retorno;
}
int cargarConfederacion(int indice, char* confederacion)
{
	int todoOk = 0;
	if(confederacion != NULL)
	{
		switch(indice)
		{
		case 1:
			strcpy(confederacion,"AFC");
			break;
		case 2:
			strcpy(confederacion,"CAF");
			break;
		case 3:
			strcpy(confederacion,"CONCACAF");
			break;
		case 4:
			strcpy(confederacion,"CONMEBOL");
			break;
		case 5:
			strcpy(confederacion,"UEFA");
			break;
		todoOk = 1;
		}
	}
	return todoOk;
}
