/*
	9. Tomar el archivo de texto (.txt) creado en el problema 7, y con la función
	fgetc() leer todo su contenido.

	fgetc(puntero_archivo);
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c;
	char direccion[] = "archivo.txt";
	
	FILE *fd = fopen(direccion,"rt"); //rt = read text -- leer texto
	
	if(fd == NULL)
	{
		printf("Error al tratar de leer el archivo");
		return 1;
	}
	
	while((c = fgetc(fd)) != EOF)
	{
		if(c == '\n')
			puts("");
		else
			putchar(c);
	}
	
	fclose(fd);	
	return 0;
}