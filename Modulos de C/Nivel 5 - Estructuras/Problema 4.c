/*
	4. Hacer un arreglo de estructura llamada atleta para N atletas que contenga 
	los siguientes miembros: nombre, pais, numero_medallas. y devuelva los datos
	(nombre, pais) del atleta que ha ganado el mayor numero de medallas.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
	char nombre[20];
	char pais[20];
	int numero_medallas;
}Atleta;

int main()
{
	int i, n, mayor = 0, pos;
	Atleta atletas[MAX];

	printf("Digite el numero de atletas: ");
	scanf("%d",&n);

	if(n > MAX) exit(0);
	
	for(i=0; i < n ; i++)
	{
		fflush(stdin);
		printf("%d. Digite su nombre: ",i+1);
		gets(atletas[i].nombre);
		fflush(stdin);

		printf("%d. Digite su pais: ",i+1);
		gets(atletas[i].pais);

		printf("%d. Digite el numero de medallas: ",i+1);
		scanf("%d",&atletas[i].numero_medallas);
		printf("\n");
	}
	
	for(i=0; i < n; i++)
	{
		if(atletas[i].numero_medallas > mayor)
		{
			mayor = atletas[i].numero_medallas;
			pos = i;
		}
	}
	
	printf("\n--El atleta con mas medallas es: --\n");
	printf("\nNombre: %s",atletas[pos].nombre);
	printf("\nPais: %s\n\n",atletas[pos].pais);
	
	system("pause");
	return 0;
}