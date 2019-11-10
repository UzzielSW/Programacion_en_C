/*
	Problema 15:
	cree una matriz bidimencional dinamica con N filas y M columnas e ingrese tanto en la diagonal
	principal como en la secundaria "1" y en las demas pociones "0". recuerde que las filas y las
	columnas deben ser iguales, luego, imprima la matriz resultante.

	la impresion debe ser algo asi:
	matriz de 4x4:

		1	0	0	1
		0	1	1	0
		0	1	1	0
		1	0	0	1
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **matriz=NULL;
	int f,c,i;
	int filas, colum;

	printf("\n ingrese el numero de filas seguido por el de columnas: ");
	scanf("%d %d",&filas,&colum);

	if (filas == colum)
	{
		matriz = (int **) calloc(filas, sizeof(int *));

		for ( i = 0; i < filas; ++i)
			matriz[i] = (int *) calloc(colum, sizeof(int));

		for(f=0; f < filas; f++) //diagonal principal
			matriz[f][f] = 1;

		for(f=0, c=(colum-1); f < filas; f++, c--)//diagonal secundaria
			matriz[f][c] = 1;

		puts("\n matriz:\n");
		for(f=0; f < filas; f++)
		{
			for(c=0; c < colum; c++)
				printf("%5d",matriz[f][c]);
			puts("");
		}
		
		for (i = 0; i < filas; ++i)
			free(matriz[i]);
		free(matriz);
		
	}else puts("\n los numeros de filas y columnas deben ser iguales para realizar el proceso.");
	return 0;
}