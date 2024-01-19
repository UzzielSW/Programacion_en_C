// ley de coulomb
// calcular la fuerza entre dos cargas
#include <iostream>
#include<stdio.h>
#include<math.h>
#define K 9000000000
double Fuerza(double, double, double);
double powI(double, int);
double powS(double, int);

int main(){

double q1, q2; //cargas
double dis; //distancia r
int exp; //exponencial
double F12; //fuerza
int opc; //opcion(metros/centimetros)
float px1, py1, px2, py2; //puntos en el plano de q1,q2

//pedir carga de q1 
printf("\n carga q1: "); scanf("%lf",&q1);
printf(" q1x10^"); scanf("%d",&exp);

q1 = (exp < 0)? powI(q1, exp) : powS(q1, exp);

//// pedir carga de q2
printf("\n carga q2: "); scanf("%lf",&q2);
printf(" q2x10^"); scanf("%d",&exp);
q2 = (exp<0)? powI(q2,exp) : powS(q2,exp);

// pedir distancia
printf("\n leer distancia en: "); 
printf("\n 1.metros"); 
printf("\n 2.centimetros"); 
printf("\n opcion? ");
scanf("%d",&opc);

printf("\n distancia = "); 
scanf("%lf",&dis);

//covirtiendo de centimetros a metros
if(opc == 2) dis /= 100;

//caculando fuerza
F12 = Fuerza(q1, q2, dis);

//imprimiendo resultado
exp = 0;
if(F12 < 1){

	while(F12 < 1){
		F12 *= 10;
		exp--;
	}
	
	printf("\n Fuerza entre las cargas: %.2lfx10^%d N", F12,exp);
}else
	printf("\n Fuerza entre las cargas: %.2lf N", F12);

return 0;
}

double Fuerza(double q1,double q2,double dis){
  return ((K*q1*q2)/(pow(dis,2)));
}

double powI(double q1,int exp){
		exp *= -1;
  	for(int i = exp; exp >= 1; exp--) q1 /= 10;
  	
return(q1);
}

double powS(double q1,int exp){
	for(int i = exp; exp >= 1; exp--) q1 *= 10;
  	
return(q1);
}