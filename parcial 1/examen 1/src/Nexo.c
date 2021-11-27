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

			if(listaPedido[i].isEmpty == VACIO)
			{
				listaPedido[i].id = id;
				pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg a recolectar. \n", &listaPedido[i].kilo, TAM_CARACTER);
				listaPedido[i].idCliente = listaCliente[j].id;
				listaPedido[i].contadorPendiente++;
				listaPedido[i].isEmpty = PENDIENTE;
				retorno = 1;
				break;

			}

		}

	}

	return retorno;

}

int procesarResiduos(ePedido listaPedido[], int tam)
{
	int retorno;

	retorno = lograrProcesoDeResiduos(listaPedido, tam);

	return retorno;

}

int lograrProcesoDeResiduos(ePedido listaPedido[], int tam)
{
	int retorno;
	int i;
	int id;
	float kiloTotal;
	char cadena[TAM_CARACTER];

	retorno = -1;

	imprimirMenuIdPedidoEstructura(listaPedido, tam);
	pedirEnteroValidado(cadena, "Ingrese la id existente: \n", &id, TAM_CARACTER);

    i = verificarIdPedido(listaPedido, tam, id);

	if(i != -1)
	{
	    retorno = 0;

	    pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de HDPE \n", &listaPedido[i].HDPE, TAM_CARACTER);
		pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de LDPE \n", &listaPedido[i].LDPE, TAM_CARACTER);
		pedirFlotanteValidado(cadena, "Ingrese la cantidad de Kg de PP \n", &listaPedido[i].PP, TAM_CARACTER);

		kiloTotal = listaPedido[i].HDPE + listaPedido[i].LDPE + listaPedido[i].PP;

		if(kiloTotal <= listaPedido[i].kilo)
		{
			listaPedido[i].kilo = 0;
			listaPedido[i].contadorPendiente--;
			listaPedido[i].contadorProcesado++;
			listaPedido[i].isEmpty = COMPLETADO;
			retorno = 1;

		}

	}

	return retorno;
}

int mostrarClientes(eCliente listaCliente[], eLocalidad listaLocalidad[], int tam , ePedido listaPedido[], int tamPedi)
{
	int retorno;
	int i;
	int j;
	eAuxiliar auxiliar[TAM_CLIENTE];

	printf(" ____________________________________________________________________________________________________________________\n");
	printf("|ID       |NOMBRE          |CUIT               |DIRECCION            |LOCALIDAD         | CANTIDAD PEDIDOS PENDIENTES|\n");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	retorno = -1;
	inicializarAuxiliarArray(auxiliar, tam);

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
			retorno = 0;
		}

		for(j = 0;j<tamPedi; j++)
		{
			if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO && listaCliente[i].id == listaPedido[j].idCliente)
			{
				auxiliar[i].contador += listaPedido[j].contadorPendiente;
			}

		}

		if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			mostrarCliente(listaCliente[i], listaLocalidad[i], auxiliar[i].contador);

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
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

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
	eAuxiliar auxiliar[TAM_PEDIDO];

	retorno = -1;

	printf(" _____________________________________________________________________________________________________\n");
	printf("|CUIT               |DIRECCION            |Kg DE HDPE           |Kg DE LDPE          |Kg DE PP        |\n");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	for(i = 0; i<tamPedi; i++)
	{
		if(i == 0)
		{
		   retorno = 0;
		}

		for(j = 0; j<tamClien; j++)
		{
			if(listaPedido[i].idCliente == listaCliente[j].id && buscarLibre(listaCliente[j].isEmpty) == OCUPADO &&  listaPedido[i].isEmpty == COMPLETADO)
			{
				strcpy(auxiliar[i].cuit, listaCliente[j].cuit);
				strcpy(auxiliar[i].direccion, listaCliente[j].direccion);
				break;

			}

		}

		if(listaPedido[i].isEmpty == COMPLETADO)
		{
			mostrarPedidoProcesado(listaPedido[i], auxiliar[i]);

			if(retorno == 0)
			{
				retorno = 1;
			}

		}

	}

	return retorno;

}

