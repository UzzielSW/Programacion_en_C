/*
	3. Realizar un programa en C que lea un arreglo de estructuras los datos
	de N empleados de la empresa y que imprima los datos del empleado con
	mayor y menor salario.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct
{
	char nombre[20];
	char sexo[20];
	float salario;	
}Empleado;

int main()
{
	int i,n, pmay, pmen;
	float mayor = 0, menor = 999999999;
	Empleado empleados[MAX];

	printf("Digite el numero de empleados de la empresa: ");
	scanf("%d",&n);

	if(n > MAX) exit(0);
	
	for(i=0; i < n ; i++)
	{
		fflush(stdin);
		printf("%d. Digite su nombre: ",i+1);
		gets(empleados[i].nombre);

		fflush(stdin);
		printf("%d. Digite su sexo: ",i+1);
		gets(empleados[i].sexo);

		printf("%d. Digite su salario: ",i+1);
		scanf("%f",&empleados[i].salario);
		printf("\n");
	}

	//Comprobando el mayor y menor Salario
	for(i=0; i < n; i++)
	{
		if(empleados[i].salario > mayor)
		{ 
			mayor = empleados[i].salario;
			pmay = i;
		}

		if(empleados[i].salario < menor)
		{
			menor = empleados[i].salario;
			pmen = i;
		}
	}
	
	printf("\nEl empleado con el mayor salario es: \n");
	printf("\nNombre: %s",empleados[pmay].nombre);
	printf("\nSexo: %s",empleados[pmay].sexo);
	printf("\nSalario: %.2f",empleados[pmay].salario);
	
	printf("\n\nEl empleado con el menor salario es: \n");
	printf("\nNombre: %s",empleados[pmen].nombre);
	printf("\nSexo: %s",empleados[pmen].sexo);
	printf("\nSalario: %.2f\n",empleados[pmen].salario);
	
	system("pause");
	return 0;
}