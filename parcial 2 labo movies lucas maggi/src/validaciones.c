#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int confirmarSalida(char* pVariable, char confirma, char rechaza)
{

    int todoOk = 0;
    char rta;

    if(pVariable != NULL)
    {
        printf("Esta seguro de que desea salir?: s/n \n ");
        fflush(stdin);
        scanf("%c", &rta);

        if(rta == 's')
        {
            *pVariable = confirma;
			todoOk = 1;
            printf("tarea finalizada!");
        }
        else
        {
            *pVariable = rechaza;
        }

    }
    return todoOk;
}

int utn_getNumeroInt (int* pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getInt(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaInt(buffer) == 1)
		{
			*pResultado = atoi (buffer);
			retorno = 1;
		}
	}
	return retorno;

}
int esNumericaInt ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;

}
int myGets ( char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
}
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	float aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getFloat(&aux)==1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}

			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}
int esNumericaFloat ( char * cadena)
{
	int retorno;
	int contadorPunto = 0;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while(cadena[i] != '\0')
		{

			if (cadena[i] == '/' || cadena[i] < '.' || cadena[i] > '9' || contadorPunto > 1 )
			{
				retorno = -1;
				break ;
			}
			if(cadena[i] == '.')
			{
				contadorPunto++;
			}
			i++;
		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
int getFloat ( float * pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaFloat(buffer) == 1)
		{
			*pResultado = atof (buffer);
			retorno = 1;
		}
	}
	return retorno;
}
int utn_getChar ( char * pResultado, char * mensaje, char * mensajeError, int reintentos)
{
	char aux[200];
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getChar(aux)==1)
			{
				strcpy(pResultado,aux);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}
int getChar ( char * pResultado)
{
	int retorno = -1;
	char buffer[200];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaChar(buffer) == 1)
		{
			strcpy(pResultado,buffer);
			retorno = 1;
		}
	}
	return retorno;

}
int esNumericaChar ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = 1;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] >= '0' && cadena[i] <= '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}

	}
	else
	{
		retorno = -1;
	}
	return retorno;

}
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos)
{
	char aux[200];
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getChar(aux)==1)
			{
				aux[0]= tolower(aux[0]);
				if(aux[0] == 's' || aux[0] == 'n')
				{
					*pResultado = aux[0];
					retorno = 1;
					break;
				}

			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}
int utn_getNumeroShort ( short * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int retorno = -1;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getInt(&aux)== 1)
			{
				if (aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}

