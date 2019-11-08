/*
	5. Dado un vector de 10 elementos = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4}, escribir un 
	programa en C  (haciendo uso de puntero) que muestre las direcciones de memoria de 
	cada elemento del vector.
*/
#include<stdio.h>

int main()
{
	int i, arr[] = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4};
	int *p_a;
	
	p_a = arr;
	
	for(i=0; i < 10; i++, p_a++)
	{
		printf("\n\nDato: arr[%d]: %d", i, arr[i]);
		printf("\nPosicion: %X",p_a);
	}
	
	return 0;
}