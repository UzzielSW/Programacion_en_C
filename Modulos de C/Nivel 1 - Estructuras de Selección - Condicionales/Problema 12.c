/*
	12. Seleccionar un tipo de vehiculo e indicar el peaje a pagar segun un valor numerico
		1 - turismo, peaje = $500.
		2 - autobus, peaje = $3000.
		3 - motocicleta, peaje = $300.
	caso contrario - Vehiculo no autorizado.
*/
#include<stdio.h>

int main()
{
	int tipo_vehiculo;
	
	printf("Digite el tipo del vehiculo: "); 
	scanf("%d",&tipo_vehiculo);
	
	switch(tipo_vehiculo)
	{
		case 1: printf("Turismo $%d",500);break;
		case 2: printf("Autobus $%d",3000);break;
		case 3: printf("Motocicleta $%d",300);break;
		default: puts("Vehiculo no autorizado");		
	}	
	
	return 0;
}