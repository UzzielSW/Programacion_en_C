#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define True 1
#define False 0
#define length(x) (sizeof(x) / sizeof(x[0]))
#define mayor(a, b) ((a > b) ? a : b)

typedef struct Nodo
{
   int info;
   struct Nodo *izq;
   struct Nodo *der;
} Nodo;

typedef Nodo arbol;

Nodo *crearNodo(int id);
void insertar(Nodo **raiz, int valor);
void inOrden(arbol *);
void preOrden(arbol *);
void postOrden(arbol *);
void imp_arbol(arbol *, int, int, int, int);
void gotoxy(int, int);
void imprimirArbolVertical(arbol *, int);

int altura(arbol *a);
void copiar(arbol *a, arbol **acop);
void espejo(arbol *a, arbol **aespejo);
int iguales(arbol *a, arbol *b);
void contarhojas(arbol *a, int *cont);
void nodosdeniveldado(arbol *a, int n);

int main()
{
   int valores[] = {100, 50, 150, 40, 70, 60, 80, 90, 20, 30, 45, 55, 65, 75, 10, 170, 140, 130, 120, 135, 180, 160, 155, 42, 48, 145, 142, 146, 190, 175, 165};
   int opc, temp;
   int x, y; // para gotoxy
   arbol *Q, *raiz = NULL, *T = NULL;

   do
   {
      system("cls");
      printf("\t\tARBOL BINARIO DE BUSQUEDA\n\n");
      printf("\t1. Ingresar Datos\n");
      printf("\t2. Mostrar Arbol\n");
      printf("\t3. Recorridos de Arbol (inOrden, preOrden, postOrden)\n");
      printf("\t4. Realizar una copia del arbol y visualizarlo\n");
      printf("\t5. Altura del Arbol, Cantidad de hojas\n");
      printf("\t6. Comparar dos arboles\n");
      printf("\t7. Determinar el arbol espejo\n");
      printf("\t8. Visualizar los nodos de un nivel del arbol (Max: %d)\n", altura(raiz) - 1);
      printf("\t9. Salir\n");
      printf("\n\tDigite su opcion ---> ");
      scanf("%d", &opc);

      if (opc == 0)
      {
         for (int i = 0; i < length(valores); i++)
         {
            temp = valores[i];
            insertar(&raiz, temp);
         }
      }

      else if (opc == 1)
      {
         do
         {
            printf("ingrese valor (0:Fin)---> ");
            if (scanf("%d", &opc) && opc != 0)
               insertar(&raiz, opc);
         } while (opc != 0);
      }

      else if (opc == 2)
      {
         x = 12 * altura(raiz);
         y = 15;
         printf("\t\n/!\\ La visualizacion del arbol con gotoxy solo funciona en Windows/!\\");

         imp_arbol(raiz, x, y, altura(raiz) - 1, altura(raiz) - 2);
         // printHorizontalTree(raiz, 10);
      }

      else if (opc == 3)
      {
         printf("\n PreOrden: ");
         preOrden(raiz);
         printf("\n InOrden: ");
         inOrden(raiz);
         printf("\n PostOrden: ");
         postOrden(raiz);
      }

      if (opc == 4)
      {
         system("cls");
         x = 15 * altura(raiz);
         y = 5;
         printf("\n/!\\ La visualizacion del arbol con gotoxy solo funciona en Windows\n");
         printf("\nLa visualizacion del arbol original: \n");
         imp_arbol(raiz, x, y, altura(raiz) - 1, altura(raiz) - 2);

         copiar(raiz, &Q);

         y += 12;
         printf("\n\nLa visualizacion del arbol copiado: \n");
         imp_arbol(Q, x, y, altura(raiz) - 1, altura(raiz) - 2);
      }

      else if (opc == 5)
      {
         printf("\nAltura del arbol: %d", altura(raiz));
         temp = 0;
         contarhojas(raiz, &temp);
         printf("\nCantidad de hojas del arbol: %d", temp);
      }

      else if (opc == 6)
      {
         printf("Comparar igualdad de arboles: ");
         printf("\n desea comparar igualdad de arboles A y Q? (1: si, 2: no, ingresar otro arbol)---> ");

         scanf("%d", &temp);
         if (temp == 1)
         {
            if (iguales(raiz, Q))
               printf("\nLos arboles A y Q son iguales");
            else
               printf("\nLos arboles A y Q no son iguales");
         }
         else
         {
            do
            {
               printf("ingrese valor (0:Fin)---> ");
               if (scanf("%d", &opc) && opc != 0)
                  insertar(&T, opc);
            } while (opc != 0);

            if (iguales(raiz, T))
               printf("\nLos arboles A y C son iguales");
            else
               printf("\nLos arboles A y C no son iguales");
         }
      }

      else if (opc == 7)
      {
         system("cls");
         x = 15 * altura(raiz);
         y = 5;
         printf("\n/!\\ La visualizacion del arbol con gotoxy solo funciona en Windows\n");
         printf("\nLa visualizacion del arbol original: \n");
         imp_arbol(raiz, x, y, altura(raiz) - 1, altura(raiz) - 2);

         espejo(raiz, &Q);

         y += 12;
         printf("\nEspejo del arbol: ");
         imp_arbol(Q, x, y, altura(raiz) - 1, altura(raiz) - 2);
      }

      else if (opc == 8)
      {
         if (altura(raiz) != 0)
         {
            printf("\nIngrese el nivel: ");
            scanf("%d", &temp);
            if (altura(raiz) - 1 >= temp)
            {
               printf("\nNodos del nivel %d: ", temp);
               nodosdeniveldado(raiz, temp);
            }
            else
               printf("\nEse nivel no existe");
         }
         else
            printf("\nArbol vacio");
      }

      getch();
   } while (opc != 9);

   return 0;
}

