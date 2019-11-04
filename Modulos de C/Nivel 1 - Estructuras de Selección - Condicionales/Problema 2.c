//	2. Comprobar si un numero digitado por el usuario es positivo o negativo
#include<stdio.h>

int main()
{
	int numero;
	
	printf("Digite un numero: "); scanf("%d",&numero);
	
	printf("\n el numero es %s", (numero > 0)? "positivo" : "negativo");
	
	return 0;
}