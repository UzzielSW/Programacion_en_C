/*
	6. Utilizar las 2 estructuras del problema 5, pero ahora pedir los datos para N 
	alumnos, y calcular cual de todos tiene el mejor promedio, e imprimir sus datos.
*/
#include<stdio.h>
#include<stdlib.h>

struct Promedio
{
	float nota1;
	float nota2;
	float nota3;
};

struct Alumno
{
	char nombre[20];
	char sexo[20];
	int edad;
	Promedio prom;
};

int main()
{
	int n, i, pmay;
	float promedio[100], mayor = 0.0;
	Alumno alumnos[100];

	printf("Digite el total de alumnos: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\n%d. Digite su nombre: ",i+1);
		gets(alumnos[i].nombre);

		printf("%d. Digite su sexo: ",i+1);
		gets(alumnos[i].sexo);

		printf("%d. Digite su edad: ",i+1);
		scanf("%d",&alumnos[i].edad);

		printf("%d. Digite sus notas: ",i+1);
		scanf("%f %f %f",&alumnos[i].prom.nota1, &alumnos[i].prom.nota2, &alumnos[i].prom.nota3);
		
		promedio[i] = (alumnos[i].prom.nota1 + alumnos[i].prom.nota2 + alumnos[i].prom.nota3)/3;
		
		if(promedio[i] > mayor)
		{
			mayor = promedio[i];
			pmay = i;
		}	
	}
	
	printf("\n-Felicidades, Alumno con Mayor Promedio-\n");
	printf("\nNombre: %s",alumnos[pmay].nombre);
	printf("\nSexo: %s",alumnos[pmay].sexo);
	printf("\nEdad: %d",alumnos[pmay].edad);
	printf("\nPromedio: %.2f\n",promedio[pmay]);
	
	system("pause");
	return 0;
}