/*
	7. Ingresar por teclado el nombre y el signo de cualquier persona e imprima, el nombre solo si la persona es signo Aries, caso contrario imprima no es signo Aries
*/
#include<stdio.h>

int main()
{
	char nombre[20], signo[20];
	
	printf("Escriba su nombre: ");
	gets(nombre);
	printf("Escriba su signo: ");
	gets(signo);
	
	strlwr(signo); //funcion para convertir a minuscula
	
	if(strcmp(signo,"aries") == 0)
		printf("\nSu nombre es: %s",nombre);
	else
		puts("\nNo es signo Aries");

	return 0;
}