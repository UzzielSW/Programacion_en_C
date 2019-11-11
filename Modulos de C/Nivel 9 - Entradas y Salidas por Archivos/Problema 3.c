//3. Hacer un programa en C que cree un archivo de texto (.txt).
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char direccion[] = "archivo.txt";
	
	FILE *fd = fopen(direccion,"w"); //w = write -- escribir -- crear
	
	if(fd == NULL)
		printf("No se encontro el lugar para crear el archivo");
	else
		printf("Archivo creado\nUbicacion: %s",direccion);
	
	return 0;
}