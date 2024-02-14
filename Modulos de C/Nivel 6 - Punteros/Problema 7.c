//7. Pedir su nombre al usuario y devolver el numero de vocales que hay.
#include<stdio.h>

int main()
{
	int cuentaVocales(char *);
	char nombre[20];
	
	printf("Digite su nombre: ");
	gets(nombre);

	printf("Numero de vocales: %d", cuentaVocales(nombre));
	
	return 0;
}

int cuentaVocales(char *s)
{
	int cont = 0;
	while(*s) //mientras que s no sea nulo \0
	{ 
		switch(*s)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':	cont++;
		}
		s++;
	} 
	
	return cont;
}