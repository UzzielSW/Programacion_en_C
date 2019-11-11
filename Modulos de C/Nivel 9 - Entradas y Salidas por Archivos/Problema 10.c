//	10. Tomar el archivo de texto creado en el problema 8. y leer todo su contenido.
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c;
	 //OJO poner ruta o solo el nombre del archivo si esta en la misma carpeta q este programa.
	char direccion[] = "Aqui va la direccion de tu archivo";
	
	FILE *fd = fopen(direccion,"rt");
	
	if(fd == NULL)
	{
		puts("Error al tratar de leer el archivo");
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