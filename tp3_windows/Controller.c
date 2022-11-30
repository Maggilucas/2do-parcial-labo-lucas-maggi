#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL && path != NULL)
		{
			if(parser_JugadorFromText(pArchivo, pArrayListJugador)== 1)
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

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador)== 1)
			{
				printf("Se cargo con exito\n");
				todoOk=0;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}

	return todoOk;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	Jugador* jugador;
	int posicion;
	int nacionalidad;
	int edad;
	char idStr[30];
	char nombre [100];
	char edadAux[3];
	char posicionStr[30];
	char nacionalidadStr[30];

	if(pArrayListJugador != NULL)
	{
		UltimoId(idStr);

		utn_getChar(nombre,"Ingrese nombre completo: \n","error... \n",100);
		utn_getNumeroInt(&edad,"Ingrese su edad :\n","ERROR INGRESE UNA OPCION VALIDA: \n",18,50,9);
		printf("opciones de posicion \n");
		printf("1- Portero \n");
		printf("2- Defensa central \n");
		printf("3- Lateral izquierdo \n");
		printf("4- Lateral derecho \n");
		printf("5- Pivote \n");
		printf("6- Mediocentro \n");
		printf("7- Mediocentro ofensivo \n");
		printf("8- Extremo izquierdo \n");
		printf("9- Extremo derecho \n");
		printf("10- Mediopunta \n");
		printf("11- Delantero centro \n");
		utn_getNumeroInt(&posicion,"Ingrese la opcion: \n","ERROR INGRESE UNA OPCION VALIDA: \n",1,11,9);
		switch(posicion)
		{
			case 1:
				strcpy(posicionStr,"Portero");
				break;
			case 2:
				strcpy(posicionStr,"Defensa central");
				break;
			case 3:
				strcpy(posicionStr,"Lateral izquierdo");
				break;
			case 4:
				strcpy(posicionStr,"Lateral derecho");
				break;
			case 5:
				strcpy(posicionStr,"Pivote");
				break;
			case 6:
				strcpy(posicionStr,"Mediocentro");
				break;
			case 7:
				strcpy(posicionStr,"Mediocentro ofensivo");
				break;
			case 8:
				strcpy(posicionStr,"Extremo izquierdo");
				break;
			case 9:
				strcpy(posicionStr,"Extremo derecho");
				break;
			case 10:
				strcpy(posicionStr,"Mediopunta");
				break;
			case 11:
				strcpy(posicionStr,"Delantero centro");
				break;
		}
		printf("opciones de nacionalidad \n");
		printf("1- argentino \n");
		printf("2- brasileño \n");
		printf("3- uruguayo \n");
		printf("4- portugues \n");
		printf("5- ingles \n");
		printf("6- aleman \n");
		printf("7- mexicano \n");
		printf("8- estado unidense \n");
		printf("9- camerunes \n");
		printf("10- senegales \n");
		printf("11- australiano \n");
		printf("12- qatari \n");
		utn_getNumeroInt(&nacionalidad,"Ingrese la opcion: \n","ERROR INGRESE UNA OPCION VALIDA: \n",1,12,9);
		switch(nacionalidad)
		{
			case 1:
				strcpy(nacionalidadStr,"argentino");
				break;
			case 2:
				strcpy(nacionalidadStr,"brasilero");
				break;
			case 3:
				strcpy(nacionalidadStr,"uruguayo");
				break;
			case 4:
				strcpy(nacionalidadStr,"portugues");
				break;
			case 5:
				strcpy(nacionalidadStr,"ingles");
				break;
			case 6:
				strcpy(nacionalidadStr,"aleman");
				break;
			case 7:
				strcpy(nacionalidadStr,"mexicano");
				break;
			case 8:
				strcpy(nacionalidadStr,"estado unidense");
				break;
			case 9:
				strcpy(nacionalidadStr,"camerunes");
				break;
			case 10:
				strcpy(nacionalidadStr,"senegales");
				break;
			case 11:
				strcpy(nacionalidadStr,"australiano");
				break;
			case 12:
				strcpy(nacionalidadStr,"qatari");
				break;
		}
		itoa(edad,edadAux,10);

		jugador = jug_newParametros(idStr, nombre, edadAux, posicionStr, nacionalidadStr, "0");
		if(jugador != NULL)
		{
			ll_add(pArrayListJugador, jugador);
			todoOk=1;
		}
	}
    return todoOk;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int todoOk=0;
	int id;
	int indice;
	int nacionalidad;
	char confirma;
	int modificar;
	int posicionAux;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidadStr[30];

	Jugador* jugador;

	if(pArrayListJugador != NULL)
	{
		utn_getNumeroInt(&id,"Ingrese el id que desea modificar : \n","ERROR INGRESE UNA OPCION VALIDA \n",1,20000,9);
		indice = BuscarIdJugador(pArrayListJugador,id);
		if(indice != -1)
		{
		jugador = (Jugador*)ll_get(pArrayListJugador,indice);
		MostrarJugador(jugador);
		printf("\n--------Modificar---------\n"
				"1.NOMBRE\n"
				"2.EDAD \n"
				"3.POSICION \n"
				"4.NACIONALIDAD \n");
		if(utn_getNumeroInt(&modificar,"Opcion que desea modificar: \n","ERROR INGRESE UNA OPCION VALIDA \n",1,4,9) == 1)
		{
			if(utn_getCharSeguir(&confirma,"\nSeguro que quiere modificar S o N:","elija solo s o n \n",9) == 1)
			{
				if(confirma == 's')
				{
					switch(modificar)
					{
					case 1:
						utn_getChar(nombreCompleto,"Ingrese nombre completo: \n"," ingrese un nombre valido \n",100);
							if(jug_setNombreCompleto(jugador,nombreCompleto) == 0)
							{
								printf("Se a modificado el nombre con exito \n");
								todoOk = 1;
							}
							else
							{
								printf("No se pudo modificar el nombre \n");
							}
						break;
					case 2:
						utn_getNumeroInt(&edad," Ingrese la edad : \n"," ERROR INGRESE UNA OPCION VALIDA: \n",18,50,9);

						if(jug_setEdad(jugador,edad) == 0)
						{
							printf("Se a modificado la edad con exito\n");
							todoOk = 1;
						}
						else
						{
							printf("No se pudo modificar la edad \n");
						}
						break;
					case 3:
						printf("\n----opciones de posiciones----\n"
								"1.Portero\n"
								"2.Defensa Central\n"
								"3.Lateral Izquierdo\n"
								"4.Lateral derecho\n"
								"5.Pivote\n"
								"6.Mediocentro\n"
								"7.Mediocentro ofensivo\n"
								"8.Extremo izquierdo\n"
								"9.Extremo derecho\n"
								"10.Mediopunta\n"
								"11.Delantero centro");
						utn_getNumeroInt(&posicionAux,"Ingrese la opcion: \n","ERROR INGRESE UNA OPCION VALIDA: \n",1,11,9);
						switch(posicionAux)
						{
							case 1:
								strcpy(posicion,"Portero");
								break;
							case 2:
								strcpy(posicion,"Defensa central");
								break;
							case 3:
								strcpy(posicion,"Lateral izquierdo");
								break;
							case 4:
								strcpy(posicion,"Lateral derecho");
								break;
							case 5:
								strcpy(posicion,"Pivote");
								break;
							case 6:
								strcpy(posicion,"Mediocentro");
								break;
							case 7:
								strcpy(posicion,"Mediocentro ofensivo");
								break;
							case 8:
								strcpy(posicion,"Extremo izquierdo");
								break;
							case 9:
								strcpy(posicion,"Extremo derecho");
								break;
							case 10:
								strcpy(posicion,"Mediopunta");
								break;
							case 11:
								strcpy(posicion,"Delantero centro");
								break;
						}
							if(jug_setPosicion(jugador,posicion) == 0)
							{
								printf("Se modifico la posicion \n");
								todoOk = 1;
							}
							else
							{
								printf("No se pudo modificar la posicion \n");

							}
						break;
					case 4:
						printf("opciones de nacionalidad \n");
						printf("1- argentino \n");
						printf("2- brasileño \n");
						printf("3- uruguayo \n");
						printf("4- portugues \n");
						printf("5- ingles \n");
						printf("6- aleman \n");
						printf("7- mexicano \n");
						printf("8- estado unidense \n");
						printf("9- camerunes \n");
						printf("10- senegales \n");
						printf("11- australiano \n");
						printf("12- qatari \n");
						utn_getNumeroInt(&nacionalidad,"Ingrese la opcion: \n","ERROR INGRESE UNA OPCION VALIDA: \n",1,12,9);
						switch(nacionalidad)
						{
							case 1:
								strcpy(nacionalidadStr,"argentino");
								break;
							case 2:
								strcpy(nacionalidadStr,"brasilero");
								break;
							case 3:
								strcpy(nacionalidadStr,"uruguayo");
								break;
							case 4:
								strcpy(nacionalidadStr,"portugues");
								break;
							case 5:
								strcpy(nacionalidadStr,"ingles");
								break;
							case 6:
								strcpy(nacionalidadStr,"aleman");
								break;
							case 7:
								strcpy(nacionalidadStr,"mexicano");
								break;
							case 8:
								strcpy(nacionalidadStr,"estado unidense");
								break;
							case 9:
								strcpy(nacionalidadStr,"camerunes");
								break;
							case 10:
								strcpy(nacionalidadStr,"senegales");
								break;
							case 11:
								strcpy(nacionalidadStr,"australiano");
								break;
							case 12:
								strcpy(nacionalidadStr,"qatari");
								break;
						}
						if(jug_setNacionalidad(jugador,nacionalidadStr) == 0)
						{
							printf("Se a modificado la nacionalidad con exito \n");
							todoOk = 1;
						}
						else
						{
							printf("No se pudo modificar la nacionalidad \n");
						}
						break;
					}
					if(ll_set(pArrayListJugador,indice,jugador) == 0)
					{
						todoOk = 1;
					}
				}
				else
				{
					if(confirma == 'n')
					{
						printf("No se realizo modificacion en el jugador \n");
						todoOk = 1;
					}
				}
			}
		}
	}
	else
	{
		printf("No se encontro el id del jugador \n");
		todoOk = 1;
	}
}


    return todoOk;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	FILE* pArchivo = NULL;
	Jugador* jugador;
	int indice;
	int id;
	char confirma;
	int idSeleccion;

	if(pArrayListJugador != NULL)
	{

		if(utn_getNumeroInt(&id," Ingrese el id que desea dar de baja : \n","ERROR INGRESE UNA OPCION VALIDA \n",1,20000,9) == 1)
		{
			indice = BuscarIdJugador(pArrayListJugador,id);
			if(indice != -1)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador,indice);
				if(jugador != NULL)
				{
					MostrarJugador(jugador);
					if(utn_getCharSeguir(&confirma,"Seguro que quiere dar de baja S o N: \n","Error. \n",9) == 1)
					{
						if(confirma == 's')
						{
							if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
							{
								pArchivo = fopen("seleccionAux.csv","w");
								if(pArchivo != NULL)
								{
									fprintf(pArchivo, "%d", idSeleccion);
									printf("funciona");
								}
								else
								{
									printf("NO FUNCIONA");
								}
								fclose(pArchivo);
							}
							else
							{
								printf("Error al buscar el id seleccion \n");
								todoOk = 0;
							}
							if(ll_remove(pArrayListJugador, indice) == 0)
							{

								jug_delete(jugador);
								todoOk = 1;
							}

						}
						else
						{
							if(confirma == 'n')
							{
								printf("No se eliminaron jugadores \n");
							}
						}
					}
				}

			}
		}

	}

    return todoOk;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int cantidadJugadores;
	int idSeleccion = 0;
	int indiceSeleccion;
	char pais[30];
	Jugador* jugador;
	Seleccion* seleccion;
	if(pArrayListJugador != NULL)
	{

		cantidadJugadores = ll_len(pArrayListJugador);
		if(cantidadJugadores > 0)
		{
			printf("\n-----Id dados de Alta----\n ID\t\tNOMBRE\t\t\t POSICION \t\t EDAD\t\t NACIONALIDAD\t\tSELECCION");
			for(int i = 0; i < cantidadJugadores; i++)
			{
				jugador = (Jugador*) ll_get(pArrayListJugador, i);
				if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
				{
					if(idSeleccion > 0)
					{
						indiceSeleccion = buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
						if(indiceSeleccion != -1)
						{
							seleccion = (Seleccion*) ll_get(pArrayListSeleccion,indiceSeleccion);
							if(selec_getPais(seleccion,pais) == 1)
							{
								todoOk= 1;
							}
						}
					}
					else
					{
						strcpy(pais,"No convocado");
					}

				}
				MostrarJugadorPais(jugador,pais);
			}
			todoOk = 1;
		}
	}
    return todoOk;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int opciones;
	int todoOk;
	int orden;
	LinkedList* aux;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		printf("Listar y ordenar\n"
			   " 1)Jugadores por nacionalidad \n"
			   " 2)Seleccion por confederacion \n"
			   " 3)Jugadores por edad \n"
			   " 4)Jugadores por Nombre \n");

		utn_getNumeroInt(&opciones, "ingrese una opcion : \n", "ingrese una opcion valida \n",1, 4, 9);
		if(utn_getNumeroInt(&orden,"Ingrese 0 para orden ascendente o 1 para orden desencente: \n","\nERROR INGRESE UNA OPCION VALIDA",0,1,9))
		{
				switch(opciones)
				{
				case 1:
					aux = ll_clone(pArrayListJugador);
					if(aux != NULL)
					{
						if(ll_sort(aux, ordenarPorNacionalidad, orden) == 0)
						{
							if(controller_listarJugadores(aux,pArrayListSeleccion) == 1)
							{
								printf(" Se realizo con exito el ordenamiento \n");
								todoOk = 1;
							}
							else
							{
								printf(" ERROR al listar las Jugadores \n");
							}
						}

					}

					break;
				case 2:
					aux = ll_clone(pArrayListSeleccion);
					if(aux != NULL)
					{
						if(ll_sort(aux , ordenarPorConfederacion, orden) == 0)
						{
							if(controller_listarSelecciones(aux) == 1)
							{
								printf("Se realizo con exito el ordenamiento \n");
								todoOk = 1;
							}
							else
							{
								printf("ERROR al listar las Selecciones \n");
							}
						}

					}

					break;
				case 3:
					aux = ll_clone(pArrayListJugador);
					if(aux != NULL)
					{
						if(ll_sort(aux , ordenarPorEdad, orden) == 0)
						{
							if(controller_listarJugadores(aux,pArrayListSeleccion) == 1)
							{
								printf("Se realizo con exito el ordenamiento \n");
								todoOk = 1;
							}
							else
							{
								printf("ERROR al listar las Jugadores \n");
							}
						}

					}

					break;
				case 4:
					aux = ll_clone(pArrayListJugador);
					if(aux != NULL)
					{
						if(ll_sort(aux , ordenarPorNombre, orden) == 0)
						{
							if(controller_listarJugadores(aux,pArrayListSeleccion) == 1)
							{
								printf("Se realizo con exito el ordenamiento \n");
								todoOk = 1;
							}
							else
							{
								printf("ERROR al listar las Jugadores \n");
							}
						}

					}

					break;
				}
			ll_deleteLinkedList(aux);
	}
	}
    return todoOk;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	FILE* pArchivo;
	Jugador* jugador;
	int len;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if(pArrayListJugador != NULL)
	{
		if (path != NULL)
		{
			pArchivo = fopen (path,"w");
			len = ll_len(pArrayListJugador);
			if(len > 0)
			{
				if(pArchivo != NULL)
				{

					fprintf(pArchivo,"id,NombreCompleto,edad,posicion,nacionalidad,id Selecion\n");


					for(int i = 0; i < len; i++)
					{
						jugador = ll_get(pArrayListJugador, i);
						if(jugador != NULL)
						{
							if(jug_getId(jugador, &id) == 0)
							{
								if(jug_getNombreCompleto(jugador, nombreCompleto) == 0)
								{
									if(jug_getEdad(jugador, &edad) == 0)
									{
										if(jug_getPosicion(jugador, posicion) == 0)
										{
											if(jug_getNacionalidad(jugador, nacionalidad) == 0)
											{
												if(jug_getIdSeleccion(jugador, &idSeleccion) == 0)
												{
													fprintf(pArchivo,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
												}
											}
										}
									}
								}
							}
						}
					}
					todoOk = 1;
				}
			}
			fclose(pArchivo);
		}
	}
    return todoOk;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* archivo = NULL;
	Jugador* jugador;
	int cantidad;
	int todoOk = 0;
	if(pArrayListJugador != NULL)
	{
		if (path != NULL)
		{

			archivo = fopen (path,"wb");


			cantidad = ll_len(pArrayListJugador);
			if(archivo != NULL)
			{
				printf("\n %d",cantidad);
				if(cantidad > 0)
				{
					for(int i = 0; i < cantidad; i++)
					{
						jugador = ll_get(pArrayListJugador, i);
						if(jugador != NULL)
						{
							fwrite(jugador,sizeof(Jugador),1,archivo);
						}
					}
					todoOk = 1;
				}
			}
			fclose(archivo);
		}
	}
    return todoOk;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	if(pArrayListSeleccion != NULL)
	{
		FILE* pArchivo;
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_SeleccionFromText(pArchivo,pArrayListSeleccion) == 1)
			{
				todoOk = 1;
			}
		}
		fclose(pArchivo);


	}
    return todoOk;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int cantidadJugadores;
	if(pArrayListSeleccion != NULL)
	{
		cantidadJugadores = ll_len(pArrayListSeleccion);
		Seleccion* seleccion;
		if(cantidadJugadores > 0)
		{
			printf("\n-----SELECCIONES----\n ID\t\tPAIS\t\t\tCONFEDERACION\t\t CONVOCADOS");
			for(int i = 0; i < cantidadJugadores; i++)
			{
				seleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				mostrarSeleccion(seleccion);
			}
			todoOk = 1;
		}
	}
    return todoOk;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{

    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	FILE* archivo;
	Seleccion* seleccion;
	int len;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(pArrayListSeleccion != NULL)
	{
		if (path != NULL)
		{
			archivo = fopen (path,"w");
			len = ll_len(pArrayListSeleccion);
			if(len > 0)
			{
				if(archivo != NULL)
				{

					fprintf(archivo,"id,pais,confederacion,convocados\n");


					for(int i = 0; i < len; i++)
					{
						seleccion = ll_get(pArrayListSeleccion, i);
						if(seleccion != NULL)
						{
							if(selec_getId(seleccion, &id) == 1)
							{
								if(selec_getPais(seleccion, pais) == 1)
								{
									if(selec_getConfederacion(seleccion, confederacion) == 1)
									{
										if(selec_getConvocados(seleccion, &convocados) == 1)
										{
											fprintf(archivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
										}
									}
								}
							}
						}
					}
					todoOk = 1;
				}
			}
			fclose(archivo);
		}
	}
    return todoOk;
}

int controller_ListarTodo(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opciones;
	int todoOk;
	int cantidad;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		printf(" Listar \n"
			   " 1)Todos los jugadores \n"
			   " 2)Todas las selecciones \n"
			   " 3)Solo los jugadores convocados \n");
		todoOk = utn_getNumeroInt(&opciones, " ingrese una opcion : \n", "Error.",1, 3, 9);

		if(todoOk == 1)
		{
			switch(opciones)
			{
			case 1:
				if(controller_listarJugadores(pArrayListJugador,pArrayListSeleccion) == 1)
				{
					printf(" Se realizo con exito listar los Jugadores \n");
					todoOk = 1;
				}
				else
				{
					printf(" ERROR al listar las Jugadores \n");
				}
				break;
			case 2:
				cantidad = ll_len(pArrayListSeleccion);
				if(cantidad > 0)
				{
						if(controller_listarSelecciones(pArrayListSeleccion) == 1)
						{
							printf("Se realizo con exito listar las selecciones \n");
							todoOk = 1;
						}
						else
						{
							printf("ERROR al listar las selecciones \n");
						}
				}
				else
				{
					printf("Tiene que cargar el archivo de selecciones primero \n");
					todoOk = 1;
				}

				break;
			case 3:
				cantidad = ll_len(pArrayListSeleccion);
				if(cantidad > 0)
				{
					if(ListarConvocados(pArrayListJugador) == 1)
					{
						printf(" Se realizo con exito la lista de jugadores convocados \n");
					}
					else
					{
						printf(" ERROR al listar los jugadores convocados \n");
					}
				}
				else
				{
					printf(" Tiene que cargar el archivo de selecciones primero \n");
					todoOk = 1;
				}

				break;
			}
		}
	}


	return todoOk;
}

