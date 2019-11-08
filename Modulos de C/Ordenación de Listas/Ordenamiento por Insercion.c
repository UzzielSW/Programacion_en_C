#include<stdio.h>

int main()
{
	int n[5] = {3, 1, 4, 2, 5};
	int i,j,aux;
	
	for(i = 1; i < 5; i++)
	{
        j = i;
        aux = n[i];
        while ((j > 0) && (aux < n[j - 1])) 
        {  // ascendentemente (aux < n[j - 1])
        	// descendentemente (aux > n[j - 1])
           n[j] = n[j - 1];
           j--;
        }
        n[j] = aux;
    }
    
	printf("\n ordenando ascendentemente: ");
	for(i=0; i < 5; i++)
		printf(" %d",n[i]);
		
	getchar();
	return 0;
}