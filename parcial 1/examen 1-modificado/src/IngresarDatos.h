//amarilla juan sebastian 1C

#ifndef INGRESARDATOS_H_
#define INGRESARDATOS_H_

#include "Validaciones.h"

/// @fn void pedirEnteroValidado(char[], char[], int*, int)
/// @brief su funcion es ingresar un entero validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param int* numero
/// @param int tamArray
void pedirEnteroValidado(char cadena[], char mensaje[], int* numero, int tamArray);

/// @fn void pedirCuitValidado(char[], char[], int*, int)
/// @brief su funcion es ingresar un cuit validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param char cuit[]
void pedirCuitValidado(char cadena[], char mensaje[], char cuit[]);

/// @fn void pedirNombre(char[], char[], char[], int)
/// @brief su funcion es ingresar un nombre validado
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param char nombre[]
/// @param int tamArray
void pedirNombre(char cadena[], char mensaje[], char nombre[], int tamArray);

/// @fn void pedirDireccion(char[], char[], char[], int)
/// @brief su funcion es ingresar una direccion valida
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param char direccion[]
/// @param int tamArray
void pedirDireccion(char cadena[], char mensaje[], char direccion[], int tamArray);

/// @fn void pedirFlotanteValidado(char[], char[], float*, int)
/// @brief su funcion es ingresar un flotante valido
///
/// @param char cadena[]
/// @param char mensaje[]
/// @param float* numero
/// @param int tamArray
void pedirFlotanteValidado(char cadena[], char mensaje[], float* numero, int tamArray);

#endif /* INGRESARDATOS_H_ */
