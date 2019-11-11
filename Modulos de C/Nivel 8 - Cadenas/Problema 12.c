/*
    12. Pedir n palabras al usuario y posteriormente ordenarlas alfabeticamente.
    Utilizar metodo de ordenamiento (Burbuja, insercion, seleccion)
*/
#include<stdio.h>
#include<string.h> // permite strcmp y strcpy.

int main()
{
    char nombre[10][20];
    char aux[20];//tiene que ser de igual o mayor tamaño que la segunda componente
    //de nombre porque aquí copiaremos esa cadena.
    int i,j,k;
    int l=0;
    puts("Para terminar escriba (*)");
    
    do
    {
        printf("Introduce un nombre: ");
        gets(nombre[l]);//lee cadenas y las almacena.
        l++;
        if(l > 9) break; //max de palabras 10
    }while (strcmp(nombre[l-1],"*") != 0);//permite comparar cadenas.

    l--;
    // ORDENAR CADENAS
    for(i=0; i < l; i++)
    {
        k = i;
        strcpy(aux, nombre[i]);
        for(j=(i+1); j < l; j++)
        {
            if(strcmp(nombre[j], aux) < 0)
            {
                k = j;
                strcpy(aux, nombre[j]);
               //permite hacer una copia auxiliar de la cadena nombre[j];
            }
        }

        strcpy(nombre[k],nombre[i]);
        strcpy(nombre[i],aux);
    }

    for(i=0; i < l; i++)
        printf("%s\n",nombre[i]);

  return 0;
}