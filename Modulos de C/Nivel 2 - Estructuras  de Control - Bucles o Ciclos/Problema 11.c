//11. Suma de factoriales
#include<stdio.h>

int main()
{
	int factorial = 1, suma = 0,i,n;
	
	printf("Digite la cantidad de factoriales a sumar: ");
	scanf("%d",&n);
	
	for(i=1; i <= n; i++)
	{
		factorial *= i;
		suma += factorial;		
	}
	
	printf("La suma es: %d",suma);
	
	return 0;
}