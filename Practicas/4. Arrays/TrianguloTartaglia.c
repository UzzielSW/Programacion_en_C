/*
	Escribir una función que genere el triángulo de Tartaglia y otra que lo escriba.

						1
					1		1
				1 		2 		1
			1 		3 		3 		1
		1 		4 		6 		4 		1

	Análisis:
		En el triángulo de Tartaglia cada número es la suma de los dos números situados encima de él. La función
		TrianguloTartaglia calcula el triángulo de Tartaglia de orden n y lo almacena en un array bidimensional del que se
		supene que previamente se ha declarado la constante N. La función escribeTrianguloTartaglia recibe como parámetro
		el array bidimensional y lo escribe.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

void TrianguloTartaglia(int a[][N], int n);
void escribeTrianguloTartaglia(int a[][N], int n);

int main()
{
	int ar[N][N];
	TrianguloTartaglia(ar, N);
	escribeTrianguloTartaglia(ar, N);

	return 0;
}

void TrianguloTartaglia( int a[][N], int n)
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if(j == 0 || j == i)
				a[i][j] = 1;
			else
				a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
}


void escribeTrianguloTartaglia(int a[][N], int n)
{
	int i,j;
	printf(" Triangulo de Tartaglia de orden %d\n", n);
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j <= i; j++)
			printf("%4d", a[i][j]);
		puts("");
	}
}