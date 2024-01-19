#include<stdio.h>
#include<string.h>

int main()
{
	char texto[80];
	void cambiar(char *);

	printf("\n Digite el texto: ");
    fgets(texto, sizeof(texto), stdin);
	
	printf("\n texto: %s",texto);
	cambiar(texto);
	printf("\n texto Invertido: %s",texto);
	
	return 0;
}

void cambiar(char *texto){ strrev(texto); }