// 3. Multiplos de 3 desde 1 hasta n
#include<stdio.h>

int main()
{
	int n, i; 
	
	printf("Digite el total de elementos: ");
	scanf("%d",&n);
	
	i = 0;
	while(++i <= n)
		if((i % 3) == 0)	
			printf("%d\n",i);

	return 0;
}