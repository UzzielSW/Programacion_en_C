//	1. Serie Fibonacci con Recursividad
//	ejemplo: 1.1.2.3.5.8...
#include<stdio.h>

int main()
{
	int numero,i;
	int fibonacci(int n);

	printf("Digite el numero de terminos: ");
	scanf("%d",&numero);
	
	for(i=1; i <= numero; i++){
		printf("%d , ",fibonacci(i));
	}
	
	return 0;
}

/*
1.1.2.3.5..

fibonacci(1) = 1
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
*/

int fibonacci(int n)
{
	if((n == 0) || (n == 1))
		return n;
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}