/*
	10. Sumar 2 matrices, pidiendo al usuario el numero de filas y
	columnas y ademas los elementos de cada matriz, luego mostrar el resultado.
*/
#include<stdio.h>
#define N 10

int main()
{
	void sumar(int a[N][N], int b[N][N], int filas, int columnas);

	int matriz1[N][N], matriz2[N][N];
	int filas,columnas, i,j;
	
	printf("Digite el numero de filas de la matriz: ");
	scanf("%d",&filas);

	printf("Digite el numero de columnas de la matriz: ");
	scanf("%d",&columnas);
	
	if (filas > N || columnas > N) exit(1);//validando con el max

	puts("");
	for(i=0; i < filas; i++)
	{
		for(j=0; j < columnas; j++)
		{
			printf("Digite el numero matriz1[%d][%d]: ",i+1,j+1);
			scanf("%d",&matriz1[i][j]);
		}
	}

	puts("\n");
	for(i=0; i < filas; i++){
		for(j=0; j < columnas; j++)
		{
			printf("Digite el numero matriz2[%d][%d]: ",i+1,j+1);
			scanf("%d",&matriz2[i][j]);
		}
	}
	
	puts("\nSuma:");
	sumar(matriz1, matriz2, filas, columnas);
	
	getchar();
	return 0;
}

void sumar(int a[N][N], int b[N][N], int filas, int columnas)
{
	int suma[filas][columnas], i,j;
	
	for(i=0; i < filas; i++)
		for(j=0; j < columnas; j++)
			suma[i][j] = a[i][j] + b[i][j]; 
	
	for(i=0; i < filas; i++)
	{
		for(j=0; j < columnas; j++) printf("%d ",suma[i][j]);

		puts("");
	}	
}