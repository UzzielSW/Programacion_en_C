/* 	13. Hacer un programa que imprima la suma de todos los numeros 
	pares que hay desde 1 hasta n, y diga cuantos numeros hay.
*/
#include<stdio.h>

int main()
{
	int cont=0, i, suma=0, n;
	
	printf("Digite la cantidad de elementos: ");
	scanf("%d",&n);
	
	for(i=1; i <= n; i++)
	{
		if((i % 2) == 0)
		{
			suma += i;
			cont++;
		}
	}
	
	printf("\n La suma es: %d",suma);
	printf("\n La cantidad de numeros es: %d",cont);
	
	return 0;
}
