//amarilla juan sebastian 1C

#ifndef OTRASFUNCIONES_H_
#define OTRASFUNCIONES_H_
#define VACIO 0
#define OCUPADO 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/// @fn void mensajeEstado(int, char[], char[], char[])
/// @brief su funcion es mostrar uno de los tres mensajes
///
/// @param int estado
/// @param char valido[]
/// @param char errorProceso[]
/// @param char noValido[]
void mensajeEstado(int estado, char valido[], char errorProceso[], char noValido[]);

/// @fn void menu()
/// @brief su funcion es mostrar un menu de opciones
void menu();

/// @fn int buscarLibre(int)
/// @brief su funcion es verificar si esta libre
///
/// @param int estado
/// @return retorna OCUPADO si salio bien o VACIO si no se encontro
int buscarLibre(int estado);

/// @fn void mayusculasAutomaticos(char[], int)
/// @brief su funcion es que una cadena se convierta en minusculas y por cada espacio, luego del espacio el caracter un mayusculas se transforma
///
/// @param char cadena[]
/// @param int tam
void mayusculasAutomaticos(char cadena[], int tam);

/// @fn int comparacionCadena(char[], char[])
/// @brief su funcion es comparar dos cadenas
///
/// @param char cadenaUno[]
/// @param char cadenaDos[]
/// @return retorna 0 si son iguales, menor a 0 si la cadena uno es menor que la otra cadena o mayor a 0 pero de forma contraria
int comparacionCadena(char cadenaUno[], char cadenaDos[]);

#endif /* OTRASFUNCIONES_H_ */
