/*
	16. Hacer un programa en C. Para guardar los numeros de celular, que muestre un menu 
	con las siguientes opciones:
	
	1. Crear(nombre,apellidos,celular)
	2. Agregar mas contactos(nombre,apellidos,celular)
	3. Visualizar contactos existentes
*/
#include<stdio.h>
#include<stdlib.h>

FILE *fd;

typedef struct
{
	char nombre[20];
	char apellidos[20];
	char celular[10];
}datosPersonales;

datosPersonales datos;

void crear()
{
	char direccion[] = "directorio_telefonico.txt";
	char rpt;
	fd = fopen(direccion,"wt"); //wt = write text - escribir texto
	
	if(fd == NULL)
	{
		puts("Error al tratar de crear el archivo");
		return 1;
	}
	
	puts("\n\t.:Creando Directorio de contactos:.");
	fprintf(fd,"\t.:Directorio Telefonico\n");
	do{
		fflush(stdin);
		printf("\nNombre: "); gets(datos.nombre);
		printf("Apellidos: "); gets(datos.apellidos);
		printf("Celular: "); gets(datos.celular);
		
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);
		
		fprintf(fd, "\nApellidos: ");
		fwrite(datos.apellidos, 1, strlen(datos.apellidos), fd);
		
		fprintf(fd, "\nCelular: ");
		fwrite(datos.celular, 1, strlen(datos.celular), fd);
		
		printf("Desea agregar mas contactos(s): ");
		scanf("%c",&rpt);
	}while(rpt == 's');
}

void agregar()
{
	char direccion[] = "directorio_telefonico.txt";
	char rpt;

	fd = fopen(direccion,"at"); //at = add text - agregar texto
	
	if(fd == NULL)
	{
		puts("Error al tratar de crear el archivo");
		return 1;
	}
	
	puts("\n\t.:Agregando contactos:.");
	do{
		fflush(stdin);
		printf("\nNombre: "); gets(datos.nombre);
		printf("Apellidos: "); gets(datos.apellidos);
		printf("Celular: "); gets(datos.celular);
		
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);
		
		fprintf(fd, "\nApellidos: ");
		fwrite(datos.apellidos, 1, strlen(datos.apellidos), fd);
		
		fprintf(fd, "\nCelular: ");
		fwrite(datos.celular, 1, strlen(datos.celular), fd);
		
		printf("Desea agregar mas contactos(s): ");
		scanf("%c",&rpt);
	}while(rpt == 's');
}

void visualizar()
{
	int c;
	char direccion[] = "directorio_telefonico.txt";
	
	fd = fopen(direccion,"r");
	
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
}

int main()
{
	int opc;
	
	do{
		printf("\n\t.:MENU:.\n");
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