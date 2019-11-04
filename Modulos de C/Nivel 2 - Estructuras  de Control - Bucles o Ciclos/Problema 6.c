//6. Sumar pares desde n hasta m (Propuesto)
#include<stdio.h>

int main()
{
	int n,m,suma=0;
	
	printf("Digite el comienzo n: ");scanf("%d",&n);
	printf("Digite el termino m: ");scanf("%d",&m);
	
	while(++n <= m)
		if((n % 2) == 0)	
			suma += n;					
	
	printf("\n La suma de pares es: %d",suma);
	return 0;
}