/*
	problema 1:
	realice el producto de la diagonal principal de una matriz MxM. si el producto de la diagonal
	inferior es mayor que la diagonal superior, ponga en 0 todos los valores de la superior,
	de lo contrario ponga los de la inferior.calcule la suma de las filas y de las columnas 
	y guardelas en dos vectores. imprima la matriz resultante en forma de filas y columnas.
	y los dos vectores.

	forma de ingresar matriz:  
	ejemplo:  9 8 7      calculos:  diag.superior = 9+1+4=14   matriz resultante: 0 8 7
			  3 1 2					diag.inferior = 7+1+7=15                      3 0 2
			  7 3 4                                                               7 3 0
 																
	suma por fila: 15 5 10
	suma por columna: 10 11 9
*/
#include<stdio.h>
#include<conio.h>
#define TAM 15

int main()
{
	int matriz[TAM][TAM], vector_filas[TAM], vector_columnas[TAM]; 
	int diag_superior=0, diag_inferior=0;
	int i,k, cant, a;

	for(i=0; i < TAM; i++) vector_filas[i]=0; //igualando todo el vector a cero para que no guarde basura
	for(i=0; i < TAM; i++) vector_columnas[i]=0; //igualando todo el vector a cero para que no guarde basura
	
	printf("\n ingrese la cantidad de la matriz MXM: ");
	scanf("%d",&cant);

	// cargando la matriz
	puts(" Digite los valores de la matriz:\n");
	for(i=0; i < cant; ++i)
	{
		printf("-> ");
		for(k=0; k < cant; ++k)
			scanf("%d",&matriz[i][k]);
	}
	
	// calculando el producto de la diagonal superior
	for(i=0; k < cant; ++i)
		diag_superior += matriz[i][i];

	// calculando el producto de la diagonal inferior
	for(i=0, k = (cant-1); i < cant; ++i, --k)
		diag_inferior += matriz[i][k];

	// igualando a 0 la diagonal que sea menor
	if (diag_inferior > diag_superior)
		for(i=0; i < cant; ++i)
			matriz[i][i] = 0;
	else
		for(i=0, k = (cant-1); i < cant; ++i, --k)
			matriz[i][k] = 0;

	// calculando suma de las filas
	for(i=0; i < cant; i++)
		for (k=0; k < cant; k++)
			vector_filas[i] += matriz[i][k];

	// calculando suma de las columnas
	for(k=0; k < cant; k++)
		for (i=0; i < cant; i++)
			vector_columnas[k] += matriz[i][k]; 
	

	// imprimiendo matriz resultante y los dos vectores
	puts("\n La matriz resultante:");
	for(i = 0; i < cant; ++i)
	{
		for(k=0; k < cant ; ++k)
			printf(" %d", matriz[i][k]);
		puts("");
	}

	printf("\n suma de las filas: ");
	for (i = 0; i < cant; ++i)
		printf(" %d",vector_filas[i]);

	printf("\n suma de las columnas: ");
	for (i = 0; i < cant; ++i)
		printf(" %d",vector_columnas[i]);
	
	getchar();
	return 0;
}