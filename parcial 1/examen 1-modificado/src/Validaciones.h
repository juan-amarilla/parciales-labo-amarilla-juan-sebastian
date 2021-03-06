//amarilla juan sebastian 1C

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @fn int validarNumeroEntero(int*, char[])
/// @brief su funcion es validar si el numero es entero
///
/// @param int* numeroEntero
/// @param char numero[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarNumeroEntero(int* numeroEntero, char numero[]);

/// @fn int validarCuit(char[], char[])
/// @brief su funcion es validar un cuit
///
/// @param char cadena[]
/// @param char cuit[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarCuit(char cadena[], char cuit[]);

/// @fn int validarNombre(char[], char[])
/// @brief su funcion es validar si es un nombre
///
/// @param char cadena[]
/// @param char nombre[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarNombre(char cadena[], char nombre[]);

/// @fn int validarDireccion(char[], char[])
/// @brief su funcion es validar si es una direccion
///
/// @param char cadena[]
/// @param char direccion[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarDireccion(char cadena[], char direccion[]);

/// @fn int validarNumeroFlotante(float*, char[])
/// @brief su funcion es validar un numero flotante
///
/// @param float* numeroFlotante
/// @param char numero[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarNumeroFlotante(float* numeroFlotante, char numero[]);

#endif /* VALIDACIONES_H_ */
