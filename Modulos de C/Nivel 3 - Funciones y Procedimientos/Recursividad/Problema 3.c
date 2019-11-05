// 3. Pasar de numero entero a numero binario con Recursividad
#include<stdio.h>

int main()
{
	int numero;
	void binario(int n);
		
	do
	{
		printf("Digite un numero: ");
		scanf("%d",&numero);
	}while(numero < 0);
	
	binario(numero);
		
	return 0;
}

void binario(int n)
{
	if(n > 1) binario(n / 2);
	
	printf("%d",(n % 2));
}