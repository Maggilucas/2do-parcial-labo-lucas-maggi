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

int menu()
{
    int opcion;
    system("cls");
    printf("1.Cargar archivo.\n");
    printf("2.Imprimir Lista\n");
    printf("3.Asignar duracion.\n");
    printf("4.Filtrar por genero.\n");
    printf("5.Ordenar Peliculas.\n");
    printf("6.Guardar Peliculas con duraciones\n");
    printf("7.Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int menuFilter()
{
    int opcion;
    system("cls");
    printf("1.Filtrar Drama.\n");
    printf("2.Filtrar Comedia\n");
    printf("3.Filtrar Accion.\n");
    printf("4.Filtrar Terror.\n");
    printf("5.Filtrar romance.\n");
    printf("6.Filtrar aventura.\n");
    printf("7.Filtrar musical.\n");
    printf("8.Filtrar animaciones.\n");
    printf("9.Filtrar documentales.\n");
    printf("10.Filtrar thrillers.\n");
    printf("11.Filtrar western.\n");
    printf("12.Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
