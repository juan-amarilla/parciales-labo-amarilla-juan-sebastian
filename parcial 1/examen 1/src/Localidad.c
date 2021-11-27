//amarilla juan sebastian 1C

#include "Localidad.h"

eLocalidad pedirUnaLocalidad(eLocalidad listaLocalidad, char cadena[])
{
	pedirLocalidad(cadena, "Ingrese localidad: \n", listaLocalidad.localidad, TAM_CARACTER);
	mayusculasAutomaticos(listaLocalidad.localidad, TAM_CARACTER);

	return listaLocalidad;

}
