// crear y añadir texto en un archivo hasta introducir un salto de linea
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *apc = fopen("archivo.dat","w+");
	
	if (apc == NULL) puts("\n el archivo no se creo");
	else
	{
		while(c != '\n')
			putc(c = getchar(), apc);
		
		fclose(apc);
	}

	return 0;
}