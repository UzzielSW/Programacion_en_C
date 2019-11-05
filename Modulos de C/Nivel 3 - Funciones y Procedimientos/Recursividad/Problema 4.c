//	4. Invertir un numero entero con Recursividad.
#include<stdio.h>

int main()
{
	int numero;
	void invertir(int n);
	
	do
	{
		printf("Digite un numero: ");
		scanf("%d",&numero);
 	}while(numero < 0);
	
	invertir(numero);

	return 0;
}

void invertir(int n)
{
	printf("%d",(n % 10));
	if(n > 10) invertir(n / 10);
}