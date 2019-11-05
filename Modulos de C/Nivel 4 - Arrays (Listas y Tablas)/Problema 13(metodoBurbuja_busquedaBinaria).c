/*
	13. Hacer un array de 10 numeros desordenados, luego ordenarlos con
	el metodo burbuja, posteriormente pedir un dato a buscar y utilizar la
	busqueda binaria para determinar si existe o no.
*/
#include<stdio.h>

int main()
{
	int arr[10] = {2, 5, 4, 6, 1, 8, 9, 10, 7, 3};
	int i, j, aux;
	int dato, inf, sup, mitad;
	char band = 'F';
	
	//Metodo Burbuja
	for(i=0; i < 10; i++)
	{
		for(j=0; j < (10-1); j++)
		{
			if(arr[j] > arr[j+1])
			{
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}
	
	for(i=0; i < 10; i++)
		printf("%d ",arr[i]);
	
	printf("\nDigite un numero: ");
	scanf("%d",&dato);

	//Busqueda Binaria
	inf = 0;
	sup = 10;
	
	while(inf <= sup)
	{
		mitad = (inf + sup)/2;

		if(arr[mitad] == dato)
		{
			band = 'V';
			break;
		}

		else if(arr[mitad] > dato)
		{
			sup = mitad;
			mitad = (inf + sup)/2;
		}

		else if(arr[mitad] < dato)
		{
			inf = mitad;
			mitad = (inf + sup)/2;
		}
	}
	
	if(band == 'F')
		printf("El dato no existe");
	
	else if(band == 'V')
		printf("El dato existe, en la pos: %d",mitad);
	
	getchar();
	return 0;
}