#include <stdio.h>
#include <string.h>

int main ()
{
	const char cadena1[] = "Programacion C", cadena2[] = "Lenguaje";
	char cop1[15], cop2[15];
	void copia(const char *,char *);
	
	printf("\n cadena de texto (copia 1): ");
	copia(cadena1, cop1);
	printf("\n cadena de texto (copia 2): ");
	copia(cadena2, cop2);
	
	getchar();
return 0;
} 
	
void copia(const char *cadena, char *cop)
{
	strcpy(cop, cadena);
	printf("%s\n",cop);
}	