void mostrarPedidoProcesado(ePedido unPedido, eAuxiliar unAuxiliar)
{
	printf("%12s %22s %14.1f %18.1f %20.1f \n\n",  unAuxiliar.cuit,
			                                       unAuxiliar.direccion,
								                   unPedido.HDPE,
								                   unPedido.LDPE,
								                   unPedido.PP);

}

int cantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[] ,eLocalidad listaLocalidad[], int tam, ePedido listaPedido[], int tamPedi)
{
	int retorno;

	retorno = lograrCantidadPedidosPendientesPorUnaLocalidad(listaCliente , listaLocalidad, tam, listaPedido, tamPedi);

	return retorno;

}

int lograrCantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[] ,eLocalidad listaLocalidad[], int tam, ePedido listaPedido[], int tamPedi)
{
	int retorno;
	int i;
	int j;
	char cadena[TAM_CARACTER];
    char localidad[TAM_CARACTER];
    eAuxiliar auxiliar;

	retorno = -1;

	auxiliar = inicializarAuxiliar(auxiliar);
	pedirLocalidad(cadena, "Ingrese una localidad: \n", localidad, TAM_CARACTER);
	mayusculasAutomaticos(localidad, TAM_CARACTER);

	for(i=0;i<tamPedi;i++)
	{
	   if(i == 0)
	   {
			retorno = 0;
	   }

       if(listaPedido[i].isEmpty == PENDIENTE)
       {
    	   for(j = 0; j<tam; j++)
    	   {
    		   if(comparacionCadena(localidad, listaLocalidad[j].localidad) == 0 && buscarLibre(listaCliente[j].isEmpty) == OCUPADO && listaCliente[j].id == listaPedido[i].idCliente)
    		   {
    			  auxiliar.acumulador += listaPedido[i].contadorPendiente;

    			  if(retorno == 0)
    			  {
    			     retorno = 1;
    			  }
    		   }
    	   }
       }

	}

	if(retorno == 1)
	{
		mostrarCantidadPedidosPendientesPorUnaLocalidad(auxiliar.acumulador, localidad);
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
    retorno = -1;

    auxiliar = inicializarAuxiliar(auxiliar);

    auxiliar.contador = ContarAcumularDePP(listaPedido, tamPedi, listaCliente, tamClien, auxiliar.contador, &auxiliar.acumulador);

    if(auxiliar.contador > 0)
    {
    	retorno = 1;
    	printf("acumulador - %.2f \n", auxiliar.acumulador);
    	printf("contador - %d \n", auxiliar.contador);
    	total = auxiliar.acumulador / auxiliar.contador;
    	mostrarPromedioDePP(total);
    }

	return retorno;

}

int ContarAcumularDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int contador, float* acumulador)
{
	int i;
	int j;

	for(i=0;i<tamClien;i++)
    {
		if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			for(j=0;j<tamPedi;j++)
			{
				if(listaPedido[j].idCliente == listaCliente[i].id && listaPedido[j].isEmpty == COMPLETADO && listaPedido[j].PP > 1)
				{
					contador++;
					break;
				}
			}

		}
    }

    acumularPP(listaPedido, tamPedi, acumulador);

    return contador;
}

void acumularPP(ePedido listaPedido[], int tam, float* acumulador)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(listaPedido[i].isEmpty == COMPLETADO)
		{
            *acumulador += listaPedido[i].PP;
		}

	}

}

