//amarilla juan sebastian 1C

#include "Pedido.h"

int inicializarPedidos(ePedido listaPedido[], int tam)
{
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		listaPedido[i].isEmpty = VACIO;
		listaPedido[i].contadorPendiente = 0;
		listaPedido[i].contadorProcesado = 0;
		retorno = 1;
	}

	return retorno;

}

int verificarPedidoExistenciaPendiente(ePedido listaPedido[], int tam)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(listaPedido[i].isEmpty == PENDIENTE)
		{
			retorno = 1;
			break;
		}

	}

	return retorno;

}

int verificarPedidoExistenciaProcesado(ePedido listaPedido[], int tam)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(listaPedido[i].isEmpty == COMPLETADO)
		{
			retorno = 1;
			break;
		}

	}

	return retorno;

}

int verificarIdPedido(ePedido listaPedido[], int tam, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(listaPedido[i].id == id && listaPedido[i].isEmpty == PENDIENTE)
		{
			retorno = i;
			break;
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


void imprimirMenuIdPedidoEstructura(ePedido listaPedido[], int tam)
{
	int i;

	printf("________________________ \n");
	printf("|ID DE PEDIDOS          |\n");
	printf("|                       |\n");

	for(i=0;i<tam;i++)
	{

		if(listaPedido[i].isEmpty == PENDIENTE)
		{
			 printf("|%8d\t\t|\n", listaPedido[i].id);
		}

	}

}
