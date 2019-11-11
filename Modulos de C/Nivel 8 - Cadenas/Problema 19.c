// 19. Determinar si una palabra es capicua o no.
// osea que se escribe igual alreves.
// ejemplo: [anitalavalatina , reconocer]
#include<stdio.h>
#include<string.h>

int main()
{
	char palabra[] = "reconocer";
	char palabra2[20];
	
	//Copiamos el contenido de palabra hacia palabra2
	strcpy(palabra2,palabra); 
	
	strrev(palabra2); //Invertimos a palabra2
	
	if(strcmp(palabra, palabra2) == 0)
		puts("Palabra capicua");
	else
		puts("No es capicua");
	
	return 0;
}