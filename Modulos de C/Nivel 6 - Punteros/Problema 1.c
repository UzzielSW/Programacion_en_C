/*
	1. Hacer una variable de tipo int, otra de tipo float y por ultimo una de tipo char,
	almacenar datos en cada una de las variables, posteriormente indicar la posicion de 
	memoria donde se encuentran guardados los datos de cada variable. Con punteros.
*/
#include<stdio.h>

int main()
{
	int entero = 10, 
		*p_entero = &entero;
	float flotante = 20.5, 
		*p_flotante = &flotante;
	char caracter = 'a', 
		*p_caracter = &caracter;
	
	printf("Variable Entera:\n");
	printf("Dato: %d",*p_entero);  
	printf("\nPosicion: %X",p_entero); 
	
	printf("\n\nVariable Flotante:\n");
	printf("Dato: %.2f",*p_flotante);
	printf("\nPosicion: %X",p_flotante);
	
	printf("\n\nVariable Caracter:\n");
	printf("Dato: %c",*p_caracter);
	printf("\nPosicion: %X",p_caracter);	
	
	return 0;
}