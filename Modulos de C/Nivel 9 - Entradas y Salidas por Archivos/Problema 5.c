//5. Abrir 2 archivos de texto (.txt), despues cerrar cada uno de ellos con fclose().
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//OJO! crear primero los archivos
	FILE *fd1 = fopen("archivo1.txt","a+");
	FILE *fd2 = fopen("archivo2.txt","a+");
	
	if(fd1 == NULL || fd2 == NULL)
		puts("Error al tratar de modificar el archivo");
	else
		puts("Se pudo modificar los archivos");
	
	//Cerramos los archivos con la funcion fclose()
	fclose(fd1);
	fclose(fd2);
	
	return 0;
}