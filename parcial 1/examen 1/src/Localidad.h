//amarilla juan sebastian 1C

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#define TAM_CARACTER 51
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char localidad[TAM_CARACTER];
	int isEmpty;

}eLocalidad;

int inicializarLocalidad(eLocalidad listaLocalidad[], int tam);

#endif /* LOCALIDAD_H_ */
