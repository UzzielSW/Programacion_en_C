/*	8. Hacer un programa que muestre 3 numeros ordenados desendentemente, 
utilizar un procedimiento para cada operacion.
*/
#include<stdio.h>
void descendente(int a,int b, int c);

int main()
{
	int a,b,c;
	
	printf("Digite 3 numeros: ");
	scanf("%d %d %d",&a,&b,&c);
	
	ascendente(a,b,c);
	
	return 0;
}

void ascendente(int a,int b, int c)
{
	puts("\nOrden Descendente");

	if((a >= b) && (a >= c))
	{
		if(b >= c)
			printf("%d %d %d",a,b,c);
		else
			printf("%d %d %d",a,c,b);
	}
	
	if((b >= a) && (b >= c))
	{
		if(a >= c)
			printf("%d %d %d",b,a,c);
		else
			printf("%d %d %d",b,c,a);
	}

	if((c >= a) && (c >= b))
	{
		if(a >= b)
			printf("%d %d %d",c,a,b);
		else
			printf("%d %d %d",c,b,a);
	}
}