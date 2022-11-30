/*
 ============================================================================
 Name        : practica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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


int main()
{
	setbuf(stdout,NULL);
	setbuf(stdin,NULL);
    //flags
    int flagLoad = 0;
    int flagDuracion = 0;
    int flagSort = 0;
    //rand
    srand(time(NULL));
  //  char path[50];
    //linkedList y punteros a linkedList
    LinkedList* movieList = ll_newLinkedList();
    if (movieList == NULL)
    {
        printf("No se consiguio memoria.\n");
        exit(1);
    }
    LinkedList* movieListDuracion = NULL;
    LinkedList* movieListDuracionyGenero = NULL;
    //init array punteros
    //ll_initArrayLinkedList(arrayListGenres,10);

    int seguir = 1;
    do
    {
        switch(menu())
        {
        case 1:
        	/*printf("ingrese el nombre del archivo .csv que desea cargar incluyendo el .csv al final \n");
        	scanf("%s",path);
        	gets(path);
        	*/
            if(controller_loadFile("movies.csv",movieList) == 1 && flagLoad == 0)
            {
                printf("archivo cargado con exito \n");
                flagLoad = 1;
            }
            else
            {
                printf("Ya se realiazo la carga.\n");
            }
            break;
        case 2:
            if (flagLoad)
            {
                controller_printList(movieList);
            }
            else
            {
                printf("Primero se debe realizar la carga (opcion 1)\n");
            }
            break;
        case 3:
            if (flagLoad && !flagDuracion)
            {
            	controller_setDuracion(movieList,&movieListDuracion);
            	flagDuracion = 1;
            }
            else
            {
                printf("Primero se debe realizar la carga (opcion 1) o bien la duracion ya fue asignada.\n");
            }

            break;
        case 4:
            if(flagLoad)
            {
               controller_filterGenero(movieList,&movieListDuracion);
               printf("filtrado realizado con exito \n");
            }
            else
            {
                printf("error en la filtracion \n");
            }
            break;
        case 5:
            if (flagLoad == 1 &&  flagDuracion==1)
            {
                controller_sortMovies(movieListDuracion);
                flagSort = 1;
            }
            else
            {
                printf("primero se debe asignar el genero (opcion 4).\n");
            }
            break;
        case 6:
            if (flagSort)
            {
                controller_saveFile("sortMovies.csv",movieListDuracion);
            }
            else
            {
                printf("primero debe realizarse el ordenamiento (opcion 6)\n");
            }

            break;
        case 7:
            seguir = 0;
            ll_deleteLinkedList(movieList);
            ll_deleteLinkedList(movieListDuracion);
            ll_deleteLinkedList(movieListDuracionyGenero);
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
    }
    while(seguir == 1);

    return 0;
}
