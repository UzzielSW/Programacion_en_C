/*
	21. Convertir una cadena (por ejemplo: "1234"), a un numero entero.
	Con la funcion atoi().
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *cad = "1234";
	int valor;
	
	valor = atoi(cad);
	
	printf("Valor numerico: %d",valor);
	
	return 0;
}