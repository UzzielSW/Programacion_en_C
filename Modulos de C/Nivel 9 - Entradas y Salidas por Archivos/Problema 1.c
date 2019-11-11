/*
	1. Utilizar la función fopen(), para determinar si existe un archivo de texto (.txt) o no.

 	fopen(nombre de archivo , modo);

	nombre de archivo = cadena  ... contiene el identificar externo del archivo
	modo = cadena               ... contiene el modo en que va a ser tratado el archivo

	//todo esta mejor explicado en el archivo "Procesamiento de archivos"
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char direccion[] = "archivo.txt";
	
	// OJO! si no has creado el archivo en la carpeta actual de este archivo no va a leer nada.
	FILE *fd = fopen(direccion,"r"); //read -- leer
	
	if(fd == NULL)
		puts("No se localizo el archivo");
	else
		printf(" Si se localizo el archivo\nUbicacion: %s",direccion);
 	
 	return 0;
}