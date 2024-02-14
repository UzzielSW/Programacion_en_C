/*
	6. Hacer un programa en C, que cree 2 archivos de texto (.txt), y luego utilizar
	la funcion fclose() para cerrarlos.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fd1 = fopen("archivo1.txt","wt");
	FILE *fd2 = fopen("archivo2.txt","wt");
	
	if(fd1 == NULL || fd2 == NULL)
		puts("No se pudo crear los archivos");
	else
		puts("Exito al crear los archivos");
	
	//utilizamos la funcion fclose() para cerrar los archivos
	fclose(fd1);
	fclose(fd2);
	
	return 0;
}