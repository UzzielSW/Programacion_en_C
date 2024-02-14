//leer e imprimir en patalla el archivo archivo.dat creado en el problema 1.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *apc = fopen("prueba.dat","r"); 

	if (apc == NULL) puts("\n el archivo no se encontro");
	else
	{
		do
			putchar(c = getc(apc));
		while(c != '\n');
		fclose(apc);
	}

	return 0;
}