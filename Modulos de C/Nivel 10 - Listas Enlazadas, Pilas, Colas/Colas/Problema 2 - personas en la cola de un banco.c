/*Ejercicio 2: Hacer un programa que guarde datos de clientes de un banco, los almacene
en cola, y por ultimo muestre los clientes en el orden correcto.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[30];
	char clave[10];
	int edad;
} Cliente;

typedef struct Nodo
{
	Cliente c;
	struct Nodo *siguiente;
} Nodo;

// Prototipos de Funciones
void cargar_cliente(Cliente *);
void insertarCola(Nodo **, Nodo **, Cliente);
void suprimirCola(Nodo **, Nodo **, Cliente *);

int main()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Cliente c;
	char rpt;
	int ki = 0;

	do
	{
		cargar_cliente(&c);				// Cargamos cliente
		insertarCola(&frente, &fin, c); // y luego lo agregamos a cola

		printf("\n Desea agregar mas clientes(s/n): ");
		fflush(stdin);
		scanf("%c", &rpt);
		printf("\n");
	} while (rpt == 'S' || rpt == 's');

	printf("\n === Carga de Clientes Exitosa ===\n\n");

	printf(" Mostrando clientes:\n");
	while (frente != NULL)
	{ // Vaciando la cola
		suprimirCola(&frente, &fin, &c);
		// Mostrando todos los clientes agregados

		if (ki >= 1)
		{
			printf("____|____|____|____|____|\n");
			printf("\n Nombre: %s\n", c.nombre);
			printf(" Clave: %s\n", c.clave);
			printf(" Edad: %i\n", c.edad);
			printf("________________________\n");
		}
		else
		{
			ki++;
			printf("\n________________________\n");
			printf("\n Nombre: %s\n", c.nombre);
			printf(" Clave: %s\n", c.clave);
			printf(" Edad: %i\n", c.edad);
			printf("________________________\n");
		}
	}

	getch();
	return 0;
}

void cargar_cliente(Cliente *c)
{

	puts("\tAgregando un Nuevo Cliente");
	printf(" Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", &c->nombre);
	printf(" Clave: ");
	fflush(stdin);
	scanf("%[^\n]", &c->clave);
	printf(" Edad: ");
	scanf("%i", &c->edad);
}

void insertarCola(Nodo **frente, Nodo **fin, Cliente c)
{

	Nodo *nuevo_nodo = malloc(sizeof(Nodo));
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;

	if (*frente == NULL)
		*frente = nuevo_nodo;
	else
		(*fin)->siguiente = nuevo_nodo;

	*fin = nuevo_nodo;
}

void suprimirCola(Nodo **frente, Nodo **fin, Cliente *c)
{
	Nodo *aux = *frente;
	*c = aux->c;

	if (*frente == *fin)
	{
		*frente = NULL;
		*fin = NULL;
	}
	else
		*frente = (*frente)->siguiente;

	free(aux);
}