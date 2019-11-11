#include <stdio.h>
#include <string.h>

int main()
{ 
    char text[5][10] = {"DONANTE", "CASA", "HOY", "MARIA", "JUAN"}; 
    char cop[10];
    int i,j,k; 

    // 	 ordenando cadenas
    for(i=0; i < 5; i++)
    {
        k = i;
        strcpy(cop, text[i]);
        for(j = (i+1); j < 5; j++)
        {
            if(strcmp(text[j], cop) < 0)
            {
                k = j;
                strcpy(cop,text[j]);
            }
        }

        strcpy(text[k], text[i]);
        strcpy(text[i], cop);
    }
    
	puts("\n imprimiendo cadenas en orden alfabetico:");
	for(i=0; i < 5; i++)
        printf(" -%s \n",text[i]);
  
    getchar();
 return 0;   
}