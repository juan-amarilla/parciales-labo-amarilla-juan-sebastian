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
	char cuit[TAM_CARACTER];
	char direccion[TAM_CARACTER];

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
/// @brief su funcion es inicializar los arrays en 0
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
/// @brief su funcion es lograr un pedido pendiente
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param int id
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no logro nada
int lograrPedido(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int id);

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

/// @fn int mostrarClientes(eCliente[], eLocalidad[], int, ePedido[], int)
/// @brief su funcion es listar todos los clientes ingresados
///
/// @param eCliente listaCliente[]
/// @param eLocalidad listaLocalidad[]
/// @param int tam
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no logro nada
int mostrarClientes(eCliente listaCliente[], eLocalidad listaLocalidad[], int tam , ePedido listaPedido[], int tamPedi);

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

/// @fn void mostrarPedidoProcesado(ePedido, eAuxiliar)
/// @brief su funcion es mostrar un pedido procesado
///
/// @param ePedido unPedido
/// @param eAuxiliar unAuxiliar
void mostrarPedidoProcesado(ePedido unPedido, eAuxiliar unAuxiliar);

/// @fn int cantidadPedidosPendientesPorUnaLocalidad(eCliente[], eLocalidad[], int, ePedido[], int)
/// @brief su funcion es ver cuantos pedidos pendientes en total hay en una localidad
///
/// @param eCliente listaCliente[]
/// @param eLocalidad listaLocalidad[]
/// @param int tam
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si esta mal
int cantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[] ,eLocalidad listaLocalidad[], int tam, ePedido listaPedido[], int tamPedi);

/// @fn int lograrCantidadPedidosPendientesPorUnaLocalidad(eCliente[], eLocalidad[], int, ePedido[], int)
/// @brief su funcion es lograr el proceso de ver la cantidad de pedidos pendientes de una localidad
///
/// @param eCliente listaCliente[]
/// @param eLocalidad listaLocalidad[]
/// @param int tam
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si esta mal
int lograrCantidadPedidosPendientesPorUnaLocalidad(eCliente listaCliente[] ,eLocalidad listaLocalidad[], int tam, ePedido listaPedido[], int tamPedi);

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
int ContarAcumularDePP(ePedido listaPedido[], int tamPedi, eCliente listaCliente[], int tamClien, int contador, float* acumulador);

/// @fn int acumularPP(ePedido[], int, float*)
/// @brief su funcion es acumular los PP
///
/// @param ePedido listaPedido[]
/// @param int tam
/// @param float* acumulador
void acumularPP(ePedido listaPedido[], int tam, float* acumulador);

/// @fn int pedidosPendiente(eCliente[], int, ePedido[], int)
/// @brief su funcion es listar los clientes con la maxima cantidad de pedidos pendientes
///
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int pedidosPendiente(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi);

/// @fn int pedidosCompletados(eCliente[], int, ePedido[], int)
/// @brief su funcion es listar los clientes con la maxima cantidad de pedidos procesados
///
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int pedidosCompletados(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi);

/// @fn int pedidosTotales(eCliente[], int, ePedido[], int)
/// @brief su funcion es listar los clientes con la maxima cantidad de pedidos
///
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @return retorna 1 si salio bien, 0 si algo paso en el proceso o -1 si no se logro nada
int pedidosTotales(eCliente listaCliente[], int tamClien, ePedido listaPedido[], int tamPedi);

/// @fn int hallarPedidos(ePedido[], int, eCliente, int)
/// @brief su funcion es contar los pedidos pendientes y procesados
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente
/// @param int contador
/// @return retorna la suma entre las cantidades de pedidos pendientes y procesados
int hallarPedidos(ePedido listaPedido[], int tamPedi, eCliente listaCliente, int contador);

/// @fn int hallarPedidosDeEstado(ePedido[], int, eCliente, int, int)
/// @brief su funcion es contar los pedidos pendientes o procesados
///
/// @param ePedido listaPedido[]
/// @param int tamPedi
/// @param eCliente listaCliente
/// @param int contador
/// @param int estadoActual
/// @return retorna la cantidad de pedidos pendientes o procesados
int hallarPedidosDeEstado(ePedido listaPedido[], int tamPedi, eCliente listaCliente, int contador, int estadoActual);

/// @fn int hallarMaximoDeCliente(eCliente[], int, eAuxiliar[], int)
/// @brief su funcion es hallar el maximo de pedidos
///
/// @param eCliente listaCliente[]
/// @param int tamClien
/// @param eAuxiliar auxiliar[]
/// @param int maximo
/// @return retorna el maximo
int hallarMaximoDeCliente(eCliente listaCliente[], int tamClien, eAuxiliar auxiliar[], int maximo);

/// @fn void mostrarMayor(eCliente[], int, eAuxiliar[], int)
/// @brief su funcion es listar los clientes que tienen la maxima cantidad de pedidos
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @param eAuxiliar auxiliar[]
/// @param int maximo
void mostrarMayor(eCliente listaCliente[], int tam, eAuxiliar auxiliar[], int maximo);

#endif /* NEXO_H_ */
