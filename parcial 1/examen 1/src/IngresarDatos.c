//amarilla juan sebastian 1C

#include "IngresarDatos.h"

void pedirEnteroValidado(char cadena[], char mensaje[], int* numero, int tamArray)
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) <= tamArray)
	{
		estado = validarNumeroEntero(numero, cadena);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= tamArray)
		{
			estado = validarNumeroEntero(numero, cadena);
		}
	}
}

void pedirCuitValidado(char cadena[], char mensaje[], char cuit[])
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) == 13)
    {
	   estado = validarCuit(cadena, cuit);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
	    	printf("Error: %s", mensaje);
	    	fflush(stdin);
	    	gets(cadena);

	    	if(strlen(cadena) == 13)
	    	{
	    		estado = validarCuit(cadena, cuit);
	    	}
    }

}

void pedirNombre(char cadena[], char mensaje[], char nombre[], int tamArray)
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) <= tamArray)
	{
		estado = validarNombre(cadena, nombre);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= tamArray)
		{
			estado = validarNombre(cadena, nombre);
		}
	}
}

void pedirDireccion(char cadena[], char mensaje[], char direccion[], int tamArray)
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) <= tamArray)
	{
		estado = validarDireccion(cadena, direccion);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= tamArray)
		{
			estado = validarDireccion(cadena, direccion);
		}
	}
}

void pedirLocalidad(char cadena[], char mensaje[], char localidad[], int tamArray)
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) <= tamArray)
	{
		estado = validarLocalidad(cadena, localidad);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= tamArray)
		{
			estado = validarLocalidad(cadena, localidad);
		}
	}
}

void pedirFlotanteValidado(char cadena[], char mensaje[], float* numero, int tamArray)
{
	int estado;

	estado = 0;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	if(strlen(cadena) <= tamArray)
	{
		estado = validarNumeroFlotante(numero, cadena);
	}

	while(estado == 0 || strlen(cadena) == 0)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);

		if(strlen(cadena) <= tamArray)
		{
			estado = validarNumeroFlotante(numero, cadena);
		}
	}
}
