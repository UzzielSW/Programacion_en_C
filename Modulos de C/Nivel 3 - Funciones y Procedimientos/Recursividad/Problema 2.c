/*	2. Consideremos una funcion que recibe un numero
	n e imprime los numeros del n al 1. Con recursividad
*/
#include<stdio.h>

int main()
{
	int i, numero;
	int listar(int n);
	
	printf("Digite el numero de terminos: ");
	scanf("%d",&numero);
	
	for(i = numero; i > 0; i--)	printf("%d.\n", listar(i));

	return 0;	
}

int listar(int n)
{
	if((n == 1) || (n == 0))
		return 1;
	else
		return listar(n - 1) + 1;	
}