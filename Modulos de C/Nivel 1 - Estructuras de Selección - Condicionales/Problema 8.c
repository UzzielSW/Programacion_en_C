/*
	8. Ingresar por teclado el nombre, la edad y el sexo de cualquier persona e imprima, solo si la persona es de sexo masculino y mayor de edad, el nombre de la persona.
*/
#include<stdio.h>

int main()
{
	char nombre[20], sexo[10];
	int edad;
	
	printf("Digite su nombre: ");
	gets(nombre);

	printf("Digite su edad: ");
	scanf("%d",&edad);
	fflush(stdin);

	printf("Digite su sexo: ");
	gets(sexo);
	
	if((strcmp(sexo,"masculino") == 0) && (edad >= 18))
		printf("\nCumple con los requisitos: %s",nombre);
	else
		puts("\nNo cumple con los requisitos");
	
	return 0;
}