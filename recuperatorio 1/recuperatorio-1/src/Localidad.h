//amarilla juan sebastian 1C

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define TAM_CARACTER 51
#include "OtrasFunciones.h"
#include "IngresarDatos.h"
#define TAM_LOCALIDAD 3
#define OCUPADO 1
#define VACIO 0

typedef struct
{
	int id;
	char localidad[TAM_CARACTER];
	int isEmpty;

}eLocalidad;

void definirLocalidades(eLocalidad listaLocalidad[], int tam);

void imprimirMenuLocalidad(eLocalidad listaLocalidad[], int tam);

void pedirUnaLocalidad(eLocalidad listaLocalidad[], int tam, int* id);

int recorrerLocalidad(eLocalidad listaLocalidad[], int tam, int id);

#endif /* LOCALIDAD_H_ */
