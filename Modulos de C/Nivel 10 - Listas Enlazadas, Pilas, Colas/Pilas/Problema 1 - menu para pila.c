/*Ejercicio 2: Hacer un programa en C++, utilizando Pilas que contenga el siguiente
menu:

	1. Insertar un caracter a la pila
	2. Mostrar todos los elementos de la pila
	3. Salir
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	char dato;
	struct Nodo *siguiente;
} Nodo;

// Prototipo
void agregarPila(Nodo **, char);
void sacarPila(Nodo **, char *);

int main()
{
	Nodo *pila = NULL;
	int opcion;
	char dato;

	do
	{
		system("cls");
		puts("\t.:MENU:.");
		puts(" 1. Insertar un caracter a la pila");
		puts(" 2. Mostrar todos los elementos de la pila");
		puts(" 3. Salir");
		printf(" Opcion: ");
		scanf("%i", &opcion);

		switch (opcion)
		{
		case 1:
			printf("\n Digite un caracter: ");
			fflush(stdin);
			scanf("%c", &dato);
			agregarPila(&pila, dato);
			break;
		case 2:
			if (pila != NULL)
			{
				printf("\n Mostrando todos los elementos de la pila: ");
				while (pila != NULL)
				{
					sacarPila(&pila, &dato);
					if (pila != NULL)
						printf(" %c ->", dato);
					else
						printf(" %c.", dato);
				}
			}
			else
				puts("\n == pila vacia ==");
			break;
		case 3:
			exit(0);
		}

		puts("\n");
		system("pause");
	} while (opcion != 3);

	return 0;
}

void agregarPila(Nodo **pila, char n)
{
	Nodo *nuevo_nodo = malloc(sizeof(Nodo));
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = *pila;
	*pila = nuevo_nodo;
}

void sacarPila(Nodo **pila, char *n)
{
	Nodo *aux = *pila;
	*n = aux->dato;
	*pila = aux->siguiente;
	free(aux);
}