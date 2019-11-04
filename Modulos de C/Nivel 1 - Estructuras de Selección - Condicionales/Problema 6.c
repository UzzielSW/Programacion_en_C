/*
	6. Ingrese un número y calcule e imprima su raíz cuadrada. Si el numero es negativo imprima el número y un mensaje que diga “tiene raíz imaginaria” 
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int numero;
	float raiz_cuadrada;
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
	
	if(numero > 0)
		printf("\nSu raiz cuadrada es: %f", sqrt(numero,0.5));
	else
		printf("\nEl numero tiene raiz imaginaria");
	
	return 0;
}