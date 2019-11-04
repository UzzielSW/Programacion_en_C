/*
	5. Sumar 1-2+3-4...

impares (+)
pares (-)

suma_pares = -2 -4 -6 ...
suma_impares = 1 + 3 + 5...

suma = suma_pares + suma_impares

1-2+3-4+5-6
-1+3-4+5-6
2-4+5-6
-2+5-6
3-6
-3
4 - 7
-4 - 8
5 - 9
-5 - 10
*/

#include<stdio.h>

int main()
{
	int i, suma_pares = 0, suma_impares = 0, n,ne;
	
	printf("Digite el total de elementos de la serie: ");
	scanf("%d",&n);
	
	i = 0;
	while(++i <= n)
	{
		if((i % 2) == 0) suma_pares += (i * -1);
		else suma_impares += i;
	}
	
	printf("\n La suma total es: %d",(suma_pares + suma_impares));	
	
	return 0;
}