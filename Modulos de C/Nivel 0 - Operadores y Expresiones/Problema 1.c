/*
	1. Pedir 2 numeros al usuario y sumarlos, restarlos, multiplicarlos y dividirlos.
*/
#include<stdio.h>

int main()
{
	float n1, n2;
	
	printf("Digite 2 numeros: ");
	scanf("%f %f",&n1, &n2);
	
	printf("\nLa suma es: %.2f",(n1 + n2));
	printf("\nLa resta es: %.2f",(n1 - n2));
	printf("\nEl producto es: %.2f",(n1 * n2));
	
	if (n2 != 0)
		printf("\nLa division es: %.2f",(n1 / n2));
	 
	return 0;
}