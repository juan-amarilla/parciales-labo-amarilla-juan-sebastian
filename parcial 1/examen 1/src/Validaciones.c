//amarilla juan sebastian 1C

#include "Validaciones.h"

int validarNumeroEntero(int* numeroEntero, char numero[])
{
	int i;
	int validacion;
	int entero;

	i = 0;
	validacion = 1;

	while (numero[i] != '\0')
	{
		if(isdigit(numero[i]) != 1)
		{
			validacion=0;
			break;
		}

		i++;

	}

	if(validacion==1)
	{
		entero=atoi(numero);
		*numeroEntero=entero;

	}


	return validacion;
}

int validarCuit(char cadena[], char cuit[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
		if((i == 2 && cadena[i] == '-') || (i == 11 && cadena[i] == '-'))
	    {
			   	i++;
			   	continue;

	    }

		else
		{
			if((i == 2 && cadena[i] != '-') || (i == 11 && cadena[i] != '-'))
			{
				retorno=0;
				break;

			}

		}

	    if(isdigit(cadena[i]) != 1)
	    {
		     retorno=0;
			 break;
	    }

	    i++;

	}

	if(retorno==1)
	{
	   strcpy(cuit, cadena);

	}

	return retorno;

}

int validarNombre(char cadena[], char nombre[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
	     if(isalpha(cadena[i]) == 0)
	     {
	    	   if(isspace(cadena[i]) != 0)
		       {
	    		   i++;
	    		   continue;

			   }

	    	   retorno=0;
	           break;
	     }

	     i++;
	}

	if(retorno==1)
	{
	   strcpy(nombre, cadena);

	}

	return retorno;
}

int validarDireccion(char cadena[], char direccion[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
	     if(isalpha(cadena[i]) == 0)
	     {
	    	   if(isspace(cadena[i]) != 0)
		       {
	    		   i++;
	    		   continue;

			   }

	    	   if(isdigit(cadena[i]) == 1)
	    	   {
	    		   i++;
	    		   continue;
	    	   }

	    	   retorno=0;
	           break;
	     }

	     i++;
	}

	if(retorno==1)
	{
	   strcpy(direccion, cadena);

	}

	return retorno;
}

int validarLocalidad(char cadena[], char localidad[])
{
	int retorno;
	int i;

	retorno = 1;
	i = 0;

	while(cadena[i]!='\0')
	{
	     if(isalpha(cadena[i]) == 0)
	     {
	    	   if(isspace(cadena[i]) != 0)
		       {
	    		   i++;
	    		   continue;

			   }

	    	   retorno=0;
	           break;
	     }

	     i++;
	}

	if(retorno==1)
	{
	   strcpy(localidad, cadena);

	}

	return retorno;
}

int validarNumeroFlotante(float* numeroFlotante, char numero[])
{
	int retorno;
	int i;
	int flag;
	float flotante;

	retorno = 1;
	i = 0;
	flag = 0;

	while(numero[i] != '\0')
	{
		   if (numero[i] == '.' && flag == 0)
		   {
		    	  flag = 1;
		          i++;
		          continue;

		   }

		   if(isdigit(numero[i]) != 1)
		   {
			      retorno=0;
		          break;
		   }

		   i++;
	}

	if(retorno==1)
	{
			flotante=atof(numero);
			*numeroFlotante=flotante;

	}

	return retorno;

}
