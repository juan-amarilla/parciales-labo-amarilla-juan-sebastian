//amarilla juan sebastian 1C

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define TAM_CARACTER 51
#include "OtrasFunciones.h"
#include "IngresarDatos.h"

typedef struct
{
	char localidad[TAM_CARACTER];

}eLocalidad;

/// @fn eLocalidad pedirUnaLocalidad(eLocalidad, char[])
/// @brief su funcion es pedir una localidad
///
/// @param eLocalidad listaLocalidad
/// @param char cadena[]
/// @return retorna el dato ingresado
eLocalidad pedirUnaLocalidad(eLocalidad listaLocalidad, char cadena[]);

#endif /* LOCALIDAD_H_ */
