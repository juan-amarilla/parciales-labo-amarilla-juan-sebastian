//amarilla juan sebastian 1C

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define VACIO 0
#define OCUPADO 1
#define TAM_CARACTER 51
#define TAM_CLIENTE 100
#include "OtrasFunciones.h"
#include "IngresarDatos.h"
#include "Localidad.h"

typedef struct
{
	int id;
	int idLocalidad;
	int contadorPendiente;
	int contadorProcesado;
    char nombre[TAM_CARACTER];
    char cuit[TAM_CARACTER];
    char direccion[TAM_CARACTER];
	int isEmpty;

}eCliente;

/// @fn void verificarCuit(char[], eCliente[])
/// @brief su funcion es verificar un cuit
///
/// @param char cadena[]
/// @param eCliente listaCliente[]
void verificarCuit(char cadena[], eCliente listaCliente[]);

/// @fn void verificarNombre(char[], eCliente[])
/// @brief su funcion es verificar un nombre
///
/// @param char cadena[]
/// @param eCliente listaCliente[]
void verificarNombre(char cadena[], eCliente listaCliente[]);

/// @fn int inicializarClientes(eCliente[], int)
/// @brief su funcion es inicializar el isEmpty como los contadores
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @return retorna 1 si salio bien o -1 si salio mal
int inicializarClientes(eCliente listaCliente[], int tam);

int altaCliente(eCliente listaCliente[], int tamClien, eLocalidad listaLocalidad[], int tamLocal, char cadena[], int id);

int altaClienteParte2(eCliente listaCliente, eLocalidad listaLocalidad[], int tamLocal, eCliente lista[], char cadena[], int id);

eCliente pedirCliente(eCliente listaCliente, eLocalidad listaLocalidad, char cadena[], int id, eCliente lista[]);

/// @fn void imprimirMenuIdClienteEstructura(eCliente[], int)
/// @brief su funcion es mostrar un menu id de cliente
///
/// @param eCliente listaCliente[]
/// @param int tam
void imprimirMenuIdClienteEstructura(eCliente listaCliente[], int tam);

int modificarCliente(eCliente listaCliente[], int tamClien, eLocalidad listaLocalidad[], int tamLocal, char cadena[]);

int modificarUnDatoDeCliente(eCliente listaCliente[], int tam, eLocalidad listaLocalidad[], int tamLocal, char cadena[]);

int modificarUnDatoDeClienteParte2(eCliente listaCliente, eCliente lista[], eLocalidad listaLocalidad[], int tamLocal, char cadena[], int id);

int opcionDeModificarCliente(int opcion, char cadena[], eCliente listaCliente[], int i, int retorno, eLocalidad listaLocalidad);

/// @fn int bajaCliente(eCliente[], int, char[])
/// @brief su funcion es dar de baja un cliente
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @param char cadena[]
/// @return retorna 1 si salio bien, 0 si no se encontro la id o -1 si la baja no fue exitosa
int bajaCliente(eCliente listaCliente[], int tam, char cadena[]);

/// @fn int darDeBajaCliente(eCliente[], int, char[])
/// @brief su funcion es lograr la baja de un cliente por id
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @param char cadena[]
/// @return retorna 1 si salio bien, 0 si no se encontro la id o -1 si la baja no fue exitosa
int darDeBajaCliente(eCliente listaCliente[], int tam, char cadena[]);

/// @fn int verificarIdCliente(eCliente[], int, int)
/// @brief verifica si esa id existe
///
/// @param eCliente listaCliente[]
/// @param int tam
/// @param int id
/// @return retorna la posicion si esta bien o -1 si no se encontro la id
int verificarIdCliente(eCliente listaCliente[], int tam, int id);

#endif /* CLIENTE_H_ */