int controller_convocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opciones;
	int todoOk=0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{

		printf(" que opcion desea realizar? \n"
			   " 1)Convocar jugador \n"
			   " 2)Quitar jugador de una Seleccion \n");
		todoOk = utn_getNumeroInt(&opciones, "ingrese una opcion : \n", "Error.",1, 2, 9);
		if(todoOk == 1)
		{
			switch(opciones)
			{
			case 1:

				if(controller_altaConvocado(pArrayListJugador,pArrayListSeleccion) == 1)
				{

					todoOk = 1;
				}
				else
				{
					printf(" no se pudo convocar al jugador \n");
				}
				break;
			case 2:
				if(controller_bajaConvocado(pArrayListJugador, pArrayListSeleccion) == 1)
				{
					printf("Se realizo con exito la baja al jugador de la seleccion \n");
					todoOk = 1;
				}
				else
				{
					printf("ERROR al dar de baja de la seleccio seleccion \n");
				}
				break;

			}
		}

		}
		else
		{

			todoOk = 0;
		}
	return todoOk;
}


int controller_altaConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int todoOk = 0;
	Seleccion* seleccion;
	Jugador* jugador;
	int cantidad;
	int indice;
	int id;
	char confirma;
	int idSeleccion;
	int convocados;
	int flag =0;
	int indiceSeleccion;
	int auxIdSeleccion;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);

		if(utn_getNumeroInt(&id," Ingrese el id que desea convocar : \n","ERROR INGRESE UNA OPCION \n",1,20000,9) == 1)
		{
			indice = BuscarIdJugador(pArrayListJugador,id);
			if(indice != 0)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador,indice);
				MostrarJugador(jugador);
				if(jug_getIdSeleccion(jugador,&auxIdSeleccion) == 0)
				{
					if(auxIdSeleccion == 0)
					{
						if(utn_getCharSeguir(&confirma,"Seguro que quiere convocar a la seleccion S o N: \n","Error. \n",9) == 1)
						{
							if(confirma == 's')
							{
								cantidad = ll_len(pArrayListSeleccion);
								for(int i= 0;i<cantidad;i++)
								{
									seleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
									if(seleccion != NULL)
									{
										if(selec_getConvocados(seleccion,&convocados) == 1)
										{
											if(convocados < 22)
											{
												flag = 1;
												mostrarSeleccion(seleccion);
											}
										}
									}
								}
								if(flag == 1)
								{
									do
									{
										flag = 0;
										if(utn_getNumeroInt(&idSeleccion," Ingrese el id de la seleccion : \n","ERROR INGRESE UNA OPCION VALIDA \n",1,cantidad,9) == 1)
										{
											indiceSeleccion = buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
											if(indiceSeleccion != 0)
											{
												seleccion = (Seleccion*)ll_get(pArrayListSeleccion,indiceSeleccion);
												if(selec_getConvocados(seleccion,&convocados) == 1)
												{
													flag = 0;
													if(convocados < 22)
													{
														flag = 1;
														mostrarSeleccion(seleccion);
														if(utn_getCharSeguir(&confirma,"Es la seleccion que fue convocado? S o N: \n","Error. \n",9) == 1)
														{
															if(confirma == 's')
															{
																if(jug_setIdSeleccion(jugador,idSeleccion) == 0 )
																{
																	convocados++;
																	if(selec_setConvocados(seleccion,convocados) == 1)
																	{
																		printf("el jugador fue convocado \n");
																		todoOk = 1;
																	}
																	else
																	{
																		todoOk = 0;
																	}
																}
																else
																{
																	todoOk = 0;
																}
															}
															else
															{
																if(confirma == 'n')
																{
																	printf(" No fue convocado \n");
																	todoOk = 1;
																}
															}
														}
													}
													else
													{
														printf("Esta lleno \n");
													}
												}
											}
										}
										else
										{
											flag = 1;
											todoOk = 0;
										}

									}while(flag != 1);

								}
							}
						}
						else
						{
							printf("No se modifico \n");
						}
					}
					else
					{
						printf(" Ese id ya tiene una seleccion, tiene que darlo de baja de la seleccion primero \n");
						todoOk = 1;
					}
				}
			}
			else
			{
				printf("No se encontro el id \n");
			}
		}
		else
		{
			printf("ERROR EN EL INGRESO DEL ID \n");
			todoOk = 0;
		}
	}
	return todoOk;
}

