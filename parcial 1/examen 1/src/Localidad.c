//amarilla juan sebastian 1C

#include "Localidad.h"

int inicializarLocalidad(eLocalidad listaLocalidad[], int tam)
{
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		listaLocalidad[i].isEmpty = VACIO;
		retorno = 1;
	}

	return retorno;
}
