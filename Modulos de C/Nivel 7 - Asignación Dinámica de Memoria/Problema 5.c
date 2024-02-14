/*
	5. Reservar espacio en memoria dinamica para un nombre, y luego liberar la memoria
	utilizada con free().
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char nombre[20], *p_nombre;
	int longitud;
	
	strcpy(nombre,"Alejandro");
	
	longitud = strlen(nombre);
	
	p_nombre = malloc((longitud + 1) * sizeof(char));
	
	strcpy(p_nombre,nombre); 
	
	printf("Nombre: %s",p_nombre);
	
	free(p_nombre); //Liberamos el espacio de memoria dinamica
	
	printf("\nNombre: %s",p_nombre);//Comprobando que se libero es espacio
	
	return 0;
} 