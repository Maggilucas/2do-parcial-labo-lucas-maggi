

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief pregunta al usuario si desea terminar una tarea o el programa
///
/// @param pVariable es la variable que va a recibir la funcion y cargar la respuesta
/// @param confirma si el usuario ingresa s confirmara la salida
/// @param rechaza si el usuario ingresa n rechazara la salida del programa
/// @return
int confirmarSalida(char* pVariable, char confirma, char rechaza);

/// @brief valida el ingreso de numeros enteros permitiendo que no se ingresen letras
///
/// @param pResultado es la variable a la que se le cargara el valor ingresado
/// @param mensaje es el mensaje de la funcion al pedir el dato
/// @param mensajeError es el mensaje en caso que no ingrese un numero
/// @param minimo el numero minimo aceptado
/// @param maximo el numero maximo aceptado
/// @param reintentos cantidad de veses que ingresan un caracter invalido
/// @return
int utn_getNumeroInt ( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);
int getInt ( int * pResultado);
int esNumericaInt ( char * cadena);
int myGets ( char * cadena, int longitud);
/// @brief valida el ingreso de numeros float permitiendo que no se ingresen letras
///
/// @param pResultado es la variable a la que se le cargara el valor ingresado
/// @param mensaje es el mensaje de la funcion al pedir el dato
/// @param mensajeError es el mensaje en caso que no ingrese un numero
/// @param minimo el numero minimo aceptado
/// @param maximo el numero maximo aceptado
/// @param reintentos cantidad de veses que ingresan un caracter invalido
/// @return
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);
int esNumericaFloat ( char * cadena);
int getFloat ( float * pResultado);

/// @brief valida el ingreso de una cadena de caracteres sin incluir numeros
///
/// @param pResultado es la variable a la que se le cargara el valor ingresado
/// @param mensaje es el mensaje de la funcion al pedir el dato
/// @param mensajeError es el mensaje en caso que no ingrese letras
/// @param reintentos cantidad de veses que ingresan un caracter invalido
/// @return
int utn_getChar ( char * pResultado, char * mensaje, char * mensajeError, int reintentos);
int getChar ( char * pResultado);
int esNumericaChar ( char * cadena);
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos);
/// @brief valida el ingreso de un numero short sin aceptar letras
///
/// @param pResultado es la variable a la que se le cargara el valor ingresado
/// @param mensaje es el mensaje de la funcion al pedir el dato
/// @param mensajeError es el mensaje en caso que no ingrese un numero
/// @param minimo el numero minimo aceptado
/// @param maximo el numero maximo aceptado
/// @param reintentos cantidad de veses que ingresan un caracter invalido
/// @return
int utn_getNumeroShort ( short * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);




#endif /* VALIDACIONES_H_ */
