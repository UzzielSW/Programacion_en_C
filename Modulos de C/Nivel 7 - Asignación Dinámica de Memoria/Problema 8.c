/*
	8. Reservar memoria para un arreglo de 5 numeros, rellenarlo con numeros que digite
	el usuario, luego utilizar realloc para ampliar ese arreglo a 10 numeros y agregar
	5 numeros mas, por ultimo imprimir el arreglo resultante de 10 numeros.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p_array, *p_arrayResultante;
	int i;

	p_array = malloc(5 * sizeof(int));

	//Pidiendo los primeros 5 numeros
	for(i=0; i < 5 ; i++)
	{
		printf("%d. Digite un numero: ",(i+1));
		scanf("%d",&p_array[i]);
	}
	
	//Ampliando el arreglo a 10 numeros 
	p_arrayResultante = realloc(p_array, 10 * sizeof(int));
	printf("\n\n");
	
	//Pidiendo los 5 numeros siguientes
	for(i=5; i < 10 ; i++)
	{
		printf("%d. Digite un numero: ",(i+1));
		scanf("%d",&p_arrayResultante[i]);
	}
	printf("\n\n\n");

	//Imprimiendo el arreglo resultante de 10 numeros
	for(i=0; i < 10 ; i++)
		printf("%d.\n",p_arrayResultante[i]);
	
	free(p_arrayResultante);
	
	return 0;
}