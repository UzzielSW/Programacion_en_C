/*
	3. Hace un programa que muestre un menú con las opciones sumar, restar, multiplicar y 
	dividir, el programa solicitará una opción y realizará la tarea elegida, se debe usar un procedimientos 
*/
#include<stdio.h>

int main()
{
	void menu();
	menu();
	return 0;
}

void menu()
{
	int opc,resp=0;
	int sumar();
	int restar();
	int multiplicar();
	void dividir();
	
	do{	
		puts("1. Sumar");
		puts("2. Restar");
		puts("3. Multiplicar");
		puts("4. Dividir");
		puts("5. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);
		
		switch(opc)
		{
			case 1: sumar();break;
			case 2: restar();break;
			case 3: multiplicar();break;
			case 4: dividir();break;
		}		
		
	}while(opc!= 5);
}

void sumar()
{
	int n1,n2;
	
	printf("\nDigite 2 numeros: ");
	scanf("%d %d",&n1,&n2);
	
	printf("La suma es: %d.\n",(n1+n2));	
}

void restar()
{
	int n1,n2;
	
	printf("\nDigite 2 numeros: ");
	scanf("%d %d",&n1,&n2);
	
	printf("La resta es: %d.\n",(n1-n2));	
}

void multiplicar()
{
	int n1,n2;
	
	printf("\nDigite 2 numeros: ");
	scanf("%d %d",&n1,&n2);
	
	printf("La multiplicacion es: %d.\n",(n1*n2));	
}

void dividir()
{
	int n1,n2;
	
	printf("\nDigite 2 numeros: ");
	scanf("%d %d",&n1,&n2);
	
	if(n2 != 0)
		printf("La division es: %d.\n",n1/n2);
	else
		puts("exception not div by zero")	
}