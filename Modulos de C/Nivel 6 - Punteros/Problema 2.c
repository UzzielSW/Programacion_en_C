/*	2. Comprobar si un n�mero es par o impar, y se�alar la posicion de memoria donde
	se est� guardando el n�mero. Con punteros.
*/
#include<stdio.h>

int main()
{
	int numero, *p_numero;
	
	printf("Digite un numero: "); //Pedimos el n�mero al usuario
	scanf("%d",&numero);
	
	p_numero = &numero;  //guardamos la posicion de memoria del n�mero
	
	if((*p_numero % 2) == 0)
	{ //Comprobamos si es par
		printf("El numero %d es par",*p_numero);
		printf("\nPosicion: %X",p_numero); //Imprimimos su posici�n en memoria
	}
	else
	{
		printf("El numero %d es impar",*p_numero);
		printf("\nPosicion: %X",p_numero);	
	}
	return 0;
}