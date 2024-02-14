#include <stdio.h>
#include <stdlib.h>
#define ASCENDENTE 1
#define DESCENDENTE 0

typedef struct Nodo
{
   int valor;
   struct Nodo *siguiente;
   struct Nodo *anterior;
} Nodo;

typedef Nodo *pNodo;
typedef Nodo *Lista;

/* Funciones con listas: */
void InsertarNodo(Lista *l, int v);
int BorrarNodo(Lista *l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

int main()
{
   Lista lista = NULL;
   int opc, dato = 0;
   do
   {
      system("cls");
      puts("\n .:Listas doblemente enlazadas:.\n");
      puts(" 1. Insertar nodo a la lista");
      puts(" 2. Borrar nodo de la lista");
      puts(" 3. Mostrar Lista");
      puts(" 4. Borrar toda la lista");
      puts(" 5. Salir");
      printf(" opcion? ");
      scanf("%i", &opc);

      switch (opc)
      {
      case 1:
         printf("\n ingrese el dato (int): ");
         scanf("%i", &dato);
         InsertarNodo(&lista, dato);
         break;

      case 2:
         if (lista != NULL)
         {
            MostrarLista(lista, ASCENDENTE);
            printf("\n ingrese el dato (int) que desea eliminar: ");
            scanf("%i", &dato);
            dato = BorrarNodo(&lista, dato);
            if (dato != 0)
            {
               puts("\n === Nodo eliminado ===");
               if (lista != NULL)
                  MostrarLista(lista, ASCENDENTE);
            }
            else
               puts("\n == Nodo no se encuentra en la lista ==");
         }
         else
            puts("\n === lista vacia ===");
         break;

      case 3:
         if (lista != NULL)
         {
            printf("\n ingrese [1] ASCENDENTE o [0] DESCENDENTE: ");
            scanf("%i", &dato);
            if (dato != 0)
               MostrarLista(lista, ASCENDENTE);
            else
               MostrarLista(lista, DESCENDENTE);
         }
         else
            puts("\n === lista vacia ===");
         break;

      case 4:
         if (lista != NULL)
            BorrarLista(&lista);
         else
            puts("\n === lista vacia ===");
         break;

      case 5:
         exit(0);
      default:
         puts("\n opcion incorrecta");
      }
      puts("\n");
      system("pause");
   } while (opc != 5);
   return 0;
}

void InsertarNodo(Lista *lista, int v)
{
   pNodo actual;
   pNodo nuevo = malloc(sizeof(Nodo)); /* Crear un nodo nuevo */
   nuevo->valor = v;

   /* Colocamos actual en la primera posicion de la lista */
   actual = *lista;
   if (actual != NULL)
      while (actual->anterior != NULL)
         actual = actual->anterior; // lo movemos hacia el ultimo nodo

   // Si la lista esta vacia o el primer miembro es mayor que el nuevo
   // Aniadimos la lista a continuacion del nuevo nodo
   if (actual == NULL || actual->valor > v)
   {
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if (actual != NULL) // aniadimos el nodo al final
         actual->anterior = nuevo;
      else // si no hay ningun nodo
         *lista = nuevo;
   }
   else
   {
      /* Avanzamos hasta el ultimo elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while (actual->siguiente != NULL && actual->siguiente->valor <= v)
         actual = actual->siguiente;

      /* Insertamos el nuevo nodo despues del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if (nuevo->siguiente != NULL)
         nuevo->siguiente->anterior = nuevo;
   }
}

int BorrarNodo(Lista *lista, int v)
{
   pNodo nodo = *lista;

   /* Buscar el nodo de valor v */
   while (nodo->siguiente != NULL)
   {
      if (nodo->valor < v)
         nodo = nodo->siguiente;
      else
         break;
   }

   /* El valor v no esta en la lista */
   if (nodo == NULL || nodo->valor != v)
      return 0;

   /* Borrar el nodo */
   if (nodo == *lista)
   {
      if (!nodo->anterior && !nodo->siguiente) // si es el unico nodo
         *lista = NULL;
      else if (nodo->siguiente != NULL) // no es el unico nodo
         *lista = nodo->siguiente;
   }

   if (nodo->anterior != NULL) 
      nodo->anterior->siguiente = nodo->siguiente;
   if (nodo->siguiente != NULL) 
      nodo->siguiente->anterior = nodo->anterior;

   free(nodo);
   return 1;
}

void BorrarLista(Lista *lista)
{
   pNodo nodo, actual = *lista;

   while (actual->anterior != NULL)
      actual = actual->anterior;

   while (actual != NULL)
   {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }

   *lista = NULL;
   puts("\n === Lista vaciada ===");
}

void MostrarLista(Lista lista, int orden)
{
   pNodo nodo = lista;
   if (lista == NULL)
      return; // de emergencia... el tratar de leer y que no aya nodos da error

   printf("\n");

   if (orden == ASCENDENTE)
   {
      while (nodo->anterior != NULL)
         nodo = nodo->anterior;

      while (nodo != NULL)
      {
         if (nodo->siguiente != NULL && nodo->anterior != NULL)
            printf(" %i ->", nodo->valor);
         else if (nodo->anterior == NULL && nodo->siguiente != NULL)
            printf(" [ %i ->", nodo->valor);
         else if (nodo->anterior == NULL && nodo->siguiente == NULL)
            printf(" [ %i ]", nodo->valor);
         else if (nodo->siguiente == NULL && nodo->anterior != NULL)
            printf(" %i ]", nodo->valor);

         nodo = nodo->siguiente;
      }
   }
   else
   {
      while (nodo->siguiente != NULL)
         nodo = nodo->siguiente;

      while (nodo != NULL)
      { // la forma de imrpimir es diferente por el orden en que se imprimen
         if (nodo->siguiente != NULL && nodo->anterior != NULL)
            printf(" %i ->", nodo->valor);
         else if (nodo->anterior == NULL && nodo->siguiente != NULL)
            printf(" %i ]", nodo->valor);
         else if (nodo->anterior == NULL && nodo->siguiente == NULL)
            printf(" [ %i ]", nodo->valor);
         else if (nodo->siguiente == NULL && nodo->anterior != NULL)
            printf(" [ %i ->", nodo->valor);

         nodo = nodo->anterior;
      }
   }

   printf("\n");
}