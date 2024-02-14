/*Ejercicio 1: Hacer un programa en C++, utilizando Colas que contenga el siguiente
menu:

	1. Insertar un caracter a una cola
	2. Mostrar todos los elementos de la cola
	3. Salir
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	char dato;
	struct Nodo *siguiente;
} Nodo;

// Prototipos de Funciones
void insertarCola(Nodo **, Nodo **, char);
void suprimirCola(Nodo **, Nodo **, char *);

int main()
{
	int opc;
	char dato;

	Nodo *frente = NULL;
	Nodo *fin = NULL;

	do
	{
		puts("\t.:MENU:.");
		puts(" 1. Insertar un caracter a una cola");
		puts(" 2. Mostrar todos los elementos de la cola");
		puts(" 3. Salir");
		printf(" Opcion: ");
		scanf("%i", &opc);

		switch (opc)
		{
		case 1:
			printf("\n Ingrese el caracter para agregar a la cola: ");
			fflush(stdin);
			scanf("%c", &dato);
			insertarCola(&frente, &fin, dato);
			break;

		case 2:
			if (frente != NULL)
			{
				printf("\n Mostrando los elementos de la cola: ");
				while (frente != NULL)
				{
					suprimirCola(&frente, &fin, &dato);
					if (frente != NULL)
						printf(" %c_", dato);
					else
						printf(" %c.", dato);
				}
			}
			else
				puts("\n == cola vacia ==");
			break;

		case 3:
			exit(0);	
		}

		puts("\n");
		system("pause");
		system("cls");
	} while (opc != 3);

	return 0;
}

// Función para insertar elementos en la cola
void insertarCola(Nodo **frente, Nodo **fin, char n)
{

	Nodo *nuevo_nodo = malloc(sizeof(Nodo));
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (*frente == NULL)
		*frente = nuevo_nodo;
	else
		(*fin)->siguiente = nuevo_nodo;

	*fin = nuevo_nodo;
}

// Función para eliminar elementos de la cola
void suprimirCola(Nodo **frente, Nodo **fin, char *n)
{
	Nodo *aux = *frente;
	*n = aux->dato;

	if (*frente == *fin)
	{
		*frente = NULL;
		*fin = NULL;
	}
	else
		*frente = (*frente)->siguiente;

	free(aux);
}