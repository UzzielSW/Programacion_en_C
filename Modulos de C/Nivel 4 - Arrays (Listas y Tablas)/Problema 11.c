/*
	11. Hacer una lista de 10 numeros, luego pedirle al usuario que 
	digite un numero, y atraves de una busqueda secuencial determinar si 
	el numero existe en la lista o no, y ademas indicar en que posicion se encuentra.
*/
#include<stdio.h>

int main()
{
	int arr[10] = {4, 6, 3, 10, 15, 23, 56, 78, 9, 54};
	int i, numero;
	char band = 'F';
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
	
	i=0;
	while((band == 'F') && (i < 10))
	{
		if(arr[i] == numero)
			band = 'V';
		i++;
	}
	
	if(band == 'F')
		printf("El elemento no existe");
	
	else if(band == 'V')
		printf("El elemento si existe, en la pos: %d",(i-1));
	
	getchar();
	return 0;
}