Nodo *crearNodo(int valor)
{
   Nodo *t = (Nodo *)malloc(sizeof(Nodo));
   t->info = valor;
   t->der = NULL;
   t->izq = NULL;
   return (t);
}

void insertar(Nodo **raiz, int info)
{
   if (!(*raiz))
      *raiz = crearNodo(info);
   else if (info < (*raiz)->info)
      insertar(&((*raiz)->izq), info);
   else
      insertar(&((*raiz)->der), info);
}

// dado que no puedo vizualizar el arbol a gran escala por la pantalla, es probable que al usar un arbol muy grande se superponga tambien o se
// rompa en algun punto. en ese caso habria variar los valores estaticos que use: 2, 4. y habria que adaptarlo al tamaño del arbol.
// En este caso use la altura del arbol para determinar aproximadamente la separacion que deberia tener cada nodo en todas las ramas.
// para un arbol de altura 5 y full me funciono bien.
void imp_arbol(arbol *ptrArbol, int x, int y, int i, int j)
{
   if (ptrArbol != NULL)
   {
      gotoxy(x, y);

      printf("%d", ptrArbol->info);
      if (i - j == 1)
         x -= (j != 0) ? 2 * i * j : 2 * 1;
      else
         x -= (j != 0) ? i * j : 2;

      y = y + 2;
      imp_arbol(ptrArbol->izq, x, y, i, j - 1);

      if (i - j == 1)
         x += (j != 0) ? 4 * i * j : 4 * 1;
      else
         x += (j != 0) ? 2 * i * j : 4 * 1;

      imp_arbol(ptrArbol->der, x, y, i, j - 1);
      y = y - 2;

      // de esta forma funciona pero se superponen los elementos del arbol
      // x -= 6;
      // y += 3;
      // imp_arbol(ptrArbol->izq, x, y, i, j - 1);
      // x += 12;
      // imp_arbol(ptrArbol->der, x, y, i, j - 1);
      // y -= 3;
   }
}

// RECORRIDO DE ARBOLES BINARIOS

/*	INORDEN(izquierdo, raiz, derecho).
Para recorrer un arbol binario hay que realizar las siguientes operaciones recursivamente en cada Nodo:
1. Atraviese el sub-arbol izquierdo
2. Visite la raiz
3. Atraviese el sub-arbol derecho
*/
void inOrden(arbol *ptrArbol)
{
   if (ptrArbol != NULL)
   {
      inOrden(ptrArbol->izq);
      printf("%d ", ptrArbol->info);
      inOrden(ptrArbol->der);
   }
}

/*	PREORDEN (raiz, izquierdo, derecho).
Para recorrer un arbol binario hay que realizar las siguientes operaciones recursivamente en cada Nodo, comenzando con el Nodo de raiz:
1. Visite la raiz
2. Atraviese el sub-arbol izquierdo
3. Atraviese el sub-arbol derecho
*/
void preOrden(arbol *ptrArbol)
{
   if (ptrArbol != NULL)
   {
      printf("%d ", ptrArbol->info);
      preOrden(ptrArbol->izq);
      preOrden(ptrArbol->der);
   }
}
/*	POSORDEN (izquierdo, derecho, raiz).
Para recorrer un arbol binario hay que realizar las siguientes operaciones en cada Nodo:
1. Atraviese el sub-arbol izquierdo
2. Atraviese el sub-arbol derecho
3. Visite la raiz
*/
void postOrden(arbol *ptrArbol)
{
   if (ptrArbol != NULL)
   {
      preOrden(ptrArbol->izq);
      preOrden(ptrArbol->der);
      printf("%d ", ptrArbol->info);
   }
}

void gotoxy(int x, int y)
{
   HANDLE hcon;
   hcon = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD dwPos;
   dwPos.X = x;
   dwPos.Y = y;
   SetConsoleCursorPosition(hcon, dwPos);
}

// ---------------------------------------ALGORITMOS DE PROBLEMAS-------------------------------------------

