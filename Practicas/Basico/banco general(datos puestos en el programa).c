/*
 - banco general tiene 5 sucursales con 4 carteras de prestamos(personales, autos, hipotecas, inversiones).
 - cargar la matriz con los datos  de las 5 sucursales.
 - calcular las siguientes opciones:
	 1- totales por sucursales de las cuatro carteras
	 2- la cartera de mayor numero
	 3- la sucursal de menor efectivo
	 4- los totales de las 5 sucursales

matriz:

	 carteras  | suc1| suc2| suc3| suc4| suc5|total´s cart|
	personales | 100 | 200 | 300 | 300 | 200 |    1,100   |
	autos      | 129 | 239 | 599 | 708 | 399 |    2,074   |
	hipotecas  | 390 | 500 | 399 | 389 | 179 |    1,857   |
	inversiones| 120 | 599 | 688 | 700 | 800 |    2,907   |
	totales suc| 739 |1,538|1,986|2,097|1,578|    7,938   |
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int i, k;

int main()
{
	// declaracion de variables
	int matriz[4][5] = {{100, 200, 300, 300, 200},
						{129, 239, 599, 708, 399},
						{390, 500, 399, 389, 179},
						{120, 599, 688, 700, 800}}; // cargando matriz manuelmente

	// declaracion de funciones
	int case1(int[][5]);
	void case2(int[][5]);
	void case3(int[][5]);

	printf("\nBIENVENIDO USUARIO AL BANCO GENERAL DE LA PROVINCIA DE PANAMA\n");
	printf("-------------------------------------------------------------\n");
	// En caso para ingresar los datos de la matriz
	// printf("\n Ingresar datos de las 5 sucursales del Banco General: \n\n");
	// for (i = 0; i < 4; ++i)
	// {
	// 	printf(" ");
	// 	for (k = 0; k < 5; ++k)
	// 	{
	// 		scanf("%i", &matriz[i][k]);
	// 	}
	// }
	// printf("\n");

	// imprimiendo datos de sucursales
	printf("Datos de las 5 sucursales del Banco General: \n\n");
	for (i = 0; i < 4; ++i)
	{
		if (i == 0)
			printf(" Personales |");
		if (i == 1)
			printf(" Auto       |");
		if (i == 2)
			printf(" Hipotecas  |");
		if (i == 3)
			printf(" Inversion  |");
		for (k = 0; k < 5; ++k)
		{
			printf(" %i |", matriz[i][k]);
		}
		printf("\n");
	}
	int totaltsu = case1(matriz);
	printf("\n");
	case2(matriz);
	case3(matriz);
	printf("\n Total de las Sucursales: %i\n", totaltsu);
}

int case1(int matriz[4][5])
{
	int sum, total = 0;
	for (i = 0; i < 5; ++i)
	{
		sum = 0;
		for (k = 0; k < 4; k++)
		{
			sum += matriz[k][i];
		}
		total += sum;
		printf("\n total de sucursal %i: %i", i + 1, sum);
	}
	return total;
}

void case2(int matriz[4][5])
{
	char carteras[4][15] = {
		"personales",
		"autos",
		"hipotecas",
		"inversiones",
	};

	char imprma[10], pos = 0;
	int sum, mayor = 0;
	for (i = 0; i < 4; ++i)
	{
		sum = 0;
		for (k = 0; k < 5; ++k)
		{
			sum += matriz[i][k];
		}
		if (mayor < sum)
			mayor = sum;

		pos = i;
	}

	printf("\n La cartera de mayor numero es: %s", carteras[pos]);
}

void case3(int matriz[4][5])
{
	int menor = 100000, sum, pos = 0;
	for (i = 0; i < 5; i++)
	{
		sum = 0;
		for (k = 0; k < 4; k++)
			sum += matriz[k][i];

		if (menor > sum)
		{
			pos = i;
			menor = sum;
		}
	}
	printf("\n La sucursal #%i es la de menor efectivo", pos + 1);
}
