/*
	•: operaciones basicas con cola
		-• Insertar un elemento en la cola (pag 95)
			.Las inserciones se llevarán a cabo por el FINAL de la cola,
		-• Eliminar un elemento de la cola (pag 96)
			.mientras que las eliminaciones se harán por el FRENTE
		-• mostrar
		-• vaciar
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef int Cola;

int main()
{
	char num1[20];
	char num2[20];
	int opc = 0, MAX;
	int frente, final;
	frente = -1;
	final = -1;
	Cola *cola;

	int insertarCola(Cola *, int *, int, int);
	int sacarCola(Cola *, int, int *);
	void mostrarCola(Cola *, int, int);

	printf("\n ingrese el numero maximo de elementos de la cola: ");
	scanf("%d", &MAX);

	cola = (Cola *)calloc(MAX, sizeof(Cola));

	for (int i = 0; i < MAX; i++)
		*(cola + i) = 0; // inicializando los valores de la cola para que no almacene basura

	do
	{
		system("cls");
		itoa(frente, num1, 10);
		itoa(final, num2, 10);
		printf("\n .:Aplicacion de Cola con vector:.\t\t\tFrente: %s", (frente < MAX - 1 ? num1 : "MAX"));
		printf("\n 1.Insertar un elemento -Push- en la cola\t\tFinal: %s", (final < MAX - 1 ? num2 : "MAX"));
		printf("\n 2.Eliminar un elemento -Pop- de la cola");
		printf("\n 3.Mostrar Cola");
		printf("\n 4.Vaciar Cola");
		printf("\n 5.Exit");
		printf("\n option? ");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			final = insertarCola(cola, &frente, final, MAX);
			break;

		case 2:
			frente = sacarCola(cola, frente, &final);
			break;

		case 3:
			mostrarCola(cola, frente, final);
			break;

		case 4:
			final = frente = -1;
			mostrarCola(cola, frente, final);
			break;

		default:
			opc = 5;
			break;
		}
		getch();
	} while (opc != 5);

	free(cola);

	return 0;
}

int insertarCola(Cola *cola, int *frente, int final, int MAX)
{
	if (final < MAX - 1)
	{
		Cola Dato, ver;
		printf("\n ingrese el dato a insertar a la cola: ");
		ver = scanf("%d", &Dato);

		if (ver)
		{ // si el dato fue leido correctamente se agrega a la cola
			final += 1;
			*(cola + final) = Dato;
			printf("\n Dato %d agregado a la cola", *(cola + final));
			if (final == 0)
				*frente = 0;
		}
	}
	else
		printf("\n Desbordamiento - Cola llena");

	return final;
}

int sacarCola(Cola *cola, int frente, int *final)
{
	if (*final != -1)
	{
		Cola Dato;
		Dato = *(cola + frente);
		*(cola + frente) = 0;

		if (frente == *final)
		{ // si hay un solo elemento se vacia la cola
			*final = -1;
			frente = -1;
		}
		else
			frente += 1;

		printf("\n Elemento %d sacado de la Cola", Dato);
	}
	else
		printf("\n Subdesbordamiento - Cola vacia");

	return frente;
}

void mostrarCola(Cola *cola, int frente, int final)
{
	if (final != -1)
	{
		putchar('\n');
		for (int i = frente; i <= final; i++)
			printf("%2d -> ", *(cola + i));

		printf("(null)");
	}
	else
		printf("\n La Cola esta vacia");
}