int pedidosPendiente(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi)
{
	int i;
	int retorno;
	eAuxiliar auxiliar[TAM_CLIENTE];
	int maximo;

	inicializarAuxiliarArray(auxiliar, tamClien);

	retorno = -1;
	maximo = 0;

	for(i=0;i<tamClien;i++)
	{
		retorno = 0;

		if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			auxiliar[i].contador = hallarPedidosDeEstado(listaPedido, tamPedi, listaCliente[i], auxiliar[i].contador, PENDIENTE);
		}
	}

    maximo = hallarMaximoDeCliente(listaCliente, tamClien, auxiliar, maximo);

	if(maximo > 0)
	{
		retorno = 1;
		mostrarMayor(listaCliente, tamClien, auxiliar, maximo);
	}

	return retorno;

}

int pedidosCompletados(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi)
{
   int i;
   int retorno;
   eAuxiliar auxiliar[TAM_CLIENTE];
   int maximo;

   inicializarAuxiliarArray(auxiliar, tamClien);

   retorno = -1;
   maximo = 0;

   for(i=0;i<tamClien;i++)
   {
	  retorno = 0;

	  if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
	  {
		 auxiliar[i].contador = hallarPedidosDeEstado(listaPedido, tamPedi, listaCliente[i], auxiliar[i].contador, COMPLETADO);
	  }
   }

   maximo = hallarMaximoDeCliente(listaCliente, tamClien, auxiliar, maximo);

   if(maximo > 0)
   {
   	 retorno = 1;
   	 mostrarMayor(listaCliente, tamClien, auxiliar, maximo);
   }

   return retorno;

}

int pedidosTotales(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi)
{
	int i;
	int retorno;
	eAuxiliar auxiliar[TAM_CLIENTE];
	int maximo;

    inicializarAuxiliarArray(auxiliar, tamClien);

	retorno = -1;
	maximo = 0;

	for(i=0;i<tamClien;i++)
	{
		retorno = 0;

		if(buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
		  auxiliar[i].contador = hallarPedidos(listaPedido, tamPedi, listaCliente[i], auxiliar[i].contador);
		}
	}

	maximo = hallarMaximoDeCliente(listaCliente, tamClien, auxiliar, maximo);

	if(maximo > 0)
	{
	   	retorno = 1;
	   	mostrarMayor(listaCliente, tamClien, auxiliar, maximo);
	}

	return retorno;

}

int hallarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente, int contador)
{
    int i;

    for(i=0;i<tamPedi;i++)
    {
    	if(listaPedido[i].idCliente == listaCliente.id)
    	{
          contador += listaPedido[i].contadorPendiente + listaPedido[i].contadorProcesado;
    	}

    }

	return contador;

}

int hallarPedidosDeEstado(ePedido listaPedido[], int tamPedi, eCliente listaCliente, int contador, int estadoActual)
{
    int i;

    for(i=0;i<tamPedi;i++)
    {
    	if(listaPedido[i].isEmpty == estadoActual && listaPedido[i].idCliente == listaCliente.id && estadoActual == PENDIENTE)
    	{
          contador += listaPedido[i].contadorPendiente;
    	}

    	else
    	{
    		if(listaPedido[i].isEmpty == estadoActual && listaPedido[i].idCliente == listaCliente.id && estadoActual == COMPLETADO)
    		{
    			contador += listaPedido[i].contadorProcesado;
    		}

    	}

    }

	return contador;

}

int hallarMaximoDeCliente(eCliente listaCliente[], int tamClien, eAuxiliar auxiliar[], int maximo)
{
	int i;

	for(i=0;i<tamClien;i++)
	{
		if((buscarLibre(listaCliente[i].isEmpty) == OCUPADO && i == 0) || (buscarLibre(listaCliente[i].isEmpty) == OCUPADO && maximo < auxiliar[i].contador))
		{
           maximo = auxiliar[i].contador;
		}

	}

	return maximo;

}

void mostrarMayor(eCliente listaCliente[], int tam, eAuxiliar auxiliar[], int maximo)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(auxiliar[i].contador == maximo && buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			printf("El cliente %s tiene como maxima cantidad de pedidos: %d \n", listaCliente[i].nombre, maximo);
		}

	}

}
