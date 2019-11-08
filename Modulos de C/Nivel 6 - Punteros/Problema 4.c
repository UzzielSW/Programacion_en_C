/*
	4. Determinar si un numero es primo o no; con puteros y además indicar en que 
	posicion de memoria se guardo el número.
*/ 
#include<stdio.h>

int main()
{
	int numero, i, cont = 0;
	int *p_numero;
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
	
	p_numero = &numero; //Guardamos en p_numero la posicion de memoria de numero
	
	for(i=1; i <= *p_numero; i++)//Utilizamos un bucle para saber si es primo
	{ 
		if((*p_numero % i)  == 0)
			cont++; 
	}
	
	//Comprobamos si es primo o no
	if(cont > 2)
	{ 
		printf("\nEl numero %d NO es primo",*p_numero);
		printf("\nPosicion: %X",p_numero);
	}
	else
	{
		printf("\nEl numero %d SI es primo",*p_numero);
		printf("\nPosicion: %X",p_numero);
	}

	return 0;
}