/*
	3 Visualizar la tarifa de la luz segun el gasto de corriente electrica. 
	Para un gasto menor de 1.000Kw x h
	la tarifa es 1.2, entre 1.OOO y 1.850Kw x h es 1.0 y mayor de 1.85OKw x h 0.9.
*/

#include <stdio.h>

int main()
{
	float gasto, tasa=0;
	
	printf("Digite el total de gasto: ");
	scanf("%f",&gasto);
	
	if(0 < gasto && gasto < 1000) tasa = 1.2;
	else if(1000 < gasto && gasto < 1850) tasa = 1;
	else if(1850 < gasto) tasa = 0.9;
	else puts("\n gasto invalido");
	
	printf("El total de tasa a pagar es: %.1f",tasa);	
	
	return 0;
}