//amarilla juan sebastian 1C

#include "NexoInformes.h"

void mostrarCliente(eCliente unCliente, eLocalidad unaLocalidad, int cantidadPendiente)
{

	 printf("|%5d\t\t|%12s\t\t|%18s\t|%17s\t|%17s\t|%18d\t\t|\n", unCliente.id,
                                                                  unCliente.nombre,
			                                                      unCliente.cuit,
			                                                      unCliente.direccion,
			                                                      unaLocalidad.localidad,
			                                                      cantidadPendiente);

}

void mostrarPedido(ePedido unPedido, eCliente unCliente)
{
	printf("|%13s\t|%15s\t|%16.1f\t|\n", unCliente.cuit,
			                                 unCliente.direccion,
			                                 unPedido.kilo);

}

void mostrarPedidoProcesado(ePedido unPedido, char cuit[], char direccion[])
{
	printf("|%12s\t\t|%17s\t|%14.1f\t\t|%15.1f\t|%18.1f     |\n",  cuit,
                                                                              direccion,
                                                                              unPedido.HDPE,
                                                                              unPedido.LDPE,
                                                                              unPedido.PP);

}

void mostrarCantidadPedidosPendientesPorUnaLocalidad(int cantidad, char localidad[])
{
	printf("La localidad %s tiene de cantidad pedidos pendientes: %d \n", localidad, cantidad);

}

void mostrarPromedioDePP(float total)
{
	printf("El promedio de PP es: %.2f \n", total);

}

void mostrarMayor(eCliente listaCliente[], int tam, int contador[], int maximo)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(contador[i] == maximo && buscarLibre(listaCliente[i].isEmpty) == OCUPADO)
		{
			printf("El cliente %s tiene como maxima cantidad de pedidos: %d \n", listaCliente[i].nombre, maximo);
		}

	}

}
