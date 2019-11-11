/*
	confeccionar un programa de mastermind: que adivine numeros de 5 digitos, generados aleatoriamente.
	el usuario debe introducir 5 digitos y el programa debe indicar si el digito esta en la posicion correcta
	entonces se considera como un acierto, cada digito en la posicion incorrecta, se considera como una pica.
	el usuario tiene hasta 10 oportunidades para adivinar el numero correcto y el sistema le presente en cada
	oportunidad, sus aciertos y sus picas. cuando adivine el numero con los digitos en las posiciones correctas
	y presente el mensaje respectivo. cuando se le termine las oportunidades tambien indicarselo. 
	utilice vectores y funciones. 

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
#include "stdbool.h"
#define li 1
#define ls 9
bool ciertos[5] = {false,false,false,false,false};	
int main(){
	char rpt;
	int numero[5],verificador[5];
	int opc,i,pica,aciertos;
    void verificar(int[],int[],int *,int *);

    printf("\n Programa MASTERMIND: ");
    printf("\n 1 - Comenzar.");
    printf("\n 2 - Salir.\n");
    printf("\n Tiene 10 Intentos \n");
    printf("\n Introduce una opcion: ");
    scanf("%d",&opc);
   
    while (opc!=2){
    	aciertos=pica=0;
    	srand(time(NULL));
		for ( i = 0; i < 5; i++){
			numero[i] = li + rand() % ((ls+1) - li);
		}
				
	    for (i=0 ; i<10 ; i++){
	    	printf("\n\n Intento numero[%i]",i+1);
	    	printf("\n ingresar 5 digitos: \n\n");
			for ( i = 0; i < 5; ++i){
				printf(" -digito [%i]: ",i+1); scanf("%i",&verificador[i]);
			}
			verificar(numero,verificador,&pica,&aciertos);
			if(aciertos == 5){
				printf("\n\n ���Crongratulations your won���");
				break;
			}	
		}
		if(aciertos!=5) printf("\n\n ��� your loser ���");
		fflush(stdin);
		printf("\n\n Desea seguir jugando (s/n): "); scanf("%c",&rpt);
		if (rpt == 'n') opc = 2;
	}	
  
 return 0; 
}


void verificar(int numero[5],int verificador[5],int *pica,int *aciertos){
	int i;
	for ( i = 0; i < 5; ++i){
		if(numero[i]==verificador[i]){
			printf("\n Digito [%i] posicion correcta",i+1);
			if(ciertos[i]==false){	*aciertos+=1; ciertos[i]=true;  }
		}else{
			 printf("\n Digito [%i] posicion incorrecta",i+1);
			 *pica+=1;
		}    
	}
	printf("\n aciertos: [%i]  ||| picas: [%i]",*aciertos,*pica);
}