#include <stdio.h>
#include <stdlib.h>
#define filas 4
#define colum 4

int main()
{
	int **matriz;
	int i,k;

	matriz = (int **) malloc(filas * sizeof(int *)); 
	puts("\n se a reservado memoria para filas");
	
	for(i=0; i < filas; i++)	
		matriz[i] = (int *) malloc(colum * sizeof(int)); 
	
	puts("\n se a reservado memoria para columnas");
	for(i=0; i < filas; i++)
		for(k=0; k < colum; k++)
			matriz[i][k] = 0;
	
	puts("\n matriz:");
	for (i = 0; i < filas; ++i)
	{
		for (k = 0; k < colum; ++k)
			printf("%5d ",*(*(matriz + i) + k));
		puts("");
	}

	for (i = 0; i < filas; i++)
		free(*(matriz + i));
	
	free(matriz);
	puts("\n se ha liberado memoria de la matriz");
	
	return 0;
}