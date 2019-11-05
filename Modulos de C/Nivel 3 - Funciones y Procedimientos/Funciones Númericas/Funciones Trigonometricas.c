 /* Funciones Trigonometricas:

	acos(x)    -> Calcula el arco coseno de x. 
	asin(x)    -> Calcula el arco seno de x.
	atan(x)    -> Calcula el arco tangente de x.
	cos(x)     -> Calcula el coseno del angulo x, en radianes.
	sin(x)     -> Calcula el seno del angulo x, en radianes.
	tan(x)     -> Devuelve la tangente del angulo x, en radianes.
*/
#include<stdio.h>
#include<math.h>
#define PI 3.141592654

float grados(float x){ return x * (PI / 180); }

int main()
{
	void funciones_trigonometricas();
	
	funciones_trigonometricas();
	
	return 0;
}

void funciones_trigonometricas()
{
	float x;
	
	printf("Digite un numero: ");
	scanf("%f",&x);

	printf("\n tangente en radiales: %.2f",tan(x));
	printf("\n tangente en grados: %.2f",tan(grados(x)));
}