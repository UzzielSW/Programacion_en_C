#include <stdio.h> 
#include <stdlib.h>

int main()
{
	//impresion de tipos de datos principales en C
	int num = 1;
	long num2 = 12345;
	double num3 = 123.12345;
	float num4 = 12.12;
	char letter = 'a';
	char *cadena = "texto";

	printf("\n entero: %d",num);
	printf("\n long: %ld",num2); 
	printf("\n double: %.5lf",num3);
	printf("\n float: %.2f",num4);
	printf("\n char: %c",letter);
	printf("\n cadena: %s",cadena);
	// %x puntero
	// %e exponenciales x10^x
	return 0;
}