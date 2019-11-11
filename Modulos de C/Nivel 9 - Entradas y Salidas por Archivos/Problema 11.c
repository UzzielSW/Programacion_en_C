// 11. Agregar texto a un archivo txt
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c;
	char direccion[] = "archivo.txt";

	// OJO! si no has creado el archivo en la carpeta actual de este archivo no va a leer nada.
	FILE *fd = fopen(direccion,"at"); //at = add texto - agregar texto;
	
	if(fd == NULL)
	{
		puts("Error al tratar de crear el archivo");
		return 1;
	}
	
	while((c = getchar()) != EOF)
		fputc(c,fd);
	
	fclose(fd);
	return 0;
}