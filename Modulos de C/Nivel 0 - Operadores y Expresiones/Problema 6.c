// 6. Calcule la media aritmetica de 3 numeros cualesquiera (Propuesto)
#include<stdio.h>

int main()
{
	int n1,n2,n3;
	float media_aritmetica = 0;

	printf("Digite 3 numeros: ");
	scanf("%d %d %d",&n1, &n2, &n3);
	
	media_aritmetica = (n1+n2+n3)/3;
	
	printf("La media aritmetica es: %.2f",media_aritmetica);
	
	return 0;
}