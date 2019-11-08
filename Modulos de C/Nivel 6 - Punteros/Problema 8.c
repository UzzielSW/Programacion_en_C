/*
	8. Pedir una cadena de caracteres (string) al usuario, e indicar cuantas veces 
	aparece la vocal a,e,i,o,u; en la cadena de caracteres.
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char palabra[50];
	int vocalA(char *);
	int vocalE(char *);
	int vocalI(char *);
	int vocalO(char *);
	int vocalU(char *);
	
	printf("Digite una palabra: ");
	gets(palabra);

	strlwr(palabra);//convertir a minuscula
	printf("\nLa vocal 'a' aparece: %d veces",vocalA(palabra));
	printf("\nLa vocal 'e' aparece: %d veces",vocalE(palabra));
	printf("\nLa vocal 'i' aparece: %d veces",vocalI(palabra));
	printf("\nLa vocal 'o' aparece: %d veces",vocalO(palabra));
	printf("\nLa vocal 'u' aparece: %d veces",vocalU(palabra));

	return 0;
}

int vocalA(char *s)
{
	int cont = 0;
	while(*s)	//mientras s no sea nulo: \0
	{ 
		if(*s == 'a') cont++
		s++;	
	}

	return cont;
}

int vocalE(char *s)
{
	int cont = 0;
	while(*s)
	{ 
		if(*s == 'e') cont++;
		s++;	
	}

	return cont;
}

int vocalI(char *s)
{
	int cont = 0;
	while(*s)
	{
		if(*s == 'i') cont++;
		s++;	
	}

	return cont;
}

int vocalO(char *s)
{
	int cont = 0;
	while(*s)
	{
		if(*s == 'o') cont++;
		s++;	
	}

	return cont;
}

int vocalU(char *s)
{
	int cont = 0;
	while(*s)
	{
		if(*s == 'u') cont++;
		s++;	
	}

	return cont;
}