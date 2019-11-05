//1. Determinar si un numero es par o no.
#include<stdio.h>

int main()
{
	void comprobar(int n);
	int numero, x;
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
	
	comprobar(numero);

	return 0;
}

void comprobar(int n)
{
	printf("\n El numero es %s",((n % 2) == 0)? "par" : "impar");
}