#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "validaciones.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int todoOk=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* convocados = ll_newLinkedList();
    int tamanio;
    int archivos=0;
    int banderaDos=0;
    char confirma;

    if(cargarAchivoId() == 1)
	{
		do{
			todoOk=0;
			tamanio = ll_len(listaJugadores);
			printf("\n--------Menu----------\n"
					"1.Cargar archivos\n"
					"2.Alta jugador\n"
					"3.Modificar jugador\n"
					"4.Baja Jugador\n"
					"5.Listado\n"
					"6.Convocar Jugadores\n"
					"7.Ordenar y listar \n"
					"8.Generar Archivo binario\n"
					"9.Cargar archivo Binario\n"
					"10.Guardar archivos .csv\n"
					"11.Salir");
			  if(utn_getNumeroInt(&option,"\nElija una opcion:", "\nERROR INGRESE UN NUMERO.\n", 1,11,9) == 1)
			  {
					switch(option)
					{
						case 1:
							if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1 && controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) == 1 && archivos !=1)
							{
								printf("\nSe realizo la lista con exito");
								todoOk = 1;
								archivos = 1;
							}
							else
							{
								if(archivos == 1)
								{
									printf("\n ya se cargaron los archivos antes");
								}
								else
								{
									printf("\nERROR AL REALIZAR LA LISTA DE JUGADORES Y SELECCION ");
								}
							}

							break;
						case 2:
							if(controller_agregarJugador(listaJugadores) == 1 && archivos == 1)
							{
								printf("\nSe dio de alta con exito");

								banderaDos = 0;
								todoOk = 1;
							}
							else
							{
								printf("Error al dar de alta o archivos no cargados");
							}

							break;
						case 3:
							if(tamanio > 0 && archivos == 1)
							{
								if(controller_listarJugadores(listaJugadores,listaSelecciones))
								{

										if(controller_editarJugador(listaJugadores) == 1)
										{

											todoOk= 1;
											banderaDos = 0;
										}
										else
										{
											printf("\nERROR AL MODIFICAR");
										}

								}
								else
								{
									printf("\nError al listar los jugadores");
								}
							}
							else
							{
								printf("\nTiene que dar de alta o cargar los archivos");
								todoOk= 1;
							}

							break;
						case 4:

								if(tamanio > 0 && archivos == 1)
								{
									if(controller_listarJugadores(listaJugadores,listaSelecciones) == 1)
									{
										if(controller_removerJugador(listaJugadores) == 1)
										{
											if(restarConvocados(listaSelecciones) == 1)
											{
												banderaDos = 0;
												printf("\nse dio de baja con exito");
												todoOk = 1;
											}
											else
											{
												printf("\nfunciona mas restar convocados");
											}

										}
										else
										{
											printf("\nERROR AL DAR DE BAJA");
										}
									}
									else
									{
										printf("\nError al listar los jugadores");
									}

								}
								else
								{
									printf("\nTiene que dar de alta o cargar los archivos");
								}


							break;
						case 5:
							if(tamanio >0 && archivos == 1)
							{
								if(controller_ListarTodo(listaJugadores,  listaSelecciones) == 1)
								{
									printf("\nSe realizo con exito la lista");
									todoOk = 1;
								}
								else
								{
									printf("\nError al listar los juegadores");
								}
							}
							else
							{
								printf("\nTiene que dar de alta o cargar los archivos primero");
							}

							break;
						case 6:
							if(archivos == 1)
							{
								if(controller_convocados(listaJugadores, listaSelecciones) == 1)
								{
									printf("\nfunciona todo correcto");
									todoOk = 1;
								}
								else
								{
									printf("\nError");
								}
							}
							else
							{
								printf("\nTiene que Cargar los archivos primero");
							}
							break;
						case 7:
							if(archivos == 1)
							{
								if(controller_ordenarJugadores(listaJugadores, listaSelecciones) == 1)
								{
									printf("\nSe realizo con exito la lista");
									todoOk = 1;
								}
								else
								{
									printf("\nError al listar los juegadores");
								}
							}
							else
							{
								printf("\nTiene que cargar los archivos primero");
							}
							break;
						case 8:
							if(archivos == 1)
							{
								if(controller_generarBinario(listaJugadores, listaSelecciones) == 1)
								{
									printf("\nSe guardo con exito el archivo");
									todoOk = 1;
								}
								else
								{
									printf("\nNo hay jugadores convocados");
								}
							}
							else
							{
								printf("\nTiene cargar los archivos primero");
							}
							break;
						case 9:
						if(controller_cargarJugadoresDesdeBinario("convocadosLista.bin", convocados) == 0)
						{
							if(controller_listarJugadores(convocados,listaSelecciones)==1)
							{
								printf("archivo generado con exito");
								todoOk= 1;
							}
						}
						else
						{
							printf("\nTiene que generar el archivo binario primero");
						}
						ll_clear(convocados);
							break;
						case 10:
							if(archivos != 1)
							{
								if(utn_getCharSeguir(&confirma,"\nSeguro que quiere guardar sin cargar los archivos ? s o n", "\nERROR", 9) == 1)
								{
									if(confirma == 's')
									{
										if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 1)
										{
											banderaDos = 1;
											cargarIdJugadorArchivo();
											printf("\nSe guardo todo correctamente");
										}
										else
										{
											todoOk = 0;
											printf("\nerror, al guardar los archivos");
										}

									}
									else
									{
										if(confirma == 'n')
										{
											printf("\nVolviendo a menu");
											todoOk=0;
										}
									}
								}
							}
							else
							{
								if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 1 && controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones) == 1)
								{
									banderaDos = 1;
									cargarIdJugadorArchivo();
									todoOk = 1;
									printf("\nSe guardo todo correctamente");
								}
								else
								{
									printf("\nerror, al guardar los archivos");
								}
							}
							break;
						case 11:
							if(banderaDos == 0)
							{
								if(utn_getCharSeguir(&confirma,"\nSeguro que quiere salir sin guardar los archivos ? s o n", "\nERROR", 90) == 1)
								{
									if(confirma == 's')
									{
										printf("Saliendo");
									}
									else
									{
										if(confirma == 'n')
										{
											option = 0;
										}
									}
								}
							}
							printf("Saliendo");
							break;
					}
			  }
		}while(option != 11 && todoOk !=0);
	}
	else
	{
		printf("\nERROR AL CARGAR EL ID");
	}
	return 0;
}

