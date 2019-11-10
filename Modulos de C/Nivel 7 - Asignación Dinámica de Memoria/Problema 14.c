/*
	Problema 14:
	escriba un programa en C que cuente el numero de veces que aparece un caracter
	en una cadena de N caracteres. Utilice asignacion dinamica de memoria y recuerde
	liberar la memoria.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *cadena;
	char caracter,itera;
	int lon=0, cant=0,i=0;

	printf("\n ingrese la cantidad de caracteres que tendra la cadena: ");
	scanf("%d",&lon);

	cadena = (char *) malloc(lon * sizeof(char));

	printf(" ingrese la cadena: ");
	fflush(stdin);	scanf("%[^\n]",cadena); // !!! OJO no poner &cadena porque da error

	printf(" ingrese el caracter que desea contar: ");
	fflush(stdin);	scanf("%c",&caracter);

	for(i=0; itera = cadena[i]; i++)
		if(itera == caracter) cant++;
	

	printf("\n cantidad de veces que aparece \" %c \" en la cadena: %d",caracter,cant);
	free(cadena);

	return 0;
}