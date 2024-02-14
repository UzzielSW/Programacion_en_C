/*
   operaciones basicas con listas enlazadas:
      -insertar un dato en la lista
      -modificar un dato en la lista
      -eliminar un dato en la lista
      -eliminar toda la lista
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
   int valor;              // Valor que va tener la estructura en cada uno en este caso es un numero entero
   struct nodo *siguiente; // Apuntador hacia el siguiente nodo o enlace
} nodo;

typedef nodo *TipoLista; // Definicion del nombre de la lista

enum
{
   ascen = 0,
   descen
};

// declaracion de funciones que posee la listas
void Insertar(TipoLista *l, int v);
void Modificar(TipoLista l, int v, int n);
void MostrarLista(TipoLista l);
void EliminarNodo(TipoLista *l, int v);
void VaciarLista(TipoLista *l);
void OrdenarLista(TipoLista l, int, bool (*)(int, int));
bool ascendente(int, int);  // implementa el orden ascendente
bool descendente(int, int); // implementa el orden descendente
int cant = 0;

int main()
{
   TipoLista lista = NULL; // Inicio de listas en Nulo
   int opc, x, n;

   do
   {
      system("cls");
      printf("\t .:MENU:.\n\n");
      printf(" 1. Agregar dato\n");
      printf(" 2. Modificar dato\n");
      printf(" 3. Mostrar datos\n");
      printf(" 4. Eliminar dato\n");
      printf(" 5. Vaciar lista\n");
      printf(" 6. Ordenar lista\n");
      printf(" 7. Salir\n\n");
      printf(" opcion? ");
      scanf("%i", &opc);

      switch (opc)
      {
      case 1:
         do
         { // SE CREA UNA LISTA HASTA QUE EL USUARIO PRECIONE 0
            printf("\n Digite  Cero (0) para salir\n");
            printf(" Digite el dato que desea agregar: ");
            scanf("%d", &x);
            if (x != 0)
               Insertar(&lista, x); // ENVIO DE VALOR AL PROCESO DE INSERTAR DATOS A LISTA
         } while (x != 0);
         break;

      case 2:
         if (lista != NULL)
         {
            MostrarLista(lista);
            printf("\n Digite el dato que desea modificar: ");
            scanf("%d", &x); // MODIFICACION DE DATOS
            printf(" Digite el dato nuevo: ");
            scanf("%d", &n);        // LEE NUEVO DATO
            Modificar(lista, x, n); // ENVIO A FUNCION DE ENCONTRAR DATO Y CAMBIAR A ACTUAL
         }
         else
            printf("\n === lista vacia ===");
         break;

      case 3:
         MostrarLista(lista);
         break;

      case 4:
         MostrarLista(lista);
         if (lista != NULL)
         {
            printf("\n Digite el dato que desea eliminar: ");
            scanf("%d", &x);
            EliminarNodo(&lista, x); // ELIMINA DATO QUE  VERIFICA EL USUARIO
         }
         break;

      case 5:
         VaciarLista(&lista);
         break;
      case 6:
         if (lista)
         {
            MostrarLista(lista);
            printf("\n digite [0] ascendente o [1] descendente: ");
            scanf("%d", &x); // orden para ordenar
            if (x)
               OrdenarLista(lista, x, descendente);
            else
            {
               OrdenarLista(lista, x, ascendente);
            }
            MostrarLista(lista);
         }
         else
            printf("\n === lista vacia ===");
         break;
      case 7:
         exit(0);

      default:
         printf("\n Opcion no valida!");
      }
      getch();
   } while (opc != 7);
   return 0;
}

// Insertar registro(insertando nodos adelante)
void Insertar(TipoLista *lista, int valor)
{
   TipoLista nuevo = malloc(sizeof(TipoLista));
   nuevo->valor = valor;
   nuevo->siguiente = *lista;
   *lista = nuevo;
   cant++;
}

// modificar un nodo
void Modificar(TipoLista lista, int v, int n)
{
   TipoLista aux = lista;
   int ban = 0;

   while (aux)
   {
      if (aux->valor == v)
      {
         aux->valor = n;
         ban = 1;
         printf("\n == Registro Modificado ==");
         MostrarLista(lista);
         break;
      }
      aux = aux->siguiente;
   }
   if (ban == 0)
      printf("\n No se encontro en el registro");
}

void MostrarLista(TipoLista lista)
{
   if (lista == NULL)
      printf("\n === Lista vacia ===");
   else
   {
      printf("\n");
      TipoLista aux = lista;
      while (aux)
      {
         if (aux->siguiente)
         {
            printf(" %d ->", aux->valor);
            aux = aux->siguiente;
         }
         else
         {
            printf(" %d", aux->valor);
            aux = aux->siguiente;
         }
      }
      printf("\n");
   }
}

// eliminar un nodo de la lista
void EliminarNodo(TipoLista *lista, int v)
{
   TipoLista aux, anterior;
   aux = *lista;
   int ban = 0;

   while (aux != NULL)
   {
      if (aux->valor == v)
      {
         cant--;
         ban = 1;
         printf("\n === Nodo %i eliminado del Registro ===", aux->valor);
         if (aux == *lista)
            *lista = (*lista)->siguiente;
         else
            anterior->siguiente = aux->siguiente;

         free(aux);
         MostrarLista(*lista);
         return;
      }
      anterior = aux;
      aux = aux->siguiente;
   }

   if (ban == 0)
      printf("\n No se encontro el registro\n");
}

// Vaciar toda la lista
void VaciarLista(TipoLista *lista)
{
   if (*lista != NULL)
   {
      cant = 0;
      while (*lista != NULL)
      {
         TipoLista aux = *lista;
         aux = *lista;
         *lista = (*lista)->siguiente;
         free(aux);
      }
      printf("\n === la lista fue vaciada ===");
   }
   else
      printf("\n === Lista vacia ===\n");
}

void OrdenarLista(TipoLista lista, int orden, bool (*compara)(int, int))
{
   TipoLista temp = lista;
   int *array = malloc(cant * sizeof(int));
   int i, k, aux;
   i = k = aux = 0;

   while (temp)
   {
      array[i] = temp->valor;
      temp = temp->siguiente;
      i++;
   }

   for (i = 0; i < cant; i++)
   {
      k = i;
      aux = array[i];
      while ((k > 0) && !(*compara)(aux, array[k - 1]))
      {
         array[k] = array[k - 1];
         k--;
      }
      array[k] = aux;
   }

   temp = lista;
   i = 0;
   while (temp)
   {
      temp->valor = array[i];
      temp = temp->siguiente;
      i++;
   }

   if (orden)
      printf("\n === ordenando descendentemente === ");
   else
      printf("\n === ordenando ascendentemente === ");

   free(array);
}

bool ascendente(int a, int b) { return a > b; }
bool descendente(int a, int b) { return a < b; }