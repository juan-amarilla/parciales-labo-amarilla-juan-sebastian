//amarilla juan sebastian 1C

#include "NexoInformes.h"

void mostrarCliente(eCliente unCliente, eLocalidad unaLocalidad, int cantidadPendiente)
{
	 printf("%5d  %12s %22s %20s %20s %20d \n\n", unCliente.id,
			                                      unCliente.nombre,
												  unCliente.cuit,
												  unCliente.direccion,
												  unaLocalidad.localidad,
												  cantidadPendiente);

}

void mostrarPedido(ePedido unPedido, eCliente unCliente)
{
	printf("%12s %20s %16.1f \n\n",  unCliente.cuit,
								   unCliente.direccion,
								   unPedido.kilo);

}

void mostrarCantidadPedidosPendientesPorUnaLocalidad(int cantidad, char localidad[])
{
	printf("La localidad %s tiene de cantidad pedidos pendientes: %d \n", localidad, cantidad);

}

void mostrarPromedioDePP(float total)
{
	printf("El promedio de PP es: %.2f \n", total);

}
