/*
	declare tres variables char *texto = "asociado", otro[8], nuevo[8];
	realice la copia del texto hacia otro utilizando:

	for(i=0; otro[i] = texto[i]; i++);

	la condicion mientras sea cierto es que guarde en otro cada elemento de texto y esto se realiza como unico proceso.

	en otra sentencia agregue la otra version de copiar, utilizando apuntadores:

	for(; *nuevo = *texto; nuevo++, texto++);

	no se inicializa el puntero, se guarda cada elemento de texto en nuevo y se incrementa ambos apuntadores.

	imprima las dos cadenas ( otro y nuevo ) y comente lo aprendido:

	aprendi una nueva manera de usar el for, realizando una sola accion. 
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char *Texto = "Asociado", otro[8], nuevo[8], *ptrnuevo = nuevo;
	int i;

	for (i = 0; otro[i] = Texto[i] ; i++);
	
	for (; *ptrnuevo = *Texto; ptrnuevo++, Texto++);
	
	printf("\n cadena de texto (otro): %s",otro);
	printf("\n cadena de texto (nuevo): %s",nuevo);
	return 0;
}