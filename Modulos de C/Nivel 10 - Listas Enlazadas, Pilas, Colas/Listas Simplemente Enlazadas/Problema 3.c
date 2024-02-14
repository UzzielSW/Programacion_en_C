/*
LISTAS ENLAZADAS:
cree una estructura de jugadores por pais de las olimpiadas de londres, donde se almacene el nombre,pais,
la edad y la disciplina. por medio de un menu administre la lista enlazada, para que agregue, elimine y
liste los elementos de la lista y eliminar todos los jugadores de la lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Nodo
{
	char nombre[30], pais[20], disciplina[20];
	int edad;
	struct Nodo *sgte;
} Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

int main()
{
	int opc;
	void agregar_jugador();
	void eliminar_jugador();
	void lista_jugadores();
	void eliminar_all();
	do
	{
		system("cls");
		printf("\n OLIMPIADAS DE LONDES");
		printf("\n 1.agregar jugadores");
		printf("\n 2.eliminar jugador");
		printf("\n 3.listar jugadores");
		printf("\n 4.eliminar todos los jugadores de lista");
		printf("\n 5.salir");
		printf("\n elije una opcion: ");
		scanf("%i", &opc);
		switch (opc)
		{
		case 1:
			agregar_jugador();
			break;
		case 2:
			eliminar_jugador();
			break;
		case 3:
			lista_jugadores();
			break;
		case 4:
			eliminar_all();
			break;
		case 5:
			break;
		default:
			printf("\n opcion invalida");
		}
		printf("\n\n");
		system("pause");
	} while (opc != 5);
	return 0;
}

void agregar_jugador()
{
	void insertar_nodo(Nodo *);
	Nodo *nuevo = malloc(sizeof(Nodo));

	printf("\n  .:Agregando un nuevo jugador:.\n");
	printf(" Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", &nuevo->nombre);
	printf(" pais: ");
	fflush(stdin);
	scanf("%[^\n]", &nuevo->pais);
	printf(" disciplina: ");
	fflush(stdin);
	scanf("%[^\n]", &nuevo->disciplina);
	printf(" Edad: ");
	scanf("%i", &nuevo->edad);

	insertar_nodo(nuevo);
}

void insertar_nodo(Nodo *nuevo)
{
	nuevo->sgte = NULL;

	if (primer == NULL)
	{
		primer = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->sgte = nuevo;
		ultimo = nuevo;
	}
}

void eliminar_jugador()
{
	if (primer != NULL)
	{
		char juga[30];
		bool veri = false;
		Nodo *temp = primer;
		Nodo *anterior = NULL;
		printf("\n ingrese el jugador que desea eliminar de la lista: ");
		fflush(stdin);
		scanf("%[^\n]", &juga);

		while (veri != false || temp != NULL)
		{
			if (strcmp(temp->nombre, juga) == 0)
			{
				veri = true;
				printf("\n .:jugador %s eliminado de lista:.", temp->nombre);
				break;
			}
			anterior = temp;
			temp = temp->sgte;
		}

		if (temp == NULL)
			printf("\n === jugador no se encontro en lista ===");
		else if (anterior == NULL)
		{
			primer = primer->sgte;
			free(temp);
		}
		else
		{
			anterior->sgte = temp->sgte;
			if (temp->sgte == NULL)
			{
				ultimo->sgte = anterior;
				ultimo = anterior;
			}
			free(temp);
		}
	}
	else
		printf("\n === lista de jugadores vacia ===");
}

void lista_jugadores()
{
	Nodo *actual = primer;
	if (primer != NULL)
	{
		printf("\n\n === Lista de jugadores ===");
		while (actual != NULL)
		{
			printf("\n\n nombre: %s", actual->nombre);
			printf("\n pais: %s", actual->pais);
			printf("\n disciplina: %s", actual->disciplina);
			printf("\n edad: %i", actual->edad);
			actual = actual->sgte;
		}
	}
	else
		printf("\n === lista de jugadores vacia ===");
}

void eliminar_all()
{
	if (primer != NULL)
	{
		while (primer != NULL)
		{
			Nodo *temp = primer;
			primer = primer->sgte;
			free(temp);
		}
		printf("\n === Todos los jugadores han sido eliminados ===");
	}
	else
		printf("\n === lista de jugadores vacia ===");
}