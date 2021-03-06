/*
============================================================================
amarilla juan sebastian 1C

Una empresa de recolecci?n y reciclado de pl?sticos
requiere un sistema que les permita administrar sus clientes
y pedidos de recolecci?n.
El programa contar? con el siguiente men?:

1) Alta de cliente:
Se da de alta un cliente con nombre de la empresa,
cuit direcci?n y localidad.
Se generar? un ID ?nico para este cliente que se
imprimir? por pantalla si el alta es correcta.

2) Modificar datos de cliente:
Se ingresa el ID de cliente y
se permitir? cambiar la direcci?n y la localidad.

3) Baja de cliente: Se ingresa el ID del cliente.
Luego se preguntar? si se quiere confirmar la eliminaci?n.

4) Crear pedido de recolecci?n: Se imprimir?n los clientes por
pantalla y se pedir? que se ingrese el ID de un cliente
existente y la cantidad de kilos totales que se recolectar?n
del cliente.
Se generar? un ID para el pedido y
el mismo quedar? en estado ?Pendiente?
hasta que se obtengan los residuos del cliente y
se trasladen a la empresa.

5) Procesar residuos: Se elegir? esta opci?n cuando los residuos que
volvieron a la empresa se hayan procesado y separado en los diferentes
tipos de pl?stico que la empresa puede reciclar.
Se imprimir?n los pedidos por pantalla
y se pedir? seleccionar el ID de uno de ellos.
Luego deber?n ingresarse la cantidad de kilos de
pl?stico de cada uno de los 3 tipos que la empresa
puede procesar que se obtuvieron de los kilos totales
que se recolectaron.
Por ?ltimo, se marcar? al pedido como ?Completado?.

6) Imprimir Clientes:
Se imprimir? una lista de clientes con todos sus
datos junto con la cantidad de ?pedidos de recolecci?n?
que posee en estado ?Pendiente?.

7) Imprimir Pedidos pendientes: Se imprimir? una lista de
los pedidos que se encuentren en estado ?Pendiente?
con la informaci?n: Cuit del cliente,
direcci?n del cliente, cantidad de kilos a recolectar.

8) Imprimir Pedidos procesados: Se imprimir? una lista
de los pedidos que se encuentren en estado ?Completado?
con la informaci?n: Cuit del cliente, direcci?n del cliente,
cantidad de kilos reciclados de cada tipo de pl?stico.

9) Ingresar una localidad e indicar la cantidad de pedidos
pendientes para dicha localidad.

10) Cantidad de kilos de polipropileno reciclado promedio por
cliente. (kilos totales / cantidad de clientes)

-PARTE 2:

1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:

a) Cliente con m?s pedidos pendientes.
b) Cliente con m?s pedidos completados.
c) Cliente con m?s pedidos.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Nexo.h"
#define TAM_CARACTER 51

int main(void)
{
	int opcion;
	int retorno;
	int retornoCliente;
	int retornoPendiente;
	int retornoProcesado;
	char cadenaAuxiliar[TAM_CARACTER];
	eCliente listaCliente[TAM_CLIENTE];
	ePedido listaPedido[TAM_PEDIDO];
	eLocalidad listaLocalidad[TAM_LOCALIDAD];
    eAuxiliar auxiliar;

    setbuf(stdout, NULL);

    definirLocalidades(listaLocalidad, TAM_LOCALIDAD);

    auxiliar = inicializarId(auxiliar);

    retorno = inicializarClientes(listaCliente, TAM_CLIENTE);
    mensajeEstado(retorno, "Inicializacion de clientes con exito. \n", "Error, un proceso salio mal. \n", "Inicializacion de clientes sin exito. \n");

    retorno = inicializarPedidos(listaPedido, TAM_PEDIDO);
    mensajeEstado(retorno, "Inicializacion de pedidos con exito. \n", "Error, un proceso salio mal. \n", "Inicializacion de pedidos sin exito. \n");

    do
    {
    	menu();
    	pedirEnteroValidado(cadenaAuxiliar, "Ingrese una opcion: \n\n", &opcion, TAM_CARACTER);

    	switch(opcion)
    	{

    	  case 1:
    	  retorno = altaCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD, cadenaAuxiliar, &auxiliar.idCliente);
    	  mensajeEstado(retorno, "Alta con exito. \n", "Error, un proceso salio mal. \n", "Alta sin exito. \n");
    	  break;

    	  case 2:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  if(retornoCliente == 1)
    	  {
    		  retorno = modificarCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_LOCALIDAD, cadenaAuxiliar);
    		  mensajeEstado(retorno, "Modificacion con exito. \n", "Error, un proceso salio mal. \n", "Modificacion sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    	  }
    	  break;

    	  case 3:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  if(retornoCliente == 1)
    	  {
    		  retorno = bajaCliente(listaCliente, TAM_CLIENTE, cadenaAuxiliar);
    		  mensajeEstado(retorno, "Baja con exito. \n", "Error, un proceso salio mal. \n", "Baja sin exito. \n");
    	  }

    	  else
    	  {
    		 mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    	  }
    	  break;

    	  case 4:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  if(retornoCliente == 1)
    	  {
    		  retorno = crearPedido(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE, &auxiliar.idPedido);
    		  mensajeEstado(retorno, "Creacion con exito. \n", "Error, un proceso salio mal. \n", "Creacion sin exito. \n");
    	  }

    	  else
          {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    	  }
    	  break;

    	  case 5:
    	  retornoPendiente = verificarPedidoExistenciaPendiente(listaPedido, TAM_PEDIDO);
    	  if(retornoPendiente == 1)
    	  {
    		  retorno = procesarResiduos(listaPedido, TAM_PEDIDO);
    		  mensajeEstado(retorno, "Procesamiento con exito. \n", "Error, un proceso salio mal. \n", "Procesamiento sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoPendiente, "Proceso correcto. \n", "Error, un proceso salio mal. \n", "No hay pedidos pendientes. \n");
    	  }
    	  break;

    	  case 6:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  if(retornoCliente == 1)
    	  {
    		  retorno = mostrarClientes(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO, listaLocalidad, TAM_LOCALIDAD);
    		  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  }

    	  else
          {
    		 mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    	  }
    	  break;

    	  case 7:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoPendiente = verificarPedidoExistenciaPendiente(listaPedido, TAM_PEDIDO);
    	  if(retornoCliente == 1 && retornoPendiente == 1)
    	  {
    		  retorno = mostrarPedidos(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    		  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		  mensajeEstado(retornoPendiente, "Hay pedidos pendientes. \n", "Error, un proceso salio mal. \n", "No hay pedidos pendientes. \n");
    	  }
    	  break;

    	  case 8:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoProcesado = verificarPedidoExistenciaProcesado(listaPedido, TAM_PEDIDO);
          if(retornoCliente == 1 && retornoProcesado == 1)
    	  {
        	  retorno = mostrarPedidosProcesados(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
        	  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		  mensajeEstado(retornoProcesado, "Hay pedidos procesados. \n", "Error, un proceso salio mal. \n", "No hay pedidos procesados. \n");
    	  }
    	  break;

    	  case 9:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoPendiente = verificarPedidoExistenciaPendiente(listaPedido, TAM_PEDIDO);
    	  if(retornoCliente == 1 && retornoPendiente == 1)
    	  {
    		  retorno = cantidadPedidosPendientesPorUnaLocalidad(listaCliente, listaLocalidad, TAM_CLIENTE, listaPedido, TAM_PEDIDO);
    		  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  }

    	  else
          {
    		 mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		 mensajeEstado(retornoPendiente, "Hay pedidos pendientes. \n", "Error, un proceso salio mal. \n", "No hay pedidos pendientes. \n");
    	  }
    	  break;

    	  case 10:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoProcesado = verificarPedidoExistenciaProcesado(listaPedido, TAM_PEDIDO);
    	  if(retornoCliente == 1 && retornoProcesado == 1)
    	  {
    		  retorno = sacarPromedioDePP(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    		  mensajeEstado(retorno, "Promedio con exito. \n", "Error, un proceso salio mal. \n", "Promedio sin exito. \n");
          }

    	  else
          {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		  mensajeEstado(retornoProcesado, "Hay pedidos procesados. \n", "Error, un proceso salio mal. \n", "No hay pedidos procesados. \n");
    	  }
    	  break;

    	  case 11:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoPendiente = verificarPedidoExistenciaPendiente(listaPedido, TAM_PEDIDO);
    	  if(retornoCliente == 1 && retornoPendiente == 1)
    	  {
    		  retorno = pedidosPendiente(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO);
    		  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		  mensajeEstado(retornoPendiente, "Hay pedidos pendientes. \n", "Error, un proceso salio mal. \n", "No hay pedidos pendientes. \n");
    	  }
    	  break;

    	  case 12:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoProcesado = verificarPedidoExistenciaProcesado(listaPedido, TAM_PEDIDO);
    	  if(retornoCliente == 1 && retornoProcesado == 1)
          {
    		  retorno = pedidosCompletados(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO);
    		  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  }

    	  else
    	  {
    		   mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		   mensajeEstado(retornoProcesado, "Hay pedidos procesados. \n", "Error, un proceso salio mal. \n", "No hay pedidos procesados. \n");
    	  }
    	  break;

    	  case 13:
    	  retornoCliente = verificarClienteExistencia(listaCliente, TAM_CLIENTE);
    	  retornoProcesado = verificarPedidoExistenciaProcesado(listaPedido, TAM_PEDIDO);
    	  retornoPendiente = verificarPedidoExistenciaPendiente(listaPedido, TAM_PEDIDO);
    	  if((retornoCliente == 1 && retornoProcesado == 1) || (retornoPendiente == 1 && retornoCliente == 1))
    	  {
    		  retorno = pedidosTotales(listaCliente, TAM_CLIENTE, listaPedido, TAM_PEDIDO);
    		  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  }

    	  else
    	  {
    		  mensajeEstado(retornoCliente, "Hay clientes. \n", "Error, un proceso salio mal. \n", "No hay clientes. \n");
    		  mensajeEstado(retornoPendiente, "Hay pedidos pendientes. \n", "Error, un proceso salio mal. \n", "No hay pedidos pendientes. \n");
    		  mensajeEstado(retornoProcesado, "Hay pedidos procesados. \n", "Error, un proceso salio mal. \n", "No hay pedidos procesados. \n");
    	  }
    	  break;

    	  case 14:
          retorno = 1;
    	  mensajeEstado(retorno, "Gracias por usar mi programa. \n", "Error, un proceso salio mal. \n", "Opcion no valida. \n");
    	  break;

    	  default:
    	  retorno = -1;
    	  mensajeEstado(retorno, "Exito. \n", "Error, un proceso salio mal. \n", "Opcion no valida. \n");
    	  break;

    	}

    } while (opcion != 14);

	return 0;
}
