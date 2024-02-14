/*2. Digite un numero, si el numero supera a 10, multiplique los 10 primeros numeros, 
sino, sumelos (Propuesto)*/

#include<stdio.h>

int main()
{
	int numero,suma, mult,i;
	
	printf("Digite un numero: ");
	scanf("%d",&numero);
		
	i = 0;
	if(numero > 10)
	{
		while(++i <= 10)	mult *= i;
		printf("\n La multiplicacion es: %d",mult);
	}
	else
	{
		while(++i <= 10)	suma += i;
		printf("\n La suma es: %d",suma);
	}
	
	return 0;
}
