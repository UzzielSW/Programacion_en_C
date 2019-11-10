//programa de equivalencia de caracteres en codigo ASCII
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define li 33  //li = limite inferior
#define ls 126 //ls = limite superior
//los limites van de 33 a 136 porque son los caracteres ASCII basicos del teclado
int main()
{
	unsigned char letra;  //unsigned el numero del valor ASCII es solo positivo.(unsigned es que no tiene signo)
	int numero=0;
	int opc=0;
	do{
		system("cls");
		printf("\n 1.codificar ");
		printf("\n 2.decodificar ");
		printf("\n 3.salir");
		printf("\n opcion: "); scanf("%d",&opc);

		switch(opc)
		{
			case 1:
				printf("\n ingrese un caracter: "); 
				fflush(stdin);
				scanf("%c",&letra);
				printf("\n el caracter %c equivale a %d en codigo ASCII",letra, letra); 
			break;

			case 2:
				srand(time(NULL));
				numero = li + rand() % ((ls+1) - li);
				printf("\n el numero generado es: %d",numero);
				printf("\n En codigo ASCII %d equivale al caracter: %c ",numero, numero); 
			break;
		}
		getchar();
	}while(opc != 3);
return 0;
}