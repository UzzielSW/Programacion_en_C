/*
	Problema 16:
	hacer un programa que llene una matriz de nxm dinamicamente y almacene en su diagonal
	principal el numero correspondiente a la fila y ademas pida un caracter que rellene el
	resto de la matriz.
	ejemplo:
	caracter de relleno: *
	matriz 3x3

		0	*	*
		*	1	*
		*	*	2
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **matriz = NULL;
	int f,c,i;
	int filas, colum;
	char caracter;

	printf("\n ingrese el numero de filas seguido por el de columnas: ");
	scanf("%d %d",&filas, &colum);

	if (filas == colum)
	{
		printf(" ingrese el caracter para llenar el resto de la matriz: ");
		fflush(stdin); scanf("%c",&caracter);
		
		matriz = (char **) calloc(filas, sizeof(char *));

		for (i = 0; i < filas; ++i)
			matriz[i] = (char *) calloc(colum, sizeof(char));

		for(f=0; f < filas; f++) 
		{
			for(c=0; c < colum; c++)
			{
				if(f == c) matriz[f][c] = f; //diagonal principal
				else matriz[f][c] = caracter;
			}
		}
		
		puts("\n matriz:\n");
		for(f=0; f < filas; f++)
		{
			for(c=0; c < colum; c++)
			{
				if(f == c) printf("  %d",matriz[f][c]);
				else printf("  %c",matriz[f][c]);
			}
			puts("");
		}
		
		for (i = 0; i < filas; ++i)
			free(matriz[i]);
		free(matriz);
		
	}else puts("\n los numeros de filas y columnas deben ser iguales para realizar el proceso.");

	return 0;
}