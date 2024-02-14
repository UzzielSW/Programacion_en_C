/*	2. Comprobar si un numero es par o impar, y apuntar a la posicion de memoria donde
	se esta guardando el numero. Con punteros.
*/
#include<stdio.h>

int main()
{
	int numero, *p_numero;
	
	printf("Digite un numero: "); //Pedimos el numero al usuario
	scanf("%d",&numero);
	
	p_numero = &numero;  //guardamos la posicion de memoria del numero
	
	if((*p_numero % 2) == 0)
	{ //Comprobamos si es par
		printf("El numero %d es par",*p_numero);
		printf("\nPosicion: %X",p_numero); //Imprimimos su posicion en memoria
	}
	else
	{
		printf("El numero %d es impar",*p_numero);
		printf("\nPosicion: %X",p_numero);	
	}
	return 0;
}