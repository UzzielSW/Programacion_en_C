// Problema 13: matriz dinamica de cadena de caracteres
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leerCadenas(char **, int);
void visualizarCadenas(char **, int);

int main()
{
	char **nombre;
	int filas=0;
	int f=0;

	printf("\n digite en numero de filas de la matriz: ");
	scanf("%d",&filas);

	nombre = (char **) malloc(filas * sizeof(char *));

	filas = leerCadenas(nombre, filas);

	if(filas != 0) visualizarCadenas(nombre, filas);
	else exit(0);

	//liberando memoria
	for(f=0; f < filas; f++)
		free(nombre[f]);
	free(nombre);

	return 0;
}


int leerCadenas(char **nombre, int filas)
{
	int f=0, lon=0;
	char cadena[30];
	puts("\n introducir cadenas de caracteres");
	puts(" pulse Enter para terminal");
	fflush(stdin);

	while((f < filas) && (lon = strlen(gets(cadena))) > 0) //capturando
	{
		nombre[f] = (char *) malloc((lon + 1) * sizeof(char));
		strcpy(nombre[f], cadena);
		f++;
	}

	return f;
}

void visualizarCadenas(char **nombre, int filas)
{
	int f=0;
	puts("\n\tvisualizando datos:");
	for(f=0; f < filas; f++)
		printf(" %s\n",nombre[f]);
}