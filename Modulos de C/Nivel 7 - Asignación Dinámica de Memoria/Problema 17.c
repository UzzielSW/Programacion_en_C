/*
	Problema 17:
	crear un programa que tenga una estructura denominada "Alumno", en la que debe considerarse como
	sus campos el nombre del Alumno, el sexo(f o m) y la edad.El programa debe permitir el ingreso 
	de una cantidad de Alumnos, calcular la cantidad de varones y mujeres que hay en el grupo,
	y la edad mayor del Alumno, luego debe visualizar la cantidad de mujeres y varones asi como la
	informacion del Alumno cuya edad es mayor.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[20];
	char sexo;
	int edad;	
}Alumno;

int main()
{
	int i, canA, canF, canM, pos, mayor;
	canF = canA = canM = pos = mayor = 0;
	Alumno *Alumnos;
	
	printf("\n ingrese la cantidad de Alumnos: ");
	scanf("%d",&canA);

	Alumnos = (Alumno *) calloc(canA, sizeof(Alumno));

	puts(" ingrese los datos de los estudiantes:");
	for (i = 0; i < canA; ++i)
	{
		printf("\n\n Alumno[%d]\n",(i+1));
		printf(" nombre: ");
		fflush(stdin); scanf("%[^\n]",&Alumnos[i].nombre);
		printf(" sexo (f o m): ");
		fflush(stdin); scanf("%c",&Alumnos[i].sexo);
		printf(" edad: "); scanf("%d",&Alumnos[i].edad);

		if(Alumnos[i].sexo == 'f') canF++;
		if(Alumnos[i].sexo == 'm') canM++;
		if(Alumnos[i].edad > mayor)
		{ 
			mayor = Alumnos[i].edad;
			pos = i;
		}
	}

	puts("\n\n Datos requeridos: ");
	printf(" cantidad de varones: %d",canM);
	printf("\n cantidad de mujeres: %d",canF);
	printf("\n informacion de Alumno con mayor edad: ");
	printf("\n nombre: %s",Alumnos[pos].nombre);
	printf("\n sexo: %c",Alumnos[pos].sexo);
	printf("\n edad: %d",Alumnos[pos].edad);

	free(Alumnos);
	return 0;
}