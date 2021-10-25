//amarilla juan sebastian 1C

#include "Cliente.h"

int inicializarClientes(eCliente listaCliente[], int tam)
{
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		listaCliente[i].isEmpty = VACIO;
		listaCliente[i].contadorPendiente = 0;
		listaCliente[i].contadorProcesado = 0;
		retorno = 1;
	}

	return retorno;
}

void verificarCuit(char cadena[], eCliente listaCliente[])
{
	int i;
	char cadenaAux[TAM_CARACTER];

	for(i=0;i<TAM_CLIENTE;i++)
	{
		while(comparacionCadena(cadena, listaCliente[i].cuit) == 0 && buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			pedirCuitValidado(cadenaAux,"Error, ingrese un cuit no existente incluyendo los guiones: \n", cadena);
		}

		break;

	}

}

void verificarNombre(char cadena[], eCliente listaCliente[])
{
	int i;
	char cadenaAux[TAM_CARACTER];

	for(i=0;i<TAM_CLIENTE;i++)
	{
		while(comparacionCadena(cadena, listaCliente[i].nombre) == 0 && buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			pedirNombre(cadenaAux, "Error, Ingrese nombre no existente: \n", cadena, TAM_CARACTER);
			mayusculasAutomaticos(cadena, TAM_CARACTER);
		}

		break;

	}

}

int altaCliente(eCliente listaCliente[], int tamClien, eLocalidad listaLocalidad[], int tamLocal, char cadena[], int id)
{
	int retorno;
	int i;

	for(i=0;i<tamClien;i++)
	{
		retorno = altaClienteParte2(listaCliente[i], listaLocalidad, tamLocal, listaCliente, cadena, id);
		break;

	}

	return retorno;
}

int altaClienteParte2(eCliente listaCliente, eLocalidad listaLocalidad[], int tamLocal, eCliente lista[], char cadena[], int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tamLocal;i++)
	{
		retorno = 0;

		if(buscarLibre(listaCliente.isEmpty) != OCUPADO)
		{
			pedirCliente(listaCliente, listaLocalidad[i], cadena, id, lista);
			retorno = 1;
			break;

		}

	}

	return retorno;

}

eCliente pedirCliente(eCliente listaCliente, eLocalidad listaLocalidad, char cadena[], int id, eCliente lista[])
{
	listaCliente.id = id;
	listaLocalidad.id = id;
	pedirNombre(cadena, "Ingrese nombre: \n", listaCliente.nombre, TAM_CARACTER);
	mayusculasAutomaticos(listaCliente.nombre, TAM_CARACTER);
	verificarNombre(listaCliente.nombre, lista);
	pedirCuitValidado(cadena,"Ingrese cuit incluyendo los guiones: \n", listaCliente.cuit);
	verificarCuit(listaCliente.cuit, lista);
	pedirDireccion(cadena, "Ingrese direccion: \n", listaCliente.direccion, TAM_CARACTER);
	pedirLocalidad(cadena, "Ingrese localidad: \n", listaLocalidad.localidad, TAM_CARACTER);
	mayusculasAutomaticos(listaCliente.direccion, TAM_CARACTER);
	mayusculasAutomaticos(listaLocalidad.localidad, TAM_CARACTER);
	listaLocalidad.isEmpty = OCUPADO;
	listaCliente.isEmpty = OCUPADO;

	return listaCliente;
}

void imprimirMenuIdClienteEstructura(eCliente listaCliente[], int tam)
{
	int i;

	printf("______________________ \n");
	printf("|ID DE CLIENTES       | \n");
	printf("ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ\n");

	for(i=0;i<tam;i++)
	{
		if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			 printf(" %8d \n", listaCliente[i].id);
		}

	}

}

int modificarCliente(eCliente listaCliente[], int tamClien, eLocalidad listaLocalidad[], int tamLocal, char cadena[])
{
	int retorno;
	int seguro;

	retorno = -1;

	pedirEnteroValidado(cadena, "żEsta seguro de modificar? ingrese el numero 1-SI o (distinto a uno)-NO \n", &seguro, TAM_CARACTER);

	if(seguro == 1)
	{
		retorno = modificarUnDatoDeCliente(listaCliente, tamClien, listaLocalidad, tamLocal, cadena);

	}

	else
	{
		printf("La modificacion no se logro. \n");
	}

	return retorno;

}

