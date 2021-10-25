/*
============================================================================
amarilla juan sebastian 1C

Una empresa de recolecci�n y reciclado de pl�sticos
requiere un sistema que les permita administrar sus clientes
y pedidos de recolecci�n.
El programa contar� con el siguiente men�:

1) Alta de cliente:
Se da de alta un cliente con nombre de la empresa,
cuit direcci�n y localidad.
Se generar� un ID �nico para este cliente que se
imprimir� por pantalla si el alta es correcta.

2) Modificar datos de cliente:
Se ingresa el ID de cliente y
se permitir� cambiar la direcci�n y la localidad.

3) Baja de cliente: Se ingresa el ID del cliente.
Luego se preguntar� si se quiere confirmar la eliminaci�n.

4) Crear pedido de recolecci�n: Se imprimir�n los clientes por
pantalla y se pedir� que se ingrese el ID de un cliente
existente y la cantidad de kilos totales que se recolectar�n
del cliente.
Se generar� un ID para el pedido y
el mismo quedar� en estado �Pendiente�
hasta que se obtengan los residuos del cliente y
se trasladen a la empresa.

5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que
volvieron a la empresa se hayan procesado y separado en los diferentes
tipos de pl�stico que la empresa puede reciclar.
Se imprimir�n los pedidos por pantalla
y se pedir� seleccionar el ID de uno de ellos.
Luego deber�n ingresarse la cantidad de kilos de
pl�stico de cada uno de los 3 tipos que la empresa
puede procesar que se obtuvieron de los kilos totales
que se recolectaron.
Por �ltimo, se marcar� al pedido como �Completado�.

6) Imprimir Clientes:
Se imprimir� una lista de clientes con todos sus
datos junto con la cantidad de �pedidos de recolecci�n�
que posee en estado �Pendiente�.

7) Imprimir Pedidos pendientes: Se imprimir� una lista de
los pedidos que se encuentren en estado �Pendiente�
con la informaci�n: Cuit del cliente,
direcci�n del cliente, cantidad de kilos a recolectar.

8) Imprimir Pedidos procesados: Se imprimir� una lista
de los pedidos que se encuentren en estado �Completado�
con la informaci�n: Cuit del cliente, direcci�n del cliente,
cantidad de kilos reciclados de cada tipo de pl�stico.

9) Ingresar una localidad e indicar la cantidad de pedidos
pendientes para dicha localidad.

10) Cantidad de kilos de polipropileno reciclado promedio por
cliente. (kilos totales / cantidad de clientes)
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "OtrasFunciones.h"
#include "Nexo.h"
#define TAM_CARACTER 51

int main(void)
{
	int opcion;
	int tamArray;
	int retorno;
	char cadenaAuxiliar[TAM_CARACTER];
	eCliente listaCliente[TAM_CLIENTE]; /*= {{1,2,"arg","12-12345678-1","Calle Argento","avellaneda",OCUPADO},
			                                {2,1,"br","12-12345678-2","calle brasil","avellaneda",OCUPADO},
			                                {3,0,"ark","32-12345678-2","calle brasil","avellaneda",OCUPADO}};*/

	ePedido listaPedido[TAM_PEDIDO]; /*= {{1,1,0,0,0,0,VACIO},
			                          {2,1,0,0,0,0,VACIO},
	                                  {3,2,0,0,0,0,VACIO}};*/

	eLocalidad listaLocalidad[TAM_CLIENTE];

	eAuxiliar auxiliar;

    setbuf(stdout, NULL);

    tamArray = sizeof(cadenaAuxiliar);
    auxiliar = inicializarId(auxiliar);

    retorno = inicializarClientes(listaCliente, TAM_CLIENTE);
    mensajeEstado(retorno, "Inicializacion de clientes con exito. \n", "Error, un proceso salio mal. \n", "Inicializacion de clientes sin exito. \n");

    retorno = inicializarPedidos(listaPedido, TAM_PEDIDO);
    mensajeEstado(retorno, "Inicializacion de pedidos con exito. \n\n", "Error, un proceso salio mal. \n\n", "Inicializacion de pedidos sin exito. \n\n");

    do
    {
    	menu();
    	pedirEnteroValidado(cadenaAuxiliar, "Ingrese una opcion: \n\n", &opcion, tamArray);

    	switch(opcion)
    	{

    	  case 1:
    	  auxiliar.idCliente++;
    	  retorno = altaCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_CLIENTE, cadenaAuxiliar, auxiliar.idCliente);
    	  mensajeEstado(retorno, "Alta con exito. \n", "Error, un proceso salio mal. \n", "Alta sin exito. \n");
    	  auxiliar.idCliente = verificarId(retorno, auxiliar.idCliente);
    	  break;

    	  case 2:
    	  retorno = modificarCliente(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_CLIENTE, cadenaAuxiliar);
    	  mensajeEstado(retorno, "Modificacion con exito. \n", "Error, un proceso salio mal. \n", "Modificacion sin exito. \n");
    	  break;

    	  case 3:
    	  retorno = bajaCliente(listaCliente, TAM_CLIENTE, cadenaAuxiliar);
    	  mensajeEstado(retorno, "Baja con exito. \n", "Error, un proceso salio mal. \n", "Baja sin exito. \n");
    	  break;

    	  case 4:
    	  auxiliar.idPedido++;
    	  retorno = crearPedido(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE, auxiliar.idPedido);
    	  mensajeEstado(retorno, "Creacion con exito. \n", "Error, un proceso salio mal. \n", "Creacion sin exito. \n");
    	  auxiliar.idPedido = verificarId(retorno, auxiliar.idPedido);
    	  break;

    	  case 5:
    	  retorno = procesarResiduos(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "Procesamiento con exito. \n", "Error, un proceso salio mal. \n", "Procesamiento sin exito. \n");
    	  break;

    	  case 6:
    	  retorno = mostrarClientes(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_CLIENTE);
    	  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  break;

    	  case 7:
    	  retorno = mostrarPedidos(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  break;

    	  case 8:
    	  retorno = mostrarPedidosProcesados(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "listado con exito. \n", "Error, un proceso salio mal. \n", "listado sin exito. \n");
    	  break;

    	  case 9:
    	  retorno = cantidadPedidosPendientesPorUnaLocalidad(listaCliente, TAM_CLIENTE, listaLocalidad, TAM_CLIENTE);
		  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  break;

    	  case 10:
    	  retorno = sacarPromedioDePP(listaPedido, TAM_PEDIDO, listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "Promedio con exito. \n", "Error, un proceso salio mal. \n", "Promedio sin exito. \n");
    	  break;

    	  case 11:
    	  retorno = pedidosPendiente(listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  break;

    	  case 12:
    	  retorno = pedidosCompletados(listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
    	  break;

    	  case 13:
    	  retorno = pedidos(listaCliente, TAM_CLIENTE);
    	  mensajeEstado(retorno, "Mensaje con exito. \n", "Error, un proceso salio mal. \n", "Mensaje sin exito. \n");
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
