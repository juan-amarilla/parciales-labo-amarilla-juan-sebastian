//amarilla juan sebastian 1C

#include "Nexo.h"

eAuxiliar inicializarId(eAuxiliar auxiliar)
{

    auxiliar.idCliente = 0;
    auxiliar.idPedido = 0;

	return auxiliar;
}

eAuxiliar inicializarAuxiliar(eAuxiliar auxiliar)
{

    auxiliar.contador = 0;
    auxiliar.acumulador = 0;

    return auxiliar;
}

void inicializarAuxiliarArray(eAuxiliar auxiliar[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		auxiliar[i].contador = 0;
		auxiliar[i].acumulador = 0;

	}
}

int verificarId(int estado, int id)
{
	if(estado == 0 || estado == -1)
	{
		id--;

	}

	return id;

}

int crearPedido(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int id)
{
	int retorno;

	retorno = lograrPedido(listaPedido, tamPedi, listaCliente, tamClien, id);

	return retorno;

}


int lograrPedido(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int id)
{
	int retorno;
	int i;
	int j;
	int idCliente;
	char cadena[TAM_CARACTER];

	retorno = -1;

	imprimirMenuIdClienteEstructura(listaCliente, tamClien);
	pedirEnteroValidado(cadena, "Ingrese una id existente de cliente: \n", &idCliente, TAM_CARACTER);
	j = verificarIdCliente(listaCliente, tamClien, idCliente);

	if(j != -1)
	{
		for(i=0;i<tamPedi;i++)
		{
			retorno = 0;

			if(listaPedido[i].isEmpty != PENDIENTE)
			{
				listaPedido[i].id = id;
				pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg a recolectar. \n", &listaPedido[i].kilo, TAM_CARACTER);
				listaPedido[i].idCliente = listaCliente[j].id;
				listaCliente[j].contadorPendiente++;
				listaPedido[i].isEmpty = PENDIENTE;
				retorno = 1;
				break;

			}

		}

	}

	return retorno;

}

int procesarResiduos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;

	retorno = lograrProcesoDeResiduos(listaPedido, tamPedi, listaCliente, tamClien);

	return retorno;

}

int lograrProcesoDeResiduos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;
	int i;
	int j;
	int id;
	float kiloTotal;
	char cadena[TAM_CARACTER];

	retorno = -1;

	imprimirMenuIdPedidoEstructura(listaPedido, tamPedi);
	pedirEnteroValidado(cadena, "Ingrese la id existente: \n", &id, TAM_CARACTER);
	i = verificarIdPedido(listaPedido, tamPedi , id);
	j = verificarIdCliente(listaCliente, tamClien, listaPedido[i].idCliente);

	if(i != -1 && j != -1 && retorno == -1)
	{
		retorno = 0;

		pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de HDPE \n", &listaPedido[i].HDPE, TAM_CARACTER);
		pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de LDPE \n", &listaPedido[i].LDPE, TAM_CARACTER);
		pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de PP \n", &listaPedido[i].PP, TAM_CARACTER);

		kiloTotal = listaPedido[i].HDPE + listaPedido[i].LDPE + listaPedido[i].PP;

		if(kiloTotal <= listaPedido[i].kilo)
		{
			listaPedido[i].kilo = 0;
			listaCliente[j].contadorPendiente--;
			listaCliente[j].contadorProcesado++;
			listaPedido[i].isEmpty = COMPLETADO;
			retorno = 1;

		}

	}

	return retorno;

}

int mostrarClientes(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal)
{
	int retorno;
	int i;

	for(i=0;i<tam;i++)
	{
		retorno = lograrMostrarClientes(listaCliente[i], listaLocalidad, tamLocal);
	}

	return retorno;

}

