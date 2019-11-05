/*
	5. Hacer un programa que pida por pantalla una temperatura en grados Celsius, 
	muestre un menú para convertirlos a Fahrenheit o Kelvin y muestre el equivalente por 
	pantalla, utilizar funciones. 

	Celsius a Fahrenheit:
		F = (9*C)/5 + 32;
		
	Celsius a Kelvin:
		K = C + 273.15
*/
#include<stdio.h>

int main()
{
	float fahrenheit(float);
	float kelvin(float);
	float C=0;
	int opc;
	
	do{
		printf("\nDigite los grados Celsius: ");
		scanf("%f",&C);
	
		puts("1. Transformar a Grados Fahrenheit");
		puts("2. Transformar a Grados Kelvin");
		puts("3. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);
	
		switch(opc)
		{
			case 1: 
				printf("\nEl equivalente en Fahrenheit es: %.2f\n",fahrenheit(C));
			break;

			case 2: 
				printf("\nEl equivalente en Kelvin es: %.2f\n",kelvin(C));
			break;
		}
		
		fflush(stdin);
		getchar();
	}while(opc != 3);

	return 0; 
}

float fahrenheit(float C)
{
	float F = ((9 * C)/5) + 32;
	return F;
}

float kelvin(float C)
{
	float K = C + 273.15;
	return K;	
}