int controller_bajaConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	Seleccion* seleccion;
	Jugador* jugador;
	int indice;
	int id;
	char confirma;
	int idSeleccion;
	int convocados;
	int flag = 0;
	int indiceSeleccion;

	if(pArrayListJugador != NULL && pArrayListSeleccion)
	{
		todoOk = 1;
		if(ListarConvocados(pArrayListJugador) == 1)
		{
			do
			{
				flag = 0;
				if(utn_getNumeroInt(&id,"Ingrese el id que desea dar de baja de la seleccion : \n","ERROR INGRESE UNA OPCION VALIDA \n",1,999999,9) == 1)
				{
					indice = BuscarIdJugador(pArrayListJugador,id);
					if(indice != 0)
					{
						jugador = (Jugador*)ll_get(pArrayListJugador,indice);
						MostrarJugador(jugador);
						if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
						{
							if(idSeleccion > 0)
							{
								flag = 1;
								if(utn_getCharSeguir(&confirma,"Seguro que quiere dar de baja de la seleccion S o N: \n","Error. \n",9) == 1)
								{
									indiceSeleccion = buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
									if(indiceSeleccion != 0)
									{
										seleccion = (Seleccion*)ll_get(pArrayListSeleccion,indiceSeleccion);
										if(selec_getConvocados(seleccion,&convocados) == 1)
										{
											convocados--;
											if(selec_setConvocados(seleccion,convocados) == 1)
											{
												todoOk = 1;
												if(jug_setIdSeleccion(jugador,0) == 0)
												{
													todoOk = 1;
												}
											}

										}
										else
										{
											todoOk= 0;
										}

									}
									else
									{
										printf("ERROR NO SE ENCONTRO EL ID \n");

									}
								}
							}
							else
							{
								flag = 0;
								printf("El jugador no fue convocado a una seleccion \n");
							}
						}
						else
						{
							todoOk = 0;
						}
					}
					else
					{
						printf("No se encontro el id \n");
					}

				}
			}while(flag != 1);
		}
		else
		{
			printf("No hay jugadores convocados \n");
		}

	}
	return todoOk;
}

