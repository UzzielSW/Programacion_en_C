#include<stdio.h>

int main()
{
	int array[5] = {4, 3, 5, 1, 2};
	int i,j,aux;
	
	for(i=0; i < 5 ; i++)
	{
		for(j=0; j < (5-1); j++)
		{
			if(array[j] > array[j+1])
			{
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	
	for(i=0; i < 5; i++)
		printf("%d ",array[i]);
	
	getchar();
	return 0;
}