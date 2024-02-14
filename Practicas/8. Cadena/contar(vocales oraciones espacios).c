/*
	dado un vector de caracteres con un texto de 50 caracteres:

	a.imprimir letra por letra,en contenido del vector
	b.contar la cantidad de espacios en blanco
	c.contar la cantidad de vocales
	d.contar las oraciones
	e.contar la cantidad de palabras
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char palabra[100];
	int space = 0, vocales = 0, oraciones = 0, palabras = 0, i, sec = 0; // Contadores
	int lon = 0; // Guardar la longuitud del Vector

	fflush(stdin);
	printf(" Ingrese el texto: \n"); // Pedimos la cadena al Usuario
	scanf("%[^\n]", palabra);
	lon = strlen(palabra);

	printf("\nA. Imprime letra por letra, el contenido del Vector:\n");
	for (i = 0; i < lon; i++)
	{
		printf("%c", palabra[i]);
	}

	// tolower(palabra);
	for (i = 0; i < lon; ++i)
	{
		switch (palabra[i])
		{
		case ' ':
			space++;
			break; // B. Contar la cantidad de espacios en blanco.
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vocales++;
			break; // C. Contar la cantidad de Vocales
		}
		// E. Contar la cantidad de palabras
		if (isalnum(palabra[i]))	// si es un numero o letra
			sec++;
		else if (!(isalnum(palabra[i])) && sec > 0)
		{
			palabras++;
			sec = 0;
		}
		// D. Contar la cantidad de Oraciones
		if (palabra[i] == '.' || palabra[i] == '!' || palabra[i] == '?')
			oraciones++;
	}

	printf("\n\n La cantidad de espacios es %i", space);
	printf("\n La cantidad de vocales es %i", vocales);
	printf("\n La cantidad de oraciones es %i", oraciones);
	printf("\n La cantidad de palabras es %i\n", palabras);
	return 0;
}