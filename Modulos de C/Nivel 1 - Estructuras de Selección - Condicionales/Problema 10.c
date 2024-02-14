/*
	10.Una distribuidora de motocicletas tiene una promocion de fin de year que consiste en lo siguiente. Las motos marca Honda tienen un descuento del 5%, 
	las marcas Yamaha del 8% y las Suzuki del 10%, las otras marcas 2%
*/
#include<stdio.h>

int main()
{
	char marca[20];
	float precio,descuento,precioFinal=0;
	
	printf("Digite la marca de su moto: ");
	gets(marca);
	printf("Digite el precio de la moto: ");
	scanf("%f",&precio);
	
	if(strcmp(marca,"honda") == 0) //igual a honda
	{
		descuento = precio * 0.05;
		precioFinal = precio - descuento;
	}
	else if(strcmp(marca,"yamaha") == 0) //igual a yamaha
	{
		descuento = precio*0.08;
		precioFinal = precio - descuento;
	}
	else if(strcmp(marca,"suzuki") == 0) //igual a susuki
	{
		descuento = precio*0.1;
		precioFinal = precio-descuento;
	}
	else //cualquier otro
	{
		descuento = precio * 0.02;
		precioFinal = precio - descuento;
	}
		
	printf("El precio final es: %f",precioFinal);

	return 0;
}