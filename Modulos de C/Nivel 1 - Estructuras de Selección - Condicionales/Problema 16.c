/*	16. Hace un menu que considere las siguientes opciones:

	caso 1: Cubo de un numero
	caso 2: Numero par o impar
	case 3: salir 
*/ 
#include<stdio.h>
#include<math.h>

int main()
{
	int numero, n1,n2, opcion, cubo;
	
	puts("\tMENU");
	puts("1. Cubo de un numero");
	puts("2. Numero par o impar");
	puts("3. Salir");
	printf("\nOpcion: ");
	scanf("%d",&opcion);
	
	switch(opcion)
	{
		case 1: 
			printf("\nDigite un numero: ");
			scanf("%d",&numero);
			cubo = pow(numero,3);
			printf("El cubo del numero es: %d",cubo);
		break;

		case 2: 
			printf("\nDigite un numero: ");
			scanf("%d",&numero);

			printf("\n El numero es %s", ((numero % 2) == 0)? "par": "impar");
		break;

		default: puts("Opcion no valida");	
	}
	
	return 0;
}