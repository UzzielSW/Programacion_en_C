/*
	5. Realice un programa que lea en un array el sexo de los N 
	estudiantes del curso de Algoritmos y que determine cuantos hombres y
	cuantas mujeres se encuentran en el grupo, suponiendo que los datos
	son extraidos alumno por alumno.
*/
#include<stdio.h>

int main()
{
	int i, numero, varon=0, mujer=0;
	char alumnos[100];
	
	printf("Digite el total de alumnos: ");
	scanf("%d",&numero);
	
	for(i=1; i <= numero; i++)
	{
		fflush(stdin);
		printf("%d. Digite el sexo del alumn@: ",i);
		gets(alumnos);
		
		if(strcmp(alumnos,"masculino") == 0) varon++;
		else if(strcmp(alumnos,"femenino") == 0) mujer++;
	}
	
	printf("\n La cantidad de varones es: %d",varon);
	printf("\n La cantidad de mujeres es: %d",mujer);
	
	getchar();
	return 0;
}