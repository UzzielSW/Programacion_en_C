/*
	15. Hacer un programa en C. Para guardar direcciones de correo que muestre un menu 
	con las siguientes opciones:
	
		1. Crear(nombre,apellidos,email)
		2. Agregar mas contactos(nombre,apellidos,email)
		3. Visualizar contactos existentes
*/
#include<stdio.h>
#include<stdlib.h>

FILE *fd;

struct DatosPersonales
{
	char nombre[20];
	char apellidos[20];
	char email[30];
}datos;

void crear()
{	
	char direccion[] = "directorio_emails.txt";
	char rpt;

	fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL)
	{
		printf("Error al tratar de crear el archivo");
		return 1;
	}
	
	puts("\n\t.:Creando Directorio de Email:.");
	fprintf(fd,"\tDirectorio de Email");
	do{
		fflush(stdin);
		printf("\nNombre: "); gets(datos.nombre);
		printf("Apellidos: "); gets(datos.apellidos);
		printf("Email: "); gets(datos.email);
		
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);

		fprintf(fd, "\nApellidos: ");
		fwrite(datos.apellidos, 1, strlen(datos.apellidos), fd);

		fprintf(fd, "\nEmail: ");
		fwrite(datos.email, 1, strlen(datos.email), fd);

		printf("Desea Agregar mas contactos(s) (s/n): ");
		scanf("%c",&rpt);		
	}while(rpt == 's');
}

void agregar()
{
	char direccion[] = "directorio_emails.txt";
	char rpt;

	fd = fopen(direccion,"at"); //at = add text -- agregar texto
	
	if(fd == NULL)
	{
		printf("Error al tratar de leer el archivo");
		return 1;
	}

	puts("\n\t.:Agregando mas contactos:.");
	do{
		fflush(stdin);
		printf("\nNombre: "); gets(datos.nombre);
		printf("Apellidos: "); gets(datos.apellidos);
		printf("Email: "); gets(datos.email);
		
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);

		fprintf(fd, "\nApellidos: ");
		fwrite(datos.apellidos, 1, strlen(datos.apellidos), fd);

		fprintf(fd, "\nEmail: ");
		fwrite(datos.email, 1, strlen(datos.email), fd);

		printf("Desea seguir agregando contantos(s) (s/n):");
		scanf("%c",&rpt);
	}while(rpt == 's');	
}

void visualizar()
{
	int c;
	char direccion[] = "directorio_emails.txt";
	
	fd = fopen(direccion,"r"); // r = read - leer
	
	if(fd == NULL)
	{
		puts("Error al tratar de leer el archivo");
		return 1;
	}
	
	puts("\n\t.:Visualizando Contactos:.\n");
	while((c = fgetc(fd)) != EOF)
	{
		if(c == '\n')
			puts("");
		else
			putchar(c);
	}
	puts("\n");
}

int main()
{
	int opc;
	
	do{
		printf("\n\t.:MENU:.");
		printf("\n1. Crear");
		printf("\n2. Agregar mas contactos");
		printf("\n3. Visualizar contactos existentes");
		printf("\n4. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1: crear();break;
			case 2: agregar();break;
			case 3: visualizar();break;
		}
		
	}while(opc != 4);
	
	return 0;
}