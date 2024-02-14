#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	float x, y;
}Punto;

//prototipos
Punto *crea_punto();
void *crea_memoria_punto(int n);
void desplegar_puntos(Punto *p);
float calcular_distancia(Punto *p1, Punto *p2);
void calcular_linea_recta(Punto *p1, Punto *p2);

int main()
{
	float distancia;
	Punto *p1, *p2;

	p1 = crea_punto();
	p2 = crea_punto();

	printf("\n ingrese los puntos en las coordenadas(x,y) del punto 1: ");
	scanf("%f %f", &p1->x, &p1->y);

	fflush(stdin);

	printf("\n ingrese los puntos en las coordenadas(x,y) del punto 2: ");
	scanf("%f %f", &p2->x, &p2->y);
	
	fflush(stdin);

	desplegar_puntos(p1);
	desplegar_puntos(p2);

	distancia = calcular_distancia(p1, p2);

	printf("\n la distancia entre los p1 y p2 es: %.2f", distancia);

	calcular_linea_recta(p1, p2);

	getchar();

	return 0;
}

Punto *crea_punto(){
	return (Punto *) crea_memoria_punto(sizeof(Punto));
}

void *crea_memoria_punto(int N){
	void *p = (int *) malloc(N);
	if (p == NULL)
	{
		puts("\n no hay memoria disponible");
		getchar();
		exit(1);
	}
	return p;
}

float calcular_distancia(Punto *p1, Punto *p2){
	return (sqrt(pow((p2->x - p1->x),2) + pow((p2->y - p1->y),2)));
}

void desplegar_puntos(Punto *p){
	static int i=0;
	printf("\n Punto %i (%.2f,%.2f)",++i, p->x, p->y);
}

void calcular_linea_recta(Punto *p1, Punto *p2){
	float A = (p2->x - p1->x);
	float M;
	float B;

	if (A == 0)
	{
		printf("\n Pendiente M infinita");
		printf("\n X = %.2f", p1->x);
	}else{
		M = (p2->y - p1->y);

		if( (M > 0) || (M < 0)){
			B = (p1->y - (M * p1->x));
			printf("\n La ecuacion de la recta es: ");
			printf(" y = %.2f X + %.2f", M, B);
		}else{
			printf("\n __________________");
			printf("\n Y = %.2f", p1->y);
		}
	}
}