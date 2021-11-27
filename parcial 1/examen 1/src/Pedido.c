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

void imprimirMenuIdPedidoEstructura(ePedido listaPedido[], int tam)
{
	int i;

	printf("______________________ \n");
	printf("|ID DE PEDIDOS        | \n");
	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯ \n");

	for(i=0;i<tam;i++)
	{

		if(listaPedido[i].isEmpty == PENDIENTE)
		{
			 printf(" %8d \n", listaPedido[i].id);
		}

	}

}
