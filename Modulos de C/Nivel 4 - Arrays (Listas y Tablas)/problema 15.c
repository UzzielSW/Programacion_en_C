/*
	sea notas una matriz de 3x10 que almacene las calificaciones de los 10 alumnos de una calse
	en cada una de las 3 asignaturas que cursan. se pide diseñar una funcion que reciba por parametro
	las calificaciones obtenidas por los alumnos en una determinada asignatura y que devuelva la
	calificacion promedio. hacer un programa que inicialice la matriz con valores dados y que invoque
	a la funcion para calcular la nota promedio de cada una de las asignaturas, imprimiendo el resultado
	por pantalla.
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	double calculoPromedio(double *);
	double promedio=0;
	int i;
	double matriz[3][10] = {
		{2.1, 3.2, 4.3, 5.0, 5.0, 4.4, 3.5, 2.6, 1.7, 5.8}, 
		{1.1, 1.2, 2.3, 2.4, 3.5, 3.6, 5.0, 5.0, 4.7, 4.8}, 
		{5.0, 5.0, 4.1, 5.0, 4.2, 3.3, 2.4, 1.5, 1.6, 5.0}
						};

	for ( i = 0; i < 3; i++)
	{
		printf("\n\n enviando notas de la asignatura #%d",i+1);
		printf("\n promedio de las notas de la asignatura #%d: %.2lf", (i+1), calculoPromedio(matriz[i]));
	}

	puts("\n");
	system("pause");
	return 0;
}

double calculoPromedio(double *matriz)
{
	double suma = 0;
	int i;
	for(i=0; i < 10; i++)
		suma += *(matriz + i);

	return (suma / 10);
}