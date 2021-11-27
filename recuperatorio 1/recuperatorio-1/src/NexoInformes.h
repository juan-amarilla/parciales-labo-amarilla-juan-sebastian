//amarilla juan sebastian 1C

#ifndef NEXOINFORMES_H_
#define NEXOINFORMES_H_

#include "Nexo.h"

/// @fn void mostrarCliente(eCliente, eLocalidad, int)
/// @brief su funcion es listar los clientes con la cantidad de pedidos pendientes
///
/// @param eCliente unCliente
/// @param eLocalidad unaLocalidad
/// @param int cantidadPendiente
void mostrarCliente(eCliente unCliente, eLocalidad unaLocalidad, int cantidadPendiente);

/// @fn void mostrarPedido(ePedido, eCliente)
/// @brief su funcion es mostrar un pedido pendiente
///
/// @param ePedido unPedido
/// @param eCliente unCliente
void mostrarPedido(ePedido unPedido, eCliente unCliente);

/// @fn void mostrarPedidoProcesado(ePedido, char[], char[])
/// @brief su funcion es mostrar un pedido procesado
///
/// @param ePedido unPedido
/// @param char cuit[]
/// @param char direccion[]
void mostrarPedidoProcesado(ePedido unPedido, char cuit[], char direccion[]);

/// @fn void mostrarCantidadPedidosPendientesPorUnaLocalidad(int, char[])
/// @brief su funcion es mostrar los pedidos pendientes por dicha localidad
///
/// @param int cantidad
/// @param char localidad
void mostrarCantidadPedidosPendientesPorUnaLocalidad(int cantidad, char localidad[]);

/// @fn void mostrarPromedioDePP(int)
/// @brief su funcion es mostrar un numero flotante
///
/// @param float total
void mostrarPromedioDePP(float total);

/// @fn void mostrarMayor(eCliente[], int, int[], int)
/// @brief su funcion es listar los clientes que tienen la maxima cantidad de pedidos
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @param int contador
/// @param int maximo
void mostrarMayor(eCliente listaCliente[], int tam, int contador[], int maximo);

#endif /* NEXOINFORMES_H_ */