int modificarUnDatoDeCliente(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal, char cadena[])
{
	int i;
	int retorno;
	int id;

	imprimirMenuIdClienteEstructura(listaCliente, tam);
	pedirEnteroValidado(cadena, "Ingrese la id para la modificacion: \n", &id, TAM_CARACTER);

	for(i=0;i<tam;i++)
	{
		retorno = modificarUnDatoDeClienteParte2(listaCliente[i], listaCliente, listaLocalidad, tamLocal, cadena, id);

	}

    return retorno;

}

int modificarUnDatoDeClienteParte2(eCliente listaCliente, eCliente lista[], eLocalidad listaLocalidad[], int tamLocal, char cadena[], int id)
{
	int i;
	int retorno;
	int opcion;

	retorno = -1;

	for(i=0;i<tamLocal;i++)
	{
		retorno = 0;

		if(listaCliente.id == id && listaLocalidad[i].id == id && buscarLibre(listaCliente.isEmpty) != VACIO && buscarLibre(listaLocalidad[i].isEmpty) != VACIO)
		{

			retorno = -1;
			do
			{
				printf("1-Modificar direccion. \n");
				printf("2-Modificar localidad. \n");
				printf("3-Salir. \n");
				pedirEnteroValidado(cadena, "Ingrese una opcion: \n", &opcion, TAM_CARACTER);

				retorno = opcionDeModificarCliente(opcion, cadena, lista, i, retorno, listaLocalidad[i]);

			} while (opcion != 3);

			break;
		}

	}

	return retorno;

}


int opcionDeModificarCliente(int opcion, char cadena[], eCliente listaCliente[], int i, int retorno, eLocalidad listaLocalidad)
{
	switch(opcion)
	{
		case 1:
		pedirDireccion(cadena, "Ingrese direccion: \n", listaCliente[i].direccion, TAM_CARACTER);
		mayusculasAutomaticos(listaCliente[i].direccion, TAM_CARACTER);
		retorno = 1;
		break;

		case 2:
		pedirLocalidad(cadena, "Ingrese localidad: \n", listaLocalidad.localidad, TAM_CARACTER);
		mayusculasAutomaticos(listaLocalidad.localidad, TAM_CARACTER);
		retorno = 1;
		break;

		case 3:
		printf("Saliste de manera exitosa. \n");
		break;

		default:
	    printf("La opcion debe ser uno de las 3 opciones. \n");
        break;

	}

	return retorno;

}

int bajaCliente(eCliente listaCliente[], int tam, char cadena[])
{
	int retorno;
	int seguro;

	retorno = -1;

	pedirEnteroValidado(cadena, "żEsta seguro de dar de baja? ingrese el numero 1-SI o (distinto a uno)-NO \n", &seguro, TAM_CARACTER);

	if(seguro == 1)
	{
		retorno = darDeBajaCliente(listaCliente, tam, cadena);
	}

	else
	{
		printf("No se dio de baja. \n");

	}

	return retorno;

}

int darDeBajaCliente(eCliente listaCliente[], int tam, char cadena[])
{
	int retorno;
	int i;
	int id;

	imprimirMenuIdClienteEstructura(listaCliente, tam);
	pedirEnteroValidado(cadena, "Ingrese la id para la baja: \n", &id, TAM_CARACTER);

	for(i=0;i<tam;i++)
	{
		retorno = 0;

		if(listaCliente[i].id == id && buscarLibre(listaCliente[i].isEmpty) != VACIO)
		{
			         listaCliente[i].isEmpty = VACIO;
					 retorno = 1;
					 break;
		}
	}

	return retorno;

}

int verificarIdCliente(eCliente listaCliente[], int tam, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(listaCliente[i].id == id && buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			retorno = i;
			break;
		}

	}

    return retorno;

}
