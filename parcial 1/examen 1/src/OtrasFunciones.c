//amarilla juan sebastian 1C

#include "OtrasFunciones.h"

void mensajeEstado(int estado, char valido[], char errorProceso[], char noValido[])
{
	if(estado == 1)
	{
	  printf("%s", valido);
	}

	else
	{
		if(estado == 0)
		{
			printf("%s", errorProceso);
		}

		else
		{
			printf("%s", noValido);
		}
	}
}

void menu()
{
   printf("1-Alta de cliente.\n");
   printf("2-Modificar datos de cliente.\n");
   printf("3-Baja de cliente.\n");
   printf("4-Crear pedido de recolecci�n. \n");
   printf("5-Procesar residuos.\n");
   printf("6-Imprimir Clientes. \n");
   printf("7-Imprimir Pedidos pendientes. \n");
   printf("8-Imprimir Pedidos procesados. \n");
   printf("9-Cantidad de pedidos pendientes para dicha localidad. \n");
   printf("10-Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes). \n");
   printf("11-Cliente con m�s pedidos pendientes. \n");
   printf("12-Cliente con m�s pedidos completados. \n");
   printf("13-Cliente con m�s pedidos. \n");
   printf("14-Salir. \n");

}

int buscarLibre(int estado)
{
	int retorno;

	retorno = VACIO;

	if(estado == OCUPADO)
	{
		retorno = OCUPADO;
	}

	return retorno;

}

void mayusculasAutomaticos(char cadena[], int tam)
{
     int i;

     strlwr(cadena);

	 for(i=0;i<tam;i++)
	 {

		 if(i == 0 && isalpha(cadena[i]) != 0)
		 {
		         	 cadena[i]= toupper(cadena[i]);
		 }

         if(isspace(cadena[i]) != 0 && isalpha(cadena[i+1]) != 0)
		 {
        	 cadena[i+1]= toupper(cadena[i+1]);

		 }
	 }
}

int comparacionCadena(char cadenaUno[], char cadenaDos[])
{
	int retorno;

	retorno = strcmp(cadenaUno, cadenaDos);

	return retorno;

}
