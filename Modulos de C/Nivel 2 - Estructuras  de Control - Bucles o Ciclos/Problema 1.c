// 1. Suma de los n primeros números
#include<stdio.h>

int main()
{
	int i, suma = 0, n;
	
	printf("Digite la cantidad de numeros a sumar: ");
	scanf("%d",&n);
	
	i = 0; 
	
	while(++i <= n)	suma += i;

	printf("La suma es: %d",suma);

	return 0;
}