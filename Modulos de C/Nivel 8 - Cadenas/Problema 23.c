/*
	23. Utilizar la funcion atof() para pasar una cadena (por ejemplo: "123.45"), a 
	numero flotante.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *cad = "123.45";
	float valor;
	
	valor = atof(cad);
	
	printf("Numero flotante: %.2f",valor);
	
	return 0;
}