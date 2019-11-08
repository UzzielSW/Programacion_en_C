#include<stdio.h>

int main()
{
	char a[5] = {'a','i','o','u','e'};
	int i;
	char band = 'F', elemento;
	
	elemento = 'l'; // elemento a buscar

	i=0;
	while((band == 'F') && (i < 5))
	{
		if(a[i] == elemento)
			band = 'V';
		i++;
	}
	
	if(band == 'F')
		puts("El elemento no existe");
	if(band == 'V')
		printf("El elemento si exite en el array, en la posicion: %d",i-1);
	
	getchar();
	return 0;
}