/*
   Escriba una función que reciba como parámetro un árbol A y devuelva una copia de él.
   Análisis
   Para resolver el ejercicio basta con hacer un recorrido del árbol en preorden haciendo una copia de él. El recorrido se implementará
   de forma recursiva, siguiendo el algoritmo explicado en la parte teórica. A la salida de la recursividad se van construyendo
   los nodos del nuevo árbol y asignándoles sus valores.
*/
void copiar(arbol *a, arbol **acop)
{
   if (a == NULL)
      *acop = NULL;
   else
   {
      *acop = (arbol *)malloc(sizeof(arbol));
      (*acop)->info = a->info;
      (*acop)->izq = a->izq;
      (*acop)->der = a->der;
   }
}

/*
Escribir una función que reciba como parámetro un árbol A y devuelva como resultado otro árbol
A(espejo) que es el árbol simétrico de A.
Análisis
Para resolver el ejercicio basta con hacer un recorrido del árbol en preorden haciendo una copia de él,
pero intercambiando entre sí los hijos.

               20                                20
          /        \								   /		 \
      11	            25							25               11
     /	   \		  /		\					 /		\    	  /      \
   6		15		22		  32			  32          22    15         6
     \						/                    \                       /
      8				  30                       30                  8

*/
void espejo(arbol *a, arbol **aespejo)
{
   if (a == NULL)
      *aespejo = NULL;
   else
   {
      *aespejo = (arbol *)malloc(sizeof(arbol));
      (*aespejo)->info = a->info;
      (*aespejo)->der = a->izq;
      (*aespejo)->izq = a->der;
   }
}

/*
   Diseñar una función que permita comprobar si son iguales dos árboles; es decir,
   tengan la misma estructura de nodos y éstos el mismo contenido.

   Análisis
   Se trata de una función recursiva que compara nodo a nodo la información almacenada en ambos árboles.
   Las condiciones de salida del proceso recursivo serán que:
   • se termine de recorrer uno de los dos árboles.
   • terminen de recorrerse ambos.
   • se encuentre diferente información en los nodos comparados.
   Si los árboles terminaron de recorrerse simultáneamente es que ambos tienen el mismo número de nodos
   y nunca ha sido diferente la información comparada; por tanto, la función devolverá verdad,
   en cualquier otro caso la función devolverá falso.
*/
int iguales(arbol *a, arbol *b)
{
   if (a == NULL)
      if (b == NULL)
         return True;
      else
         return False;
   else if (b == NULL)
      return False;
   else if (a->info != b->info)
      return False;
   else
      return iguales(a->izq, b->izq) && iguales(a->der, b->der);
}

/*
Escribir una función que permita contar las hojas de un árbol.
Análisis
Se debe recorrer el árbol, contando, únicamente, los nodos que no tienen hijos.
En la llamada inicial, el parámetro cont debe valer 0. El tipo árbol representa el
nodo del árbol (consultar problema ver si dos arboles son iguales)
*/
void contarhojas(arbol *a, int *cont)
{
   if (a != NULL)
      if ((a->izq == NULL) && (a->der == NULL))
         *cont += 1;
      else
      {
         contarhojas(a->izq, cont);
         contarhojas(a->der, cont);
      }
}

/*
Diseñar una función que permita determinar la altura de un árbol.
Análisis
Profundidad o altura de un árbol es el máximo de la altura de los nodos del árbol. Esta profundidad se puede obtener utilizando
una función que recorra el árbol y en cada nodo seleccione el subárbol de mayor altura y le sume a ésta una nueva
unidad.
*/
int altura(arbol *a)
{
   if (a != NULL)
      return 1 + mayor(altura(a->izq), altura(a->der));
   else
      return 0;
}

/*
Escribir un una función que muestre todos los nodos de un árbol que se encuentran en un nivel dado.
Análisis
Si se considera que la raíz se encuentra en el nivel cero, de un árbol habrá que escribir el nodo cuando el parámetro que indique
el nivel sea cero siempre y cuando en cada llamada recursiva disminuya en una unidad el parámetro. La declaración de
*/
void nodosdeniveldado(arbol *a, int n)
{
   if (n < 0)
      printf("error");
   else if (n == 0)
   {
      if (a != NULL)
         printf(" %d ", a->info);
   }
   else if (a != NULL)
   {
      nodosdeniveldado(a->izq, n - 1);
      nodosdeniveldado(a->der, n - 1);
   }
}

void imprimirArbolVertical(arbol *root, int space)
{
   // Caso base
   if (root == NULL)
   {
      return;
   }

   // Aumenta el espacio entre niveles
   space += 10;

   // Procesa el subárbol derecho primero
   imprimirArbolVertical(root->der, space);

   // Imprime el nodo actual después del espacio
   printf("\n");
   for (int i = 10; i < space; i++)
   {
      printf(" ");
   }
   printf("%d\n", root->info);

   // Procesa el subárbol izquierdo
   imprimirArbolVertical(root->izq, space);
}