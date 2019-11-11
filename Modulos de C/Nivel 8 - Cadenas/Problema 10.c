//10. Pedir 2 nombres al usuario y comparar si son iguales o no.
#include<stdio.h>
#include<string.h>

int main()
{
	char nombre1[20], nombre2[20];
	
	printf("Digite el primer nombre: ");
	gets(nombre1);

	printf("Digite el segundo nombre: ");
	gets(nombre2);
	
	if(strcmp(nombre1,nombre2) == 0)
		puts("Ambos nombres son iguales");
	else
		puts("Los nombres son distintos");
	
	return 0;
}