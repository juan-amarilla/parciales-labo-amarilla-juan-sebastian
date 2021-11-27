//amarilla juan sebastian 1C

#ifndef PEDIDO_H_
#define PEDIDO_H_
#define VACIO 0
#define PENDIENTE 2
#define COMPLETADO 3
#define TAM_CARACTER 51
#define TAM_PEDIDO 1000
#include "OtrasFunciones.h"
#include "IngresarDatos.h"

typedef struct
{
	int id;
	int idCliente;
	int contadorPendiente;
	int contadorProcesado;
	float kilo;
	float HDPE;
	float LDPE;
	float PP;
	int isEmpty;

}ePedido;

/// @fn int inicializarPedidos(ePedido[], int)
/// @brief su funcion es inicializar en VACIO los pedidos y en 0 sus contadores
///
/// @param ePedido listaCliente[]
/// @param int tam
/// @return retorna 1 si salio bien o -1 si salio mal
int inicializarPedidos(ePedido listaPedido[], int tam);

/// @fn int verificarPedidoExistenciaPendiente(ePedido[], int)
/// @brief su funcion es verificar si hay un pedido pendiente
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @return retorna -1 si no encontro nada o 1 si encontro algo
int verificarPedidoExistenciaPendiente(ePedido listaPedido[], int tam);

/// @fn int verificarPedidoExistenciaProcesado(ePedido[], int)
/// @brief su funcion es verificar si hay un pedido procesado
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @return retorna -1 si no encontro nada o 1 si encontro algo
int verificarPedidoExistenciaProcesado(ePedido listaPedido[], int tam);

/// @fn int verificarIdPedido(ePedido[], int, int)
/// @brief su funcion es verificar si la id de pedido esta en pendiente y existe
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @param int id
/// @return retorna la posicion si salio bien o -1 si salio mal
int verificarIdPedido(ePedido listaPedido[], int tam, int id);

/// @fn int procesarResiduos(ePedido[], int)
/// @brief su funcion es procesar los residuos
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no logro nada
int procesarResiduos(ePedido listaPedido[], int tam);

/// @fn int lograrProcesoDeResiduos(ePedido[], int)
/// @brief su funcion es lograr el procesar los residuos de forma correcta
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no logro nada
int lograrProcesoDeResiduos(ePedido listaPedido[], int tam);

/// @fn void imprimirMenuIdPedidoEstructura(listaPedido[], int)
/// @brief su funcion es mostrar un menu id de pedido
///
/// @param ePedido listaPedido[]
/// @param int tam
void imprimirMenuIdPedidoEstructura(ePedido listaPedido[], int tam);

#endif /* PEDIDO_H_ */
