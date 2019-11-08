#include<stdio.h>

int main()
{
	int a[5] = {3, 1, 4, 2, 5};
	int i,j,min,temp;
	
	for(i=0; i < (5-1); i++)
	{
		min = i;
		for(j = (i+1); j < 5; j++)
		{
			if(a[j] < a[min]) // a[j] < a[min] ascendente // // a[j] > a[min] descendente //
				min = j;
		}

		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	
	for(i=0; i < 5 ; i++)	
		printf("%d ",a[i]);
	
	getchar();
	return 0;
}