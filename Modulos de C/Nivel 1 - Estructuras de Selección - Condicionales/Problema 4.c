// 4. Determinar si un numero es par, impar 
#include<stdio.h>

int main()
{
	int numero;
	
	printf("Escriba un numero: ");
	scanf("%d",&numero);

	printf("\n el numero es %s", ((numero%2) == 0)? "par" : "impar");

	return 0;
}