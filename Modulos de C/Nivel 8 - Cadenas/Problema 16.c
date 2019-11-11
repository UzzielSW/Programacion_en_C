/*
	16. Pedir al usuario su nombre,apellido, y ciudad en la que vive, posteriormente
	convertir todo a MAYUSCULAS e imprimir los datos.(Utilizar una estructura)
*/
#include<stdio.h>
#include<string.h>

struct Datos
{
	char nombre[20];
	char apellidos[20];
	char ciudad[20];
};

int main()
{
	Datos dato;
	printf("Digite su nombre: ");
	gets(dato.nombre);

	printf("Digite sus apellidos: ");
	gets(dato.apellidos);

	printf("Digite su ciudad: ");
	gets(dato.ciudad);
	
	//Convirtiendo a MAYUSCULAS
	strupr(dato.nombre);
	strupr(dato.apellidos);
	strupr(dato.ciudad);
	
	//Mostrando datos convertidos
	printf("\nSu nombre: %s",dato.nombre);
	printf("\nSus apellidos: %s",dato.apellidos);
	printf("\nSu ciudad: %s",dato.ciudad);
	
	return 0;
}