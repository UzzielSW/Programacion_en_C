/*
	pag 47.
	crear un directorio telefonico que sera guardado en un archivo. debe incluir los nombres, 
	direcciones y numeros de telefono. representar cada registro como una estructura. debe
	utilizar un menu que contenga los siguientes puntos:
	1. agregar una persona
	2. borrar una persona
	3. modificar los datos de una persona
	4. consultar los datos de una persona
	5. generar la lista completa de todo el directorio
	6. salir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *archivo;
FILE *temp;

typedef struct 
{
	char nombre[20];
	char direccion[30];
	long telefono;
}Directorio;

Directorio leer(Directorio);

int main()
{
	int opc;
	Directorio nuevo;
	void agregar(Directorio);
	void borrar(Directorio);
	void modificar(Directorio); 
	void consultar(Directorio);
	void lista(Directorio);

	do{	system("cls");
		system ("color 71");
		puts("\n DIRECTORIO TELEFONICO");
		puts(" 1.Agregar una persona");
		puts(" 2.Borrar una persona");
		puts(" 3.modificar los datos de una persona");
		puts(" 4.Consultar los datos de una persona");
		puts(" 5.Generar la lista completa de todo el directorio");
		puts(" 6.salir");
		printf("\n opcion: ");	scanf("%d",&opc);

		switch(opc)
		{
			case 1: agregar(nuevo);	  break;
			case 2: borrar(nuevo);    break;
			case 3: modificar(nuevo); break;
			case 4: consultar(nuevo); break;
			case 5: lista(nuevo);     break;
			case 6: break;
			default: puts("\n opcion invalida");
		}
		fflush(stdin);
		getchar();
	} while(opc != 6);

	return 0;
}

Directorio leer(Directorio nuevo)
{
	fscanf(archivo, " %[^\n]", &nuevo.nombre);
	fscanf(archivo, " %[^\n]", &nuevo.direccion);
	fscanf(archivo, "%ld", &nuevo.telefono);
	return nuevo;
}

void agregar(Directorio nuevo)
{
	archivo = fopen("directorio_telefonico.dat","a+");
	if(archivo == NULL) puts("\n no se creo el archivo");
	else
	{
		puts("\n .:nuevo directorio:.");
		fflush(stdin);
		printf("\n ingrese su nombre: "); scanf("%[^\n]", &nuevo.nombre);
		fflush(stdin);
		printf(" ingrese su direccion: "); scanf("%[^\n]", &nuevo.direccion);
		printf(" ingrese su telefono: "); scanf("%ld", &nuevo.telefono);

		fprintf(archivo, "%s\n", nuevo.nombre);
		fprintf(archivo, "%s\n", nuevo.direccion);
		fprintf(archivo, "%ld\n", nuevo.telefono);

		fclose(archivo);
	}
}

void borrar(Directorio nuevo)
{	
	char verifi[20];  bool desi = false;  
	fflush(stdin);

	temp = fopen("temporal.dat","w+");

	archivo = fopen("directorio_telefonico.dat","r+");

	printf("\n ingrese su nombre: "); scanf("%[^\n]",&verifi);

	if(temp == NULL && archivo == NULL) puts("\n no se encontro el archivo o no se creo");
	else
	{
		nuevo = leer(nuevo);
		while(feof(archivo) == 0)
		{	
			if((strcmp(nuevo.nombre,verifi) == 0) && (desi == false))
			{ 
				desi = true; 
				puts("\n directorio eliminado"); 
			}
			else
			{
				fprintf(temp, "%s\n", nuevo.nombre);
				fprintf(temp, "%s\n", nuevo.direccion);
				fprintf(temp, "%ld\n", nuevo.telefono);
			}

			nuevo = leer(nuevo);
		}

		fclose(archivo);
		fclose(temp);
		remove("directorio_telefonico.dat");
		rename("temporal.dat", "directorio_telefonico.dat");

		if (desi == false) printf("\n directorio telefonico con el nombre %s no se encontro", verifi);
	}
}

void modificar(Directorio nuevo)
{	
	char verifi[20];  bool desi = false;  
	fflush(stdin);

	temp = fopen("temporal.dat","w+");

	archivo = fopen("directorio_telefonico.dat","r+");

	printf("\n ingrese su nombre: "); scanf("%[^\n]",&verifi);

	if(temp == NULL && archivo == NULL) printf("\n no se encontro el archivo o no se creo");
	else
	{
		nuevo = leer(nuevo);
		while(feof(archivo) == 0)
		{	
			if((strcmp(nuevo.nombre,verifi) == 0) && (desi == false))
			{ 
				desi = true; 
				fflush(stdin);
				printf(" ingrese nueva direccion: "); scanf("%[^\n]", &nuevo.direccion);
				printf(" ingrese nuevo telefono: "); scanf("%ld", &nuevo.telefono);
				fprintf(temp, "%s\n", nuevo.nombre);
				fprintf(temp, "%s\n", nuevo.direccion);
				fprintf(temp, "%ld\n", nuevo.telefono);
				printf("\n directorio modificado"); 
			}
			else
			{
				fprintf(temp,"%s\n",nuevo.nombre);
				fprintf(temp,"%s\n",nuevo.direccion);
				fprintf(temp,"%ld\n",nuevo.telefono);
			}

			nuevo = leer(nuevo);
		}

		fclose(archivo);
		fclose(temp);
		remove("directorio_telefonico.dat");
		rename("temporal.dat", "directorio_telefonico.dat");

		if (desi == false) printf("\n directorio telefonico con el nombre %s no se encontro",verifi);
	}
}

void consultar(Directorio nuevo)
{	
	char verifi[20];  bool desi = false;
	fflush(stdin);

	printf("\n ingrese su nombre: "); scanf("%[^\n]",&verifi);

	archivo = fopen("directorio_telefonico.dat","r+");

	if(archivo == NULL) printf("\n no se encontro el archivo");
	else
	{
		while(feof(archivo) == 0)
		{	
			nuevo = leer(nuevo);
			if(strcmp(nuevo.nombre, verifi) == 0){ desi = true; break;  }
		}

		if (desi == true)
		{
			printf("\n .:directorio:.");
			printf("\n nombre: %s",nuevo.nombre);
			printf("\n direccion: %s",nuevo.direccion);
			printf("\n telefono: %ld",nuevo.telefono);
		}else puts("\n directorio telefonico no se encontro");

		fclose(archivo);
	}
}


void lista(Directorio nuevo)
{	
	int con=0;

	puts("\n lista completa del directorio: ");
	archivo = fopen("directorio_telefonico.dat","r+");

	if(archivo == NULL) puts("\n no se encontro el archivo");
	else
	{
		nuevo = leer(nuevo);
		while(feof(archivo) == 0)
		{ 
			++con;	
			printf("\n\n .:directorio #%d:.", con);
			printf("\n nombre: %s", nuevo.nombre);
			printf("\n direccion: %s", nuevo.direccion);
			printf("\n telefono: %ld", nuevo.telefono);	
			nuevo = leer(nuevo);
		}

		fclose(archivo);
	}
}