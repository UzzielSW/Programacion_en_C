/*
 - banco general tiene 5 sucursales con 4 carteras de prestamos(personales,autos,hipotecas,inversiones).
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
int i,k;

int main()
{
	// declaracion de variables
	int matriz[4][5] = {{100,200,300,300,200},
					    {129,239,599,708,399},
					    {390,500,399,389,179},
					    {120,599,688,700,800}}; // cargando matriz manuelmente

	int pers=0, aut=0, hipo=0, inver=0, mayor=0, menor=99999999;
	int opc, tsu1, tsu2, tsu3, tsu4, tsu5, totaltsu; //tsu# = total de sucursal#
	tsu1=tsu2=tsu3=tsu4=tsu5=totaltsu=0;
	char imprma[10],mensucur[10];

	// declaracion de funciones
	int case1(int [][5],int,int,int,int,int);
	void case2(int [][5],int,int,int,int,int,char []);
	void case3(int,int,int,int,int,int,char []);

	do{	
		system("cls");
		printf ("BIENVENIDO USUARIO AL BANCO GENERAL DE LA PROVINCIA DE PANAMA\n");
		printf ("-------------------------------------------------------------\n");
		printf ("Elige la opcion que deseas realizar: \n 1. Operacion. \n 2. Salir. \n");
		scanf ("%i",&opc);
		switch(opc){
			case 1:
				system("cls");
				// imprimiendo datos de sucursales
				printf("\n Datos de las 5 sucursales del Banco General: \n\n");
				for ( i = 0; i < 4; ++i){ 
					if (i == 0) printf(" Personales |");
					if (i == 1) printf(" Auto       |");
					if (i == 2) printf(" Hipotecas  |");
					if (i == 3) printf(" Inversion  |");
					for (k = 0; k < 5; ++k){ printf(" %i |",matriz[i][k]); } 
				printf("\n"); 
				}
				printf("\n");
        		// llamado de funciones
				totaltsu = case1(matriz,tsu1,tsu2,tsu3,tsu4,tsu5);
				printf("\n");
				case2(matriz,pers,aut,hipo,inver,mayor,imprma);
				printf("\n");
				case3(tsu1,tsu2,tsu3,tsu4,tsu5,menor,mensucur);
				printf("\n");
				printf("\n total de totas las sucursales: %i",totaltsu);
        	break;
		}
	getch();
	}while(opc!=2);
return 0;
}


int case1(int matriz[4][5],int tsu1,int tsu2,int tsu3,int tsu4,int tsu5)
{
	for ( i = 0; i < 4; ++i){ tsu1+=matriz[i][0]; } printf("\n total de sucursal 1: %i",tsu1);
	for ( i = 0; i < 4; ++i){ tsu2+=matriz[i][1]; } printf("\n total de sucursal 2: %i",tsu2);
	for ( i = 0; i < 4; ++i){ tsu3+=matriz[i][2]; } printf("\n total de sucursal 3: %i",tsu3);
	for ( i = 0; i < 4; ++i){ tsu4+=matriz[i][3]; } printf("\n total de sucursal 4: %i",tsu4);
	for ( i = 0; i < 4; ++i){ tsu5+=matriz[i][4]; } printf("\n total de sucursal 5: %i",tsu5);
return (tsu1+tsu2+tsu3+tsu4+tsu5);
}


void case2(int matriz[4][5],int pers,int aut,int hipo,int inver,int mayor,char imprma[10])
{
	for ( i = 0; i < 4; ++i)
	{
		for ( k = 0; k < 5; ++k)
		{
			     if (i==0) pers+=matriz[i][k];
			else if (i==1) aut+=matriz[i][k];
			else if (i==2) hipo+=matriz[i][k];
			else if (i==3) inver+=matriz[i][k];
		}
	}

	if(pers>mayor){  mayor=pers;  strcpy(imprma,"personales"); }
	if(aut>mayor){   mayor=aut;   strcpy(imprma,"autos"); }
	if(hipo>mayor){  mayor=hipo;  strcpy(imprma,"hipotecas"); }
	if(inver>mayor){ mayor=inver; strcpy(imprma,"inversiones"); }

	printf("\n la cartera de mayor numero es: %s",imprma);
}


void case3(int tsu1,int tsu2,int tsu3,int tsu4,int tsu5,int menor,char mensucur[10])
{
	if(tsu1<menor){ menor=tsu1; strcpy(mensucur,"sucursal 1"); }
	if(tsu2<menor){ menor=tsu2; strcpy(mensucur,"sucursal 2"); }
	if(tsu3<menor){ menor=tsu3; strcpy(mensucur,"sucursal 3"); }
	if(tsu4<menor){ menor=tsu4; strcpy(mensucur,"sucursal 4"); }
	if(tsu5<menor){ menor=tsu5; strcpy(mensucur,"sucursal 5"); }

	printf("\n la sucursal de menor efectivo es: %s",mensucur);
}
