/*
	14. Crear un programa en C, que pueda seguir agregando contactos de email, hacia el 
	archivo que creamos en el problema 13.
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
	
	FILE *fd = fopen(direccion,"at"); //at = add texto - agregar texto;
	
	if(fd == NULL)
	{
		puts("Error al tratar de localizar el archivo");
		return 1;
	}
	
	puts("\t.:Agregando mas Contacto de Email:.");
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
		
		printf("Desea seguir agregando mas contantos(s) (s/n):  ");
		scanf("%c",&rpt);
	}while(rpt == 's');
	
	fclose(fd);
	return 0;
}