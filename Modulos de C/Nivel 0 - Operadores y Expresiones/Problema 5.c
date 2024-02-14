//	5. Hacer un Programa que calcule areas de trapecios
#include<stdio.h>

int main()
{
	int base_M, base_m, altura;
	float area;
	
	printf("Digite la base mayor: ");
	scanf("%d",&base_M);
	printf("Digite la base menor: ");
	scanf("%d",&base_m);
	printf("Digite la altura: ");
	scanf("%d",&altura);
	
	area = ((base_M + base_m) * altura)/2;
	
	printf("\nEl area es: %f",area);
	
	return 0;
}