/*
	14. Mostrar los meses del año, pidiendole al usuario un numero entre (1-12) y mostrar el mes al que corresponde
*/
#include<stdio.h>

int main()
{
	int mes;
	
	printf("Digite un numero entre (1-12): ");
	scanf("%d",&mes);
	
	switch(mes)
	{
		case 1: puts("Enero");break;
		case 2: puts("Febrero");break;
		case 3: puts("Marzo");break;
		case 4: puts("Abril");break;
		case 5: puts("Mayo");break;
		case 6: puts("Junio");break;
		case 7: puts("Julio");break;
		case 8: puts("Agosto");break;
		case 9: puts("Septiembre");break;
		case 10: puts("Octubre");break;
		case 11: puts("Noviembre");break;
		case 12: puts("Diciembre");break;	
		default: puts("Numero no valido para mes");	
	}

	return 0;
}