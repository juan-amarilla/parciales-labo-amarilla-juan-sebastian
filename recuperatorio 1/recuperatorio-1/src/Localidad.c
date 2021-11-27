//amarilla juan sebastian 1C

#include "Localidad.h"

void definirLocalidades(eLocalidad listaLocalidad[], int tam)
{
	int i;

	eLocalidad auxiliar[TAM_LOCALIDAD] = {{10,"Rawson", OCUPADO},
			                              {20,"Saavedra", OCUPADO},
			                              {30,"Santa Rosa", OCUPADO}};

	for(i = 0; i<tam; i++)
	{
		if(auxiliar[i].isEmpty == OCUPADO)
		{
			listaLocalidad[i] = auxiliar[i];
		}
	}

}

void imprimirMenuLocalidad(eLocalidad listaLocalidad[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		if(listaLocalidad[i].isEmpty == OCUPADO)
		{
			printf("%d-%s \n", (i+1), listaLocalidad[i].localidad);
		}

	}

}

void pedirUnaLocalidad(eLocalidad listaLocalidad[], int tam, int* id)
{
	int i;
	int opcion;
	char cadena[TAM_CARACTER];

	imprimirMenuLocalidad(listaLocalidad, tam);

	pedirEnteroValidado(cadena, "Ingrese la localidad: \n", &opcion, TAM_CARACTER);

	for(i = 0; i<tam; i++)
	{
		if(opcion == (i+1) && id != NULL)
		{
			*id = listaLocalidad[i].id;
		}

	}

}

int recorrerLocalidad(eLocalidad listaLocalidad[], int tam, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(listaLocalidad[i].id == id && listaLocalidad[i].isEmpty == OCUPADO)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}
