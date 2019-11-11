/*
	17. Pedir su nombre y apellidos al usuario (en mayuscula), porteriormente utilizar
	la funcion strlwr() para convertir las MAYUSCULAS en minusculas e imprimir los datos.
*/
#include<stdio.h>
#include<string.h>

struct Datos
{
	char nombre[20];
	char apellidos[20];
};

int main()
{
	Datos dato;

	printf("Digite su nombre (en MAYUSCULAS): ");
	gets(dato.nombre);

	printf("Digite sus apellidos (en MAYUSCULAS): ");
	gets(dato.apellidos);
	
	//Convirtiendo a minusculas
	strlwr(dato.nombre);
	strlwr(dato.apellidos);
	
	//Mostrando datos convertidos
	printf("\nSu nombre: %s",dato.nombre);
	printf("\nSus apellidos: %s",dato.apellidos);
	
	return 0;
}