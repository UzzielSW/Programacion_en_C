#include<stdio.h>
#include<string.h>

int main()
{
	char texto[] = "son letras minusculas";
	void cambiar_may(char *);

	printf("\n cadena original: %s\n",texto);
	cambiar_may(texto);
	printf(" cadena cambiada: %s\n",texto);
	
return 0;
}

void cambiar_may(char *texto){ strupr(texto); }