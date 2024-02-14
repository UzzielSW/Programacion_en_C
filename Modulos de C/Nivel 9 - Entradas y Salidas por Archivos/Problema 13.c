/*
	13. Crear un archivo de texto (.txt), donde guardar los email de amigos.

	fprintf(puntero,informacion);
	fwrite(dato a guardar, size, longitud, puntero);
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char nombre[20];
	char apellidos[20];
	char email[30];
}DatosPersona;

int main()
{
	DatosPersona datos;
	char direccion[] = "emails.txt";
	char rpt;

	FILE *fd = fopen(direccion,"wt");
	
	if(fd == NULL)
	{
		puts("Error al tratar de crear el archivo");
		return 1;
	}
	
	puts("\t.:EMAIL DE AMIGOS:."); 
	fprintf(fd,"\t.:EMAIL DE AMIGOS:.");
	
	do{
		fflush(stdin);	
		printf("\nNombre: "); gets(datos.nombre);
		printf("Apellidos: "); gets(datos.apellidos);
		printf("Email: "); gets(datos.email);
	
		fprintf(fd,"\n\nNombre: "); 
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);

		fprintf(fd,"\nApellidos: ");
		fwrite(datos.apellidos, 1, strlen(datos.apellidos), fd);

		fprintf(fd,"\nEmail: ");
		fwrite(datos.email, 1, strlen(datos.email), fd);

		printf("Desea guardar mas datos(s) (s/n): ");
		scanf("%c",&rpt);
	}while(rpt == 's');
	
	fclose(fd);	
	return 0;
}