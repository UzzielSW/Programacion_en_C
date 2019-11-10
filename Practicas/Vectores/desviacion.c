// calcular la desviacion de 50 numeros entre 10-50
#include <stdio.h>
#include <time.h>
#define li 10
#define ls 50

int main()
{
	int numeros[50], desvia[50];
	int cant=0, promedio=0, i, sum=0;

	srand(time(NULL));
	for(i=0; i<50; i++) numeros[i] = li + rand() % ((ls+1) - li);
	for(i=0; i<50; i++) sum += numeros[i];
	
	promedio = sum / 50;

	for(i=0; i < 50 ; i++)	
		if(numeros[i] > promedio) 
			cant++;
	
	for(i=0; i < 50; i++) 
		desvia[i] = numeros[i] - promedio;
	
	printf("\n promedio: %d", promedio);
	printf("\n cantidad de numeros mayores a la media: %d",cant);
	printf("\n desviacion de todos los numeros respecto a la media:\n");

	for(i=0; i < 50; i++)
	{
		if(desvia[i] > 0) printf("  %d\n", desvia[i]);
		else printf(" %d\n",desvia[i]); 
	}
	
	getchar();
	return 0;
}