int controller_generarBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int idSeleccion;
	Seleccion* seleccion;
	Jugador* jugador;
	int indiceSeleccion;
	char confederacion[30];
	int cantidadJugadores;
	int idConfederacion;
	char confederacionAux[30];
	LinkedList* aux = ll_newLinkedList();
	if(pArrayListJugador != NULL && pArrayListSeleccion)
	{
		cantidadJugadores = ll_len(pArrayListJugador);
		printf("\n"
				"1.AFC\n"
				"2.CAF\n"
				"3.CONCACAF\n"
				"4.CONMEBOL\n"
				"5.UEFA\n");
		if(utn_getNumeroInt(&idConfederacion," Ingrese el id de la confederacion : \n","ERROR INGRESE UNA OPCION VALIDA \n",1,5,9) == 1)
		{
			cargarConfederacion(idConfederacion,confederacionAux);

			for(int i = 0; i < cantidadJugadores; i++)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador,i);
				if(jug_getIdSeleccion(jugador,&idSeleccion) == 0)
				{
					indiceSeleccion = buscarIdSeleccion(pArrayListSeleccion, idSeleccion);
					seleccion = (Seleccion*)ll_get(pArrayListSeleccion,indiceSeleccion);
					if(selec_getConfederacion(seleccion,confederacion) == 1)
					{
						if(stricmp(confederacionAux,confederacion) == 0)
						{
							ll_add(aux, jugador);
							todoOk = 1;
						}

					}
				}
			}
			if(todoOk == 1)
			{

				if(controller_guardarJugadoresModoBinario("convocadosLista.bin", aux) == 1)
				{
					ll_deleteLinkedList(aux);
				}
			}
			else
			{
				printf("No hay jugadores convocados en esa confederacion \n");
			}
		}
	}
	return todoOk;
}
