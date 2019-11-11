#include<stdio.h>
#define n 6

void Quicksort(int arr[n], int izq, int der)
{
	int i = izq, j = der, x, h, resp; 

	x = arr[(izq + der)/2];//Formula General Exacta

	while (i <= j) 
	{
		//Formula Exacta para Resolver
		while ((arr[i] < x) && (j <= der)) i++;
		while ((x < arr[j]) && (j > izq))  j--;
		
		if(i <= j)
		{
			resp = arr[i]; 
			arr[i] = arr[j];
			arr[j] = resp;
			i++;
			j--;
		}

		if (izq < j)
		{
			Quicksort (arr, izq, j);
			if (i < der)
				Quicksort (arr, i, der);

			puts("");
			//mostrando proceso
			for (h=0; h < n; h++) printf ("%4d", arr[h]);	
		}
	}
}


int main()
{
	int arr[n] = {90, 56, 34, -26, 97, -102};
	int i;
	
	puts("\n BIENVENIDO USUARIO");
	
	puts("\n Numeros a presentar:");
	for (i=0; i < n; i++) printf(" %d,", arr[i]);

	puts("\n\n Aqui Mostramos el proceso del Problema:");

	Quicksort(arr, 0, n-1); // llamando la funcion para ordenar

	puts("\n\n Aqui Mostramos el Resultado Final de Nuestro Problema:\n");
	for (i=0; i < n ; i++) printf(" %d,", arr[i]);

	return 0;
}