//amarilla juan sebastian 1C

#include "NexoInformes.h"

void mostrarCliente(eCliente unCliente, eLocalidad unaLocalidad)
{
	 printf("%5d  %12s %22s %20s %20s %20d \n\n", unCliente.id,
			                                      unCliente.nombre,
												  unCliente.cuit,
												  unCliente.direccion,
												  unaLocalidad.localidad,
												  unCliente.contadorPendiente);

}

void mostrarPedido(ePedido unPedido, eCliente unCliente)
{
	printf("%12s %20s %16.1f \n\n",  unCliente.cuit,
								   unCliente.direccion,
								   unPedido.kilo);

}

void mostrarPedidoProcesado(ePedido unPedido, eCliente unCliente)
{
	printf("%12s %22s %14.1f %18.1f %20.1f \n\n",  unCliente.cuit,
								                  unCliente.direccion,
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
