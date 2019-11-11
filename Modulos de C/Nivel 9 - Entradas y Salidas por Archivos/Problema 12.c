/*
	12. Crear un archivo de texto, ponerle el texto que deseas, y luego crear un 
	programa en C para agregarle mas texto al archivo.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c;

	// OJO! si no has creado el archivo en la carpeta actual de este archivo no va a leer nada.
	char direccion[] = "archivo.txt";
	
	FILE *fd = fopen(direccion,"at");
	
	if(fd == NULL)
		puts("Error al tratar de abrir el archivo");
	
	while((c = getchar()) != EOF)
		fputc(c,fd);
	
	return 0;
}