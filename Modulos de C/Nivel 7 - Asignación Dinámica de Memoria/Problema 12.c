/*
	Problema 12:
	se trata de realizar un programa que lea una frase y conservando el orden de las palabras 
	que ha leido, escriba cada una de estas palabras al reves.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

void libro(); // forma en como la hacen en el libro
void miform(); //la que hice usando la funcion strlok

int main()
{
//	libro();
//	miform();
	return 0;
}

// forma extraida de libro de programacion en C
void libro()
{
	char c, temp[20];
	char **frase;
	int i,j=0, npal=0,n;
	
	frase = malloc(max * sizeof(char *)); //la frase tiene un max de 10 palabras

	puts("\n ingrese la frase:");
	do
	{
		c = getchar();
		//leer letra por letra mientras diferente de espacio o salto de linea
		if(c != ' ' && c != '\n')
			temp[j++] = c;
		else
		{
			temp[j++] = '\0';//agregando el final de cada arreglo
			frase[npal] = malloc(j * sizeof(char)); //reservando espacio para la nueva palabra leida en temp
			strcpy(frase[npal++], temp);// agregando palabra a la matriz
			j = 0;
		}
	} while (c != '\n');

	puts("\n las palabras de la frase son:");
	for (i = 0; i < npal; i++)
		printf(" %s",frase[i]);
	
	puts("\n\n las palabras al reves son:\n");
	for (i = 0; i < npal; i++)
	{
		printf(" ");
		for (j = (strlen(frase[i]) - 1); j >= 0; j--)
			printf("%c",frase[i][j]);
	}	
}


void miform()
{
	char temp[30];
	char *palabra;
	char **frase;
	int f,c, npal=0, lon;

	frase = malloc(max * sizeof(char *));

	printf("\n ingrese una frase: ");
	scanf("%[^\n]",&temp);

	palabra = strtok(temp," ");//extrayendo palabra primera palabra
	lon = strlen(palabra);
	frase[npal] = malloc(lon * sizeof(char)); //reservando memoria de logitud de la palabra
	strcpy(frase[npal], palabra);//agregando palabra a la matriz

	while(palabra != NULL)
	{
		++npal;
		palabra = strtok(NULL," ");
		if(palabra != NULL)
		{
			lon = strlen(palabra);
			frase[npal] = malloc(lon * sizeof(char));
			strcpy(frase[npal],palabra);
		}
	}

	puts("\n las palabras de la frase son:");
	for(f=0; f < npal; f++)
		printf(" %s",frase[f]);
	
	puts("\n\n las palabras al reves son:");
	for(f=0; f < npal; f++)
	{
		printf(" ");
		for(c = (strlen(frase[f]) - 1); c >= 0; c--)
			printf("%c",frase[f][c]);
	}	

	// se puede hacer usando for y imrpimiendo letra por letra la palabra alrrever o usar metodo para invertir las palabras...	
}