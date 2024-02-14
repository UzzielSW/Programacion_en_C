/*
	10. Un alumno desea saber cual sera su calificacian final en la materia de Algoritmos.
	Dicha calificacion se compone de los siguientes porcentajes:

	* 55% del promedio de sus tres calificaciones parciales.
	* 30% de la calificacion del examen final.
	* 15% de la calificacion de un trabajo final. (Propuesto)
*/

#include<stdio.h>

int main()
{
	float p1, p2, p3, examen, trabajo, promedio_parcial;
	float p_parcial = 0, p_examen = 0, p_trabajo = 0, calificacion = 0;
	
	printf("Digite la nota de los 3 parciales: ");
	scanf("%f %f %f",&p1, &p2, &p3);
	
	printf("Digite la nota del examen final: ");
	scanf("%f",&examen);
	
	printf("Digite la nota del trabajo final: ");
	scanf("%f",&trabajo);
	
	promedio_parcial = (p1+p2+p3)/3;
	
	p_parcial = promedio_parcial * 0.55;
	p_examen = examen * 0.30;
	p_trabajo = trabajo * 0.15;
	
	calificacion = p_parcial + p_examen + p_trabajo;
	
	printf("La calificacion final es: %f",calificacion);
	
	return 0;
}