/*
	11. Dada una nota de un examen mediante un código escribir el literal que le corresponde a la nota.

	A - Excelente
	B - Notable
	C - Aprobado
	D y F - Reprobado
*/
#include<stdio.h>
#include <ctype.h>

int main()
{
	char nota; 
	
	printf("Digite la calificacion (A-F): ");
	scanf("%c",&nota);
	
	nota = toupper(nota); //convertir a mayuscula

	switch(nota)
	{
		case 'A': puts("Excelente");break;
		case 'B': puts("Notable");break;
		case 'C': puts("Aprobado");break;
		case 'D':
		case 'F': puts("Reprobado");break;
		default: puts("No es posible esa nota");
	}
	return 0;
}