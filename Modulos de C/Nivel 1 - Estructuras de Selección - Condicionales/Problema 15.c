/*
	15. Hacer un programa que simule un cajero autometico con un saldo inicial de 1000 Dolares.
*/ 
#include<stdio.h>

int main()
{
	int saldo_inicial = 1000, opcion;
	float saldo, retiro, agregar;
	
	puts("Bienvenido a su cajero Virtual");
	puts("Digite la opcion de su preferencia");
	puts("1. Ingresar dinero en cuenta");
	puts("2. Retirar dinero de la cuenta");
	puts("3. Ver dinero disponible en cuenta");
	puts("4. Salir");
	printf("\nOpcion: ");
	scanf("%d",&opcion);
	
	switch(opcion)
	{
		case 1: 
			printf("\nDigite la cantidad que desea ingresar: ");
			scanf("%f",&agregar);
			saldo = saldo_inicial + agregar;
			printf("El saldo actual es: %.2f",saldo);
		break;

		case 2:
			printf("\nDigite la cantidad que desea retirar: ");
			scanf("%f",&retiro);

			if(retiro > saldo_inicial)
				puts("La cantidad solicitada es mayor al saldo");
			else
			{
				saldo = saldo_inicial - retiro;
				printf("El saldo actual es de: %.2f",saldo);
			}
		break;

		case 3: 
			printf("El dinero disponible en cuenta es: %d",saldo_inicial);
		break;

		case 4: break;
		default: puts("Numero no disponible");		
	}
	
	return 0;
}