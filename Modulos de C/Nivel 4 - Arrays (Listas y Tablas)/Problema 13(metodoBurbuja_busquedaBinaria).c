/*
	13. Hacer un array de 10 numeros desordenados, luego ordenarlos con
	el metodo por insercion, posteriormente pedir un dato a buscar y utilizar la
	busqueda binaria para determinar si existe o no.
*/
#include <stdio.h>

int main()
{
	int arr[10] = {2, 5, 4, 6, 1, 8, 9, 10, 7, 3};
	int i, j, aux, cont = 0;
	int dato, inf, sup, mitad;
	char band = 'F';

	// Metodo por insercion
	for (i = 1; i < 10; i++)
	{
		j = i;
		aux = arr[i];
		while ((j > 0) && (aux < arr[j - 1]))
		{ // ascendentemente (aux < arr[j - 1])
		  // descendentemente (aux > arr[j - 1])
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = aux;
	}

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\nDigite un numero: ");
	scanf("%d", &dato);

	// Busqueda Binaria
	inf = 0;
	sup = 10;

	while (inf <= sup && cont < 10)
	{
		mitad = (inf + sup) / 2;

		if (arr[mitad] == dato)
		{
			band = 'V';
			break;
		}
		else if (arr[mitad] > dato)
		{
			sup = mitad;
			mitad = (inf + sup) / 2;
		}
		else if (arr[mitad] < dato)
		{
			inf = mitad;
			mitad = (inf + sup) / 2;
		}

		cont++;
	}

	if (band == 'F')
		printf("El dato no existe");

	else if (band == 'V')
		printf("El dato existe, en la pos: %d", mitad);

	getchar();
	return 0;
}