/*
14. Hacer un array de 10 numeros desordenados, luego ordenarlos con
el ordenamiento por seleccion, posteriormente pedir un dato a buscar 
y utilizar la busqueda binaria para determinar si existe o no.
*/
#include<stdio.h>

int main()
{
	int arr[10] = {2, 5, 4, 6, 1, 8, 9, 10, 7, 3};
	int i,j, min, temp;
	int dato, inf, sup, mitad;
	char band = 'F';
	
	for(i=0; i < 10; i++)
	{
		min = i;
		for(j = (i+1); j <= 10; j++)
			if(arr[j] < arr[min])
				min = j;

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	
	for(i=0; i < 10; i++) printf("%d ",arr[i]);
	
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
		puts("El dato no existe");
		
	else if(band == 'V')
		printf("El dato existe, en la pos: %d",mitad);
	
	getchar();
	return 0;
}