int lograrMostrarClientes(eCliente listaCliente, eLocalidad listaLocalidad[], int tamLocal)
{
	int i;
	int retorno;

	retorno = -1;

	printf(" ____________________________________________________________________________________________________________________\n");
	printf("|ID       |NOMBRE          |CUIT               |DIRECCION            |LOCALIDAD         | CANTIDAD PEDIDOS PENDIENTES|\n");
	printf("ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ\n");

	for(i=0;i<tamLocal;i++)
	{
		if(i == 0)
		{
			retorno = 0;
		}

		if(buscarLibre(listaCliente.isEmpty) == OCUPADO && buscarLibre(listaLocalidad[i].isEmpty) == OCUPADO)
		{
			if(listaCliente.id == listaLocalidad[i].id)
			{
				mostrarCliente(listaCliente, listaLocalidad[i]);
			}

			if(retorno == 0)
			{
			  retorno = 1;
			}

		}

	}

	return retorno;

}

int mostrarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;

	retorno = lograrMostrarPedidos(listaPedido, tamPedi, listaCliente, tamClien);

	return retorno;

}

int lograrMostrarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int i;
	int j;
	int retorno;

	retorno = -1;

	printf(" ____________________________________________________________________\n");
	printf("|CUIT               |DIRECCION            |Kg A RECOLECTAR           |\n");
	printf("ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ\n");

	for(i=0;i<tamPedi;i++)
	{
		j = verificarIdCliente(listaCliente, tamClien, listaPedido[i].idCliente);

		if(i == 0)
		{
			retorno = 0;
		}

		if(listaPedido[i].isEmpty == PENDIENTE && j != -1)
		{
				mostrarPedido(listaPedido[i], listaCliente[j]);

				if(retorno == 0)
				{
					retorno = 1;
				}

		}

	}

	return retorno;

}

int mostrarPedidosProcesados(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;

	retorno = lograrMostrarPedidosProcesados(listaPedido, tamPedi, listaCliente, tamClien);

	return retorno;
}

int lograrMostrarPedidosProcesados(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int i;
	int j;
	int retorno;

	retorno = -1;

	printf(" _____________________________________________________________________________________________________\n");
	printf("|CUIT               |DIRECCION            |Kg DE HDPE           |Kg DE LDPE          |Kg DE PP        |\n");
	printf("ŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻŻ\n");

	for(i=0;i<tamPedi;i++)
	{
		j = verificarIdCliente(listaCliente, tamClien, listaPedido[i].idCliente);

		if(i == 0)
		{
			retorno = 0;
		}

		if(listaPedido[i].isEmpty == COMPLETADO && j != -1)
		{
			mostrarPedidoProcesado(listaPedido[i], listaCliente[j]);

			if(retorno == 0)
			{
			  retorno = 1;
			}

		}

	}

	return retorno;

}

int cantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal)
{
	int retorno;
	int i;

	for(i=0;i<tam;i++)
	{
		retorno = lograrCantidadPedidosPendientesPorUnaLocalidad(listaCliente[i], listaLocalidad, tamLocal);
	}

	return retorno;

}

int lograrCantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente, eLocalidad listaLocalidad[], int tam)
{
	int retorno;
	int i;
	char cadena[TAM_CARACTER];
    char localidad[TAM_CARACTER];
    eAuxiliar auxiliar;

	retorno = -1;

	auxiliar = inicializarAuxiliar(auxiliar);
	pedirLocalidad(cadena, "Ingrese una localidad: \n", localidad, TAM_CARACTER);
	mayusculasAutomaticos(localidad, TAM_CARACTER);

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
			retorno = 0;
		}

       if(comparacionCadena(localidad, listaLocalidad[i].localidad) == 0 && buscarLibre(listaLocalidad[i].isEmpty) == OCUPADO)
       {
    	   auxiliar.contador += listaCliente.contadorPendiente;

    	   if(retorno == 0)
    	   {
    	   	  retorno = 1;
    	   }
       }

	}

	if(retorno == 1)
	{
		mostrarCantidadPedidosPendientesPorUnaLocalidad(auxiliar.contador, localidad);
	}

	return retorno;

}

int sacarPromedioDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;

	retorno = lograrSacarPromedioDePP(listaPedido, tamPedi, listaCliente, tamClien);

	return retorno;

}

int lograrSacarPromedioDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien)
{
	int retorno;
    eAuxiliar auxiliar;
    float total;

    total = 0;

    auxiliar = inicializarAuxiliar(auxiliar);

    retorno = ContarAcumularDePP(listaPedido, tamPedi, listaCliente, tamClien, &auxiliar.contador, &auxiliar.acumulador);

    if(auxiliar.contador > 0)
    {
    	total = auxiliar.acumulador / auxiliar.contador;
    	mostrarPromedioDePP(total);
    }

	return retorno;

}

int ContarAcumularDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int* contador, float* acumulador)
{
	int i;
	int retorno;

	for(i=0;i<tamClien;i++)
    {
		contarDePP(listaPedido, tamPedi, contador, listaCliente[i].id);
    }

    retorno = acumularPP(listaPedido, tamPedi, acumulador);


   return retorno;

}

void contarDePP(ePedido listaPedido[], int tam, int* contador, int id)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(listaPedido[i].idCliente == id && listaPedido[i].isEmpty == COMPLETADO)
		{
			*contador += 1;
			break;

		}

	}

}

int acumularPP(ePedido listaPedido[], int tam, float* acumulador)
{
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
			retorno = 0;
		}

		if(listaPedido[i].isEmpty == COMPLETADO)
		{
            *acumulador += listaPedido[i].PP;

            if(retorno == 0)
            {
            	retorno = 1;
            }
		}

	}

	return retorno;

}

int pedidosPendiente(eCliente listaCliente[], int tam)
{
	int i;
	int maximo;
	int flag;
	int retorno;
	char nombre[TAM_CARACTER];

	flag = 0;
	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(retorno == -1)
		{
			retorno = 0;
		}

		if((listaCliente[i].isEmpty == OCUPADO && flag == 0) || (maximo < listaCliente[i].contadorPendiente && flag == 1))
		{
			maximo = listaCliente[i].contadorPendiente;
			strcpy(nombre, listaCliente[i].nombre);

			if(flag == 0 && retorno == 0)
			{
				flag = 1;
				retorno = 1;
			}
		}

	}

	if(retorno == 1)
	{
		printf("El cliente %s es el que tiene mas pedidos pendientes: %d \n", nombre, maximo);

	}

	return retorno;

}

int pedidosCompletados(eCliente listaCliente[], int tam)
{
	int i;
	int maximo;
	int flag;
	int retorno;
	char nombre[TAM_CARACTER];

	flag = 0;
	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(retorno == -1)
		{
			retorno = 0;
		}

		if((listaCliente[i].isEmpty == OCUPADO && flag == 0) || (maximo < listaCliente[i].contadorProcesado && flag == 1))
		{
			maximo = listaCliente[i].contadorProcesado;
			strcpy(nombre, listaCliente[i].nombre);

			if(flag == 0 && retorno == 0)
			{
				flag = 1;
				retorno = 1;
			}
		}

	}

	if(retorno == 1)
	{
		printf("El cliente %s es el que tiene mas pedidos procesados: %d \n", nombre, maximo);

	}

	return retorno;

}

int pedidos(eCliente listaCliente[], int tam)
{
	int i;
	int maximo;
	int flag;
	int retorno;
	char nombre[TAM_CARACTER];
	eAuxiliar auxiliar[TAM_CLIENTE];

	flag = 0;
	retorno = -1;

	inicializarAuxiliarArray(auxiliar, tam);

	for(i=0;i<tam;i++)
	{
		if(retorno == -1)
		{
			retorno = 0;
		}

		auxiliar[i].contador = listaCliente[i].contadorProcesado + listaCliente[i].contadorPendiente;

		if((listaCliente[i].isEmpty == OCUPADO && flag == 0) || (maximo < auxiliar[i].contador && flag == 1))
		{
			maximo = auxiliar[i].contador;
			strcpy(nombre, listaCliente[i].nombre);

			if(flag == 0 && retorno == 0)
			{
				flag = 1;
				retorno = 1;
			}
		}

	}

	if(retorno == 1)
	{
		printf("El cliente %s es el que tiene mas pedidos procesados: %d \n", nombre, maximo);

	}

	return retorno;

}
