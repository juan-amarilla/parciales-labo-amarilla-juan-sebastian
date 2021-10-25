//amarilla juan sebastian 1C

#ifndef NEXO_H_
#define NEXO_H_
#include "Cliente.h"
#include "Pedido.h"
#include "NexoInformes.h"

typedef struct
{
	int contador;
	float acumulador;
	int idCliente;
	int idPedido;

}eAuxiliar;

/// @fn eAuxiliar inicializarId(eAuxiliar)
/// @brief su funcion es inicializar las id en 0
///
/// @param eAuxiliar auxiliar
/// @return retorna las id en 0
eAuxiliar inicializarId(eAuxiliar auxiliar);

/// @fn eAuxiliar inicializarAuxiliar(eAuxiliar)
/// @brief su funcion es inicializar el contador a 0 y acumulador tambien a 0
///
/// @param eAuxiliar auxiliar
/// @return retorna el dato inicializado
eAuxiliar inicializarAuxiliar(eAuxiliar auxiliar);

/// @fn void inicializarAuxiliarArray(eAuxiliar[], int)
/// @brief su funcion es inicializar los arrays
///
/// @param eAuxiliar auxiliar[]
/// @param int tam
void inicializarAuxiliarArray(eAuxiliar auxiliar[], int tam);

/// @fn int verificarId(int, int)
/// @brief su funcion es verificar si la id se ingreso de manera correcta
///
/// @param int estado
/// @param int id
/// @return retorna la id
int verificarId(int estado, int id);

/// @fn int crearPedido(ePedido[], int, eCliente[], int, int)
/// @brief su funcion es crear un pedido
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param int id
/// @return retorna 1 si salio bien, 0 si no encontro distinto a pendiente o -1 si la id no se encontro
int crearPedido(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int id);

/// @fn int lograrPedido(ePedido[], int, eCliente[], int, int)
/// @brief su funcion es lograr el pedido
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param int id
/// @return retorna 1 si salio bien, 0 si no encontro distinto a pendiente o -1 si la id no se encontro
int lograrPedido(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int id);

/// @fn int procesarResiduos(ePedido[], int, eCliente[], int)
/// @brief su funcion es procesar residuos
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si sucedio algo en el proceso o -1 si esta mal
int procesarResiduos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int lograrProcesoDeResiduos(ePedido[], int, eCliente[], int)
/// @brief su funcion es lograr el proceso de residuos
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si sucedio algo en el proceso o -1 si esta mal
int lograrProcesoDeResiduos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);


int mostrarClientes(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal);

int lograrMostrarClientes(eCliente listaCliente, eLocalidad listaLocalidad[], int tamLocal);

/// @fn int mostrarPedidos(ePedido[], int, eCliente[], int)
/// @brief su funcion es mostrar pedidos pendiente
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si no se encontro un pedido o -1 si esta mal
int mostrarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int lograrMostrarPedidos(ePedido[], int, eCliente[], int)
/// @brief su funcion lograr el proceso de mostrar pedidos pendiente
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si no se encontro un pedido o -1 si esta mal
int lograrMostrarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int mostrarPedidosProcesados(ePedido[], int, eCliente[], int)
/// @brief su funcion es mostrar pedidos procesados
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si no se encontro un pedido o -1 si esta mal
int mostrarPedidosProcesados(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int lograrMostrarPedidosProcesados(ePedido[], int, eCliente[], int)
/// @brief su funcion lograr el proceso de mostrar pedidos procesados
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si no se encontro un pedido o -1 si esta mal
int lograrMostrarPedidosProcesados(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

int cantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal);

int lograrCantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente, eLocalidad listaLocalidad[], int tam);

/// @fn int sacarPromedioDePP(ePedido[], int, eCliente[], int)
/// @brief su funcion es sacar el promedio de PP
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int sacarPromedioDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int lograrSacarPromedioDePP(ePedido[], int, eCliente[], int)
/// @brief su funcion es lograr de sacar el promedio de PP
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int lograrSacarPromedioDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien);

/// @fn int ContarAcumularDePP(ePedido[], int, eCliente[], int, int*, float*)
/// @brief su funcion es contar y acumular de PP por cliente
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param int* contador
/// @param float* acumulador
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int ContarAcumularDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int* contador, float* acumulador);

/// @fn void contarDePP(ePedido[], int, int*, int)
/// @brief su funcion es contar por cliente basandose en la id de cliente de pedido
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @param int* contador
/// @param int id
void contarDePP(ePedido listaPedido[], int tam, int* contador, int id);

/// @fn int acumularPP(ePedido[], int, float*)
/// @brief su funcion es acumular los PP
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @param float* acumulador
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int acumularPP(ePedido listaPedido[], int tam, float* acumulador);

int pedidosPendiente(eCliente listaCliente[], int tam);

int pedidosCompletados(eCliente listaCliente[], int tam);

int pedidos(eCliente listaCliente[], int tam);

#endif /* NEXO_H_ */
