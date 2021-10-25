//amarilla juan sebastian 1C

#ifndef NEXOINFORMES_H_
#define NEXOINFORMES_H_

#include "Cliente.h"
#include "Pedido.h"


void mostrarCliente(eCliente unCliente, eLocalidad unaLocalidad);

/// @fn void mostrarPedido(ePedido, eCliente)
/// @brief su funcion es mostrar un pedido pendiente
///
/// @param ePedido unPedido
/// @param eCliente unCliente
void mostrarPedido(ePedido unPedido, eCliente unCliente);

/// @fn void mostrarPedidoProcesado(ePedido, eCliente)
/// @brief su funcion es mostrar un pedido procesado
///
/// @param ePedido unPedido
/// @param eCliente unCliente
void mostrarPedidoProcesado(ePedido unPedido, eCliente unCliente);

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

#endif /* NEXOINFORMES_H_ */