/*
	4. Hacer un programa que pida por pantalla un numero del 1 al 10 y mediante un 
	procedimiento muestre por pantalla el numero escrito en letras.
*/

#include<stdio.h>
void comprobar(int n);

int main()
{
	int numero;
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
	
	while(numero < 1 || numero > 10)
	{
		printf("Digite un numero: ");
		scanf("%d",&numero);
	}
	
	comprobar(numero);
	
	return 0;
}

void comprobar(int n)
{
	switch(n)
	{
		case 1: puts("Uno");break;
		case 2: puts("Dos");break;
		case 3: puts("Tres");break;
		case 4: puts("Cuatro");break;
		case 5: puts("Cinco");break;
		case 6: puts("Seis");break;
		case 7: puts("Siete");break;
		case 8: puts("Ocho");break;
		case 9: puts("Nueve");break;
		case 10: puts("Diez");break;
	}
}