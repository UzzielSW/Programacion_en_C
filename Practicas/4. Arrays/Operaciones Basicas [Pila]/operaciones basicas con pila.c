/*  * operaciones basicas con pilas
		- insertar (algoritmo en pag 80 del libro de estructura de datos)
		- sacar  (algoritmo en pag 80 del libro de estructura de datos)
		- mostrar
		- vaciar
 */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

typedef int Pila;

int main()
{
	char num[2];
	int opc;
	int MAX, TOPE=-1;
	Pila *pila;

	int insertarPila(Pila *, int, int);
	int sacarPila(Pila *, int);
	void mostrarPila(Pila *, int);
	int vaciarPila(Pila *, int);

	printf("\n ingrese el numero maximo de elementos de la pila: ");
	scanf("%d",&MAX);
	
	pila = (Pila *) malloc(MAX*sizeof(Pila));
	
	for(int i=0 ; i < MAX; i++)	*(pila+i)=0; //inicializando los valores de la pila para que no almacene basura

	do
	{	system("cls");
		itoa(TOPE, num, 10);
		printf("\n .:Aplicacion de Pila con vector:.\t\t\ttope: %s", (TOPE<MAX-1 ? num : "MAX"));
		printf("\n 1.Insertar un elemento -Push- en la pila");
		printf("\n 2.Eliminar un elemento -Pop- de la pila");
		printf("\n 3.Mostrar Pila");
		printf("\n 4.Vaciar Pila");
		printf("\n 5.Exit");
		printf("\n option? ");
		scanf("%d",&opc);

		switch(opc){
			case 1:
				TOPE = insertarPila(pila, TOPE, MAX);
			break;

			case 2:
				TOPE = sacarPila(pila, TOPE);
			break;

			case 3:
				mostrarPila(pila, TOPE);
			break;

			case 4:
				TOPE = vaciarPila(pila, TOPE);
				mostrarPila(pila, TOPE);
			break;

			default: opc=5; break;
		}getch();
	} while (opc!=5);
	
	free(pila);
	
return 0;
}

int insertarPila(Pila *pila, int TOPE, int MAX)
{
	if(TOPE == MAX-1)
	printf("\n Subdesbordamiento - Pila llena");	
	else{
		int Dato, ver;
		printf("\n ingresar el dato a insertar a la pila: ");
		ver = scanf("%d",&Dato);

		if(ver){ //si el dato fue leido correctamente se agrega a la pila
			TOPE+=1;
			*(pila+TOPE) = Dato;
		}
	}

return TOPE;
}

int sacarPila(Pila *pila, int TOPE)
{
	if(TOPE == -1)
		printf("\n Subdesbordarniento - Pila vacia");
	else{
		int Dato;
		Dato = *(pila+TOPE);
		*(pila+TOPE) = 0;
		TOPE--;
		printf("\n Elemento sacado de la pila: %d ", Dato);
	}

	return TOPE;
}

void mostrarPila(Pila *pila, int TOPE)
{
	putchar('\n');
	if (TOPE != -1)
	{
		for (int i = 0; i <= TOPE ; ++i)
			printf("%2d -> ",*(pila+i));
			
		printf("(null)\n");
	}
	else 
		printf(" La Pila esta vacia");
}

int vaciarPila(Pila *pila, int TOPE){

	for (int i = 0; i <= TOPE; ++i)
		*(pila+i) = 0;

return -1;
}