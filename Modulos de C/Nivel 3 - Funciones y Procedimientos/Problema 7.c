/*	7. Hace un programa que muestre 3 números ordenados de ascendentemente, 
utilizar un procedimiento para cada operación.
*/
#include<stdio.h>

int main()
{
	int a,b,c;
	void ascendente(int, int, int);

	printf("Digite 3 numeros: ");
	scanf("%d %d %d",&a,&b,&c);
	
	ascendente(a,b,c);
	
	return 0;
}

void ascendente(int a,int b, int c)
{
	puts("\nOrden Ascendente");

	if((a >= b) && (a >= c))
	{
		if(b >= c)
			printf("%d %d %d",c,b,a);
		else
			printf("%d %d %d",b,c,a);
	}

	if((b >= a) && (b >= c))
	{
		if(a >= c)
			printf("%d %d %d",c,a,b);
		else
			printf("%d %d %d",a,c,b);
	}

	if((c >= a) && (c >= b))
	{
		if(a >= b)
			printf("%d %d %d",b,a,c);
		else
			printf("%d %d %d",a,b,c);
	}
}