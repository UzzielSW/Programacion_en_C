//2. Convertir Grados Celsius a Grados Fahrenheit (Propuesto)

#include<stdio.h>

int main()
{
	float grados_C, grados_F;
	
	printf("Digite los grados Celsius: ");
	scanf("%f",&grados_C);
	
	grados_F = grados_C * 1.8 + 32;
	
	printf("\nEl equivalente en Grados Fahrenheit es: %f", grados_F);
	
	return 0;
}