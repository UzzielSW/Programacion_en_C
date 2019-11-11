/*
	4. Hacer un programa en C que cree un archivo de texto (.txt) llamado "hola mundo",
	crear el archivo en la carpeta que elija.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char direccion[] = "Aqui pones la direccion";
	
	FILE *fd = fopen(direccion,"w");
	
	if(fd == NULL)
		puts("No se encontro la Ubicacion para crear el archivo");
	else
		printf("Archivo creado\nUbicacion: %s",direccion);
	
	return 0;
}