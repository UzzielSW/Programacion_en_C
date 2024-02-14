/* 
	Menu principal	(1)
		1.Pila  1.1
		2.Cola  1.2
		3.Salir 1.3

		Menu Pila (1.1)
			1.Pone 		1.1.1
			2.Quita		1.1.2
			3.Mostrar   1.1.3
			4.Regresar  1.1.4

		Menu Cola (1.2)
			1.Pone 		1.2.1
			2.Quita		1.2.2
			3.Mostrar   1.2.3
			4.Regresar  1.2.4

		Salir (1.3)
			GuardarPila -> GuardarCola -> Salir
*/

#include "iostream"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "fstream"
#define MAX 5
using namespace std;

#include "funcionesPila.h" // Vinculando funciones de Pila
#include "funcionesCola.h" // vinculando funciones de Cola

//funciones menu principal
int Menu_Pila(Pila Mercancias[MAX], int TOPE);	               //  1.1 
void Menu_Cola(Cola Clientes[MAX], int *frente, int *final);  //  1.2
void Guardar_Pila_Cola(Pila[], int TOPE, Cola[], int frente, int final);       //  1.3

int main()
{
	int opc;
	
	//Pila
	Pila Mercancias[MAX];
	int TOPE = -1;
	
	//Cola
	Cola Clientes[MAX];
	int FRENTE = -1, FINAL = -1;


	//Menu Principal
	do{	system("cls");
		cout<<"\n [ Estructuras de Datos Estaticas ]\t\t\t"<<char(174)<<"Junior"<<char(175)
			<<"\n\n 1.Pila"
			<<"\n 2.Cola"
			<<"\n 3.Salir"
			<<"\n\n >> ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				TOPE = Menu_Pila(Mercancias, TOPE);
			break;

			case 2:
				Menu_Cola(Clientes, &FRENTE, &FINAL);
			break;

			default:
				Guardar_Pila_Cola(Mercancias, TOPE, Clientes, FRENTE, FINAL);
				opc = 3; 
		}getch();
	} while (opc != 3);
	return 0;
}


void Guardar_Pila_Cola(Pila Mercancias[MAX], int TOPE, Cola Clientes[MAX], int FRENTE, int FINAL)
{
	ofstream Archivo_Pila, Archivo_Cola;

	/// guardando datos de la pila ///
	Archivo_Pila.open("archivos//Mercancias.dat");

	if(Archivo_Pila.fail())
		cout<<"\n Error al abrir el archivo \"Mercancias.dat\"";
	else{
		if(TOPE != -1){ // guardar mientras la pila no este vacia
			for(int i = 0; i <= TOPE ; i++){
				Archivo_Pila<< Mercancias[i].nombre<< " "
							<< Mercancias[i].cantidad<< " "
							<< Mercancias[i].precio<<endl;
			}
			cout<< "\n Se guardaron los datos de la Pila correctamente";
		}else
			cout<<"\n Pila vacia [no se guardo ningun dato]";
		
		Archivo_Pila.close();
	}

	/// guardando datos de la cola ///
	Archivo_Cola.open("archivos//Clientes.dat");

	if(Archivo_Cola.fail())
		cout<<"\n Error al abrir el archivo \"Clientes.dat\"";
	else{
		if(FINAL != -1){// guardar mientras la cola no este vacia
			for(int i = FRENTE; i <= FINAL ; i++){
				Archivo_Cola<< Clientes[i].nombre<< " "
							<< Clientes[i].total<<endl;
			}
			cout<< "\n Se guardaron los datos de la Cola correctamente";
		}else
			cout<<"\n Cola vacia [no se guardo ningun dato]";
		
		Archivo_Cola.close();
	}
	
}
