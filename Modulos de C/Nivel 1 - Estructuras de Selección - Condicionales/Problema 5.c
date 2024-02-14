// 5. Calcular el mayor de dos numeros leidos del teclado y visualizarlo en pantalla.
#include<stdio.h>

int main()
{
	int n1, n2;
	
	printf("Digite 2 numeros: ");
	scanf("%d %d",&n1,&n2);
	
	printf("\nel mayor es: %d",(n1 > n2)? n1 : n2);

	return 0;
}