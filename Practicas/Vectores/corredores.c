/*
    programa de competencia de carreras
        - 10 corredores
        - capturar el pais del que proviene cada corredor.
        - ordenar la lista de paises alfabeticamente

    luego generar los tiempos de recorrido durante la carrera de forma aleatoria
    luego ordenar la lista de los corredores de menos a mayor segun el tiempo de llegada.
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int i,j, num, y=0, tempo;
    char temp[20];
    int Posiciones[10], m[10];
    char Corredores[10][20];

    puts("\n Introducir nombre de los 10 paices:");

    for (i=0; i < 10; i++)
    {
        printf("%d: ",(i+1))
    	fflush(stdin);
        scanf("%[^\n]",&Corredores[i]);
    }
    
    system("cls");

    for (i = 0; i < 10; i++ )
    {
        for (j = (i + 1); j < 10; j++ )
        {
            //funcion strcoll compara las cadenas 
            // retorna un numero mayor , igual o menor q cero
            if ((strcoll(Corredores[i], Corredores[j])) > 0 ) // text1 > text2
            {  
                strcpy (temp, Corredores[i]);
                strcpy (Corredores[i], Corredores[j]);
                strcpy (Corredores[j], temp);
            }
        }
    }

    puts("\n Corredores por orden Alfabetico: \n");
    for (i=0; i < 10; i++) printf(" -%s \n",Corredores[i]);

    for (i=0; i < 10; i++) Posiciones[i] = 0; //incializando 
    
    srand(time(NULL));
    do{
        num = rand() % 10;
        Posiciones[num] += 10;
    }while(Posiciones[num] != 100);


    for(i=0; i < 10; i++)
    {
        for (j=(i+1); j < 10; j++)
        {
            if(Posiciones[j] > Posiciones[i])
            {
	            tempo = Posiciones[j];
                Posiciones[j] = Posiciones[i];
                Posiciones[i] = tempo;

                strcpy (temp, Corredores[i]);
                strcpy (Corredores[i], Corredores[j]);
                strcpy (Corredores[j], temp);
            }
        }
    }

    puts("\n Ganadores: ");
    for (i=0; i < 3; i++)
	   printf(" -%s con: %d metros \n", Corredores[i], Posiciones[i]);

	system("pause");
    return 0;
}