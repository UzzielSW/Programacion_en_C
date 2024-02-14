/*
	6. Rellenar un array de 10 numeros, posteriormente utilizando punteros indicar cuales
	son numeros pares y su posicion en memoria.
*/
#include<stdio.h>

int main()
{
	int i, arr[10];
	int *p_a;
	
	for(i=0; i < 10; i++)
	{
		printf("Digite un numero arr[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	p_a = arr; //indicar al puntero que inicie en arr[0]
	
	for(i=0; i < 10; i++, p_a++)
	{ 
		if((*p_a % 2) == 0)//Comprobar numeros pares
		{
			printf("\n\nNumero par: %d",*p_a);
			printf("\nPosicion: %X",p_a);
		}
	}
	
	return 0;
}