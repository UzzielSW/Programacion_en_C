//9. Determinar si un N�mero es Primo o no.
#include<stdio.h>

int main()
{
	int i, numero,cont=0;
	
	printf("Digite un numero: "); scanf("%i",&numero);
	
	for(i=1; i <= numero; i++)
		if((numero % i) == 0)	
			cont++;
	
	if(cont > 2)	puts(" El numero es compuesto");
	else 		puts(" El numero es primo");

	return 0;
}