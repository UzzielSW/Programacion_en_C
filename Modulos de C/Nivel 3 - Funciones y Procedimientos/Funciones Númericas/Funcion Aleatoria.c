/* Funcion Aleatoria: 

	srand(time(NULL));
	variable  = limite_inferior + rand() % ((limite_superior + 1 ) - limite_inferior);
*/
#include<stdio.h>
#include<time.h>

int main()
{
	void funcion_aleatoria();
	
	funcion_aleatoria();
	
	return 0;
}

void funcion_aleatoria()
{
	int numero, i, li, ls;
	
	srand(time(NULL));
	
	printf("Digite el limite inferior: ");
	scanf("%d",&li);
	
	printf("Digite el limite superior: ");
	scanf("%d",&ls);
	
	for(i=1; i <= 10; i++)
	{
		numero = li + rand() % ((ls + 1) - li);
		printf("%d.\n",numero);
	}
}