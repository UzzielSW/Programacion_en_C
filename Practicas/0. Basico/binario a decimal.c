/*
	elabore un programa que cargue en un vector 5 digitos binarios y realice la conversion a numero decimal.
	el programa debe poseer el titulo, la opcion para introducir los digitos binarios y hacer el calculo
	y la opcion para terminar.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int opc,i, vector[5], decimal=0;
	do{
		system("cls");
		puts(" 1.introducir digitos binarios");
		puts(" 2.realizar conversion [ Binario --> Decimal ]");
		puts(" 3.salir");
		printf("\n opcion: "); scanf("%d",&opc);

		switch(opc)
		{
			case 1: 
				printf("\n ingrese los digitos binarios: ");
				for(i=4; i >= 0; i--)
					scanf("%d",&vector[i]);
			break; 
			
			case 2:	
				for(i=4; i >= 0; i--)
					if(vector[i] == 1)
						decimal += (vector[i] * pow(2, i));
					
				printf("\n El decimal es: %d", decimal);
				decimal=0;
			break;
		}
		getchar();
	} while (opc != 3);
return 0;
}