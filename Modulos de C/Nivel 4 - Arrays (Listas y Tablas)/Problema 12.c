/*
	12. Hacer un array pidiendo al usuario el numero de elementos, y
	rellenar el array con numeros digitados por el teclado, luego pedir
	al usuario un numero, y hacer una busqueda secuencial para indicar 
	si ese elemento existe o no, tambien entregar posicion.
*/
#include<stdio.h>

int main()
{
	int arr[50], i, elementos, numero;
	char band = 'F';
	
	printf("Digite el total de elementos del array: ");
	scanf("%d",&elementos);
	puts("\n");

	for(i=0; i < elementos; i++)
	{
		printf("Digite un numero del vector[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\n Ahora digite el numero a buscar: ");
	scanf("%d",&numero);

	//Comenzando busqueda secuencial
	i=0;
	while((band == 'F') && (i < elementos))
	{
		if(arr[i] == numero) band = 'V';
		i++;
	}
	
	if(band == 'F')
		printf("\nEl numero no existe");
	
	else if(band == 'V')
		printf("\nEl numero existe, y esta en la posicion: %d",(i-1));
	
	getchar();
	return 0;
}