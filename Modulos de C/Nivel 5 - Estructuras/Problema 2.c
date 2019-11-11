/*
	2. Hacer una estructura llamada alumno, en la cual se tendran los
	siguientes miembros: Nombre, edad, promedio, pedir datos al usuario 
	para 3 alumnos, comprobar cual de los 3 tiene el mejor promedio y
	posteriormente imprimir los datos del alumno
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char nombre[20];
	int edad;
	float promedio;
}Alumno;

int main()
{
	int i, pos;
	float mejorNota = 0;
	Alumno alumnos[3];
	
	for(i=0; i < 3; i++)
	{
		fflush(stdin);
		printf("%d. Digite su nombre: ",i+1);
		gets(alumnos[i].nombre);

		printf("%d. Digite su edad: ",i+1);
		scanf("%d",&alumnos[i].edad);

		printf("Digite su promedio: ",i+1);
		scanf("%f",&alumnos[i].promedio);
		puts("");
	}
	
	for(i=0; i < 3; i++)
	{
		if(alumnos[i].promedio > mejorNota)
		{
			mejorNota = alumnos[i].promedio;
			pos = i;
		}
	}
	
	//Imprimimos los datos del mejor promedio
	printf("\nEl alumno con la mejor nota es: \n");
	printf("\nNombre: %s",alumnos[pos].nombre);
	printf("\nEdad: %d",alumnos[pos].edad);
	printf("\nPromedio: %.2f\n\n",alumnos[pos].promedio);
	
	system("pause");
	return 0;
}