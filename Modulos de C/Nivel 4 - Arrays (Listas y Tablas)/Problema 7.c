/*
	7. Hacer una matrices de tipo entera preguntandole al usuario el 
	numero de filas y el numero de columnas, rellenar la matriz y luego mostrarla en pantalla
*/
#include<stdio.h>

int main()
{
	int tabla[50][50], filas, columnas, i,j;
	
	printf("Digite el numero de filas: ");
	scanf("%d",&filas);

	printf("Digite el numero de columnas: ");
	scanf("%d",&columnas);
	
	printf("\n\n");
	
	for(i=0; i < filas; i++)
	{
		for(j=0; j < columnas; j++)
		{
			printf("Digite tabla[%d][%d]: ",i+1,j+1);
			scanf("%d",&tabla[i][j]);
		}
	}
	
	printf("\n\n");
	
	for(i=0;i < filas; i++)
	{
		for(j=0;j < columnas; j++)
			printf("%d ",tabla[i][j]);
		puts("");
	}
	
	getchar();
	return 0;
}