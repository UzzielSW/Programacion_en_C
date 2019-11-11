#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"
#include "stdbool.h"
#define li 1000
#define ls 9999
FILE *guarda;
struct Bank
{
	char nombre[30];
	float saldo;
	int contrasenia;
}usuarios[100],*ptrusuario = usuarios;

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);  //colores
void gotoxy (int,int);                           //posicion

int main(){SetConsoleTitle(" ::Bank:: ");
	// declaracion de variables y funciones
	int opc,cant=0;
	int menu(void);
	int crearCuenta(int);
	void estadoCuentas(int);
	void depositos(int);
	void retiros(int);
 	int eliminarCuenta(int);
 	void salida(int);
	int recuperandoDatos(void);
	cant = recuperandoDatos(); 
	// menu
	do{
		opc = menu();
		switch(opc){
			case 1: cant = crearCuenta(cant);    			 	break;
			case 2:	estadoCuentas(cant);         	   		 	break;
			case 3: depositos(cant);             			 	break;
	 		case 4: retiros(cant);          				 	break;
	        case 5: cant = eliminarCuenta(cant);   			 	break;
	        case 6: salida(cant); 							 	break;
			default: printf("\n Ingrese una opcion del 1 al 5");break;
		}
	getch();	
	} while(opc!=6);
return 0;
}


int menu(void)
{	int opc=0,a,b;
	system("cls");	
	
//	cuadro
	for (a=2;a<118;a++)
	{
		gotoxy (a,1);
		SetConsoleTextAttribute (screen,245);
		printf ("%c",205);
		
		gotoxy (a,28);
		SetConsoleTextAttribute (screen,245);
		printf ("%c",205);
	}
	
	for (b=2;b<28;b++)
	{
		gotoxy (1,b);
		SetConsoleTextAttribute (screen,245);
		printf ("%c",186);
			
		gotoxy (118,b);
		SetConsoleTextAttribute (screen,245);
		printf ("%c",186);
	}
	
//	esquinas
	gotoxy (1,1);
	SetConsoleTextAttribute (screen,245);
	printf ("%c",201);
	
	gotoxy (118,1);
	SetConsoleTextAttribute (screen,245);
	printf ("%c",187);
	
	gotoxy (1,28);
	SetConsoleTextAttribute (screen,245);
	printf ("%c",200);
	
	gotoxy (118,28);
	SetConsoleTextAttribute (screen,245);
	printf ("%c",188);
	
//	menu
	gotoxy (35,4);
	SetConsoleTextAttribute (screen,245);
	printf("         |   °°°::Jeisson Bank::°°°   |          ");	
	gotoxy (45,6);
	SetConsoleTextAttribute (screen,240);
	printf("       1.Crear cuenta       ");
	gotoxy (45,8);
	SetConsoleTextAttribute (screen,241);		
	printf("    2.Estado de cuentas     ");
	gotoxy (45,10);	
	SetConsoleTextAttribute (screen,242);		
	printf("        3.Depositos         ");
	gotoxy (45,12);
	SetConsoleTextAttribute (screen,243);		
	printf("         4.Retiros          ");
	gotoxy (45,14);
	SetConsoleTextAttribute (screen,244);		
	printf("      5.Eliminar cuenta     ");	
	gotoxy (45,16);
	SetConsoleTextAttribute (screen,246);		
	printf("          6.salir           ");	
	gotoxy (45,18);
	SetConsoleTextAttribute (screen,245);		
	printf("   elije una opcion: "); 
	scanf("%i",&opc);
return opc;
}


int crearCuenta(int i)
{	float verificador=0;
		
		fflush(stdin);
		printf("\n ingrese su nombre: "); 
		scanf("%[^\n]",&(ptrusuario+i)->nombre);
		printf(" ingrese un saldo de apertura mayor o igual a 50$: "); 
		scanf("%f",&verificador);
		if(verificador>=50){
			(ptrusuario+i)->saldo = verificador;
			srand(time(NULL));
			(ptrusuario+i)->contrasenia = li + rand() % ((ls+1) - li);
			printf("\n su cuenta a sido creada correctamente, su contrasenia es: %i \a",(ptrusuario+i)->contrasenia);
		return ++i;
		}else{ printf("\n la cuenta no se creo, ingrese un saldo de apertura mayor a 50$ balboas "); return i; }
}



void estadoCuentas(int cant)
{	int contra=0;	bool desi = false;

	printf(" \n contrasenia: "); 
	scanf("%i",&contra);	
	for (int i = 0; i < cant; ++i)
	{
		if(contra==(ptrusuario+i)->contrasenia && desi==false){
			printf("\n °° Bienvenido %s °°\n",(ptrusuario+i)->nombre);
			printf("\n su saldo actual es: %.2f",(ptrusuario+i)->saldo);
			desi=true;
		}
	}
	if(desi == false) printf("\n contrasenia incorrecta"); 
}



void depositos(int cant)
{	int contra=0; float depo=0;	bool desi = false;
	
	printf(" \n contrasenia: "); 
	scanf("%i",&contra);	
	for (int i = 0; i < cant; ++i)
	{
		if(contra==(ptrusuario+i)->contrasenia && desi==false){
			printf("\n °° usuario %s °° \n",(ptrusuario+i)->nombre);
			printf("\n ingrese la cantidad que desea depositar: "); 
			scanf("%f",&depo);
			(ptrusuario+i)->saldo+=depo;
			printf("\n Su saldo nuevo es: %.2f",(ptrusuario+i)->saldo);
			desi=true;
		}
	}
	if(desi == false) printf("\n contrasenia incorrecta"); 
}


void retiros(int cant)
{	int contra=0,opc=0;  float retiro=0;  bool desi = false;
	printf("\n contrasenia: "); 
	scanf("%i",&contra);	

	for (int i = 0; i < cant; ++i)
	{
		if(contra==(ptrusuario+i)->contrasenia && desi == false){ 
			if((ptrusuario+i)->saldo>=5){
				printf("\n °° usuario %s °° \n",(ptrusuario+i)->nombre); 
				printf("\n 1.)  20$ \n 2.)  50$ \n 3.)  100$ \n 4.)  500$ \n 5.)  otros \n Su saldo actual es: %.2f",(ptrusuario+i)->saldo);
				printf("\n ingrese una opcion para retirar: "); 
				scanf("%i",&opc);

				switch(opc){
					case 1: 
						if((ptrusuario+i)->saldo>=20)  (ptrusuario+i)->saldo-=20;
						else printf("\n su saldo es insuficiente");
					break;

					case 2: 
						if((ptrusuario+i)->saldo>=50)  (ptrusuario+i)->saldo-=50;
						else printf("\n su saldo es insuficiente");
					break;

					case 3: 
						if((ptrusuario+i)->saldo>=100)  (ptrusuario+i)->saldo-=100;
						else printf("\n su saldo es insuficiente");
					break;

					case 4: 
						if((ptrusuario+i)->saldo>=500)  (ptrusuario+i)->saldo-=500;
						else printf("\n su saldo es insuficiente");
					break;

					case 5: 
						printf("\n ingrese la cantidad que desea retirar: "); 
						scanf("%f",&retiro);
						if((ptrusuario+i)->saldo>=retiro)  (ptrusuario+i)->saldo-=retiro;
						else printf("\n su saldo es insuficiente");
					break;
				}
				printf("\n Su saldo actual es: %.2f",(ptrusuario+i)->saldo); desi=true;
			}else printf("\n no se puede realizar un retiro menor a 5 balboas");
		}
	}
	if(desi == false) printf("\n contrasenia incorrecta"); 
}


int eliminarCuenta(int cant)
{	int contra=0,i,k;	bool desi = false;
	Bank *aux;
	printf(" \n contrasenia: "); 
	scanf("%i",&contra);
	aux = ptrusuario;
	if(aux->contrasenia == contra){
		for(i=0;i<cant-1;i++){
			strcpy((ptrusuario+i)->nombre , (ptrusuario+i+1)->nombre);
			(ptrusuario+i)->saldo = (ptrusuario+i+1)->saldo;
			(ptrusuario+i)->contrasenia = (ptrusuario+i+1)->contrasenia;
		}
		desi = true; 
	}else{
		for( i = 1; i < cant; i++){
			aux = ptrusuario+i;
			if((aux)->contrasenia == contra && desi==false){
				for(k=i;k<cant-1;k++){
					strcpy((ptrusuario+k)->nombre , (ptrusuario+k+1)->nombre);
					(ptrusuario+k)->saldo = (ptrusuario+k+1)->saldo;
					(ptrusuario+k)->contrasenia = (ptrusuario+k+1)->contrasenia;
				}
				desi=true;
			}
			if(desi==true) break;
		}
	}
	if(desi == false){ printf("\n cuenta no encontrada"); return cant; } 
	else{
		printf("\n °° Usuario: %s °°\n",(aux)->nombre);
		printf("\n cuenta eliminada");
		return --cant;
	}
	delete aux;
}

void salida(int cant)
{	int i;
	void bank();
		system("cls");
		guarda = fopen("jeisson_bank.dat","w");
		if(guarda == NULL)	printf("\n no se guardo correctamente");
		else{
			for ( i = 0; i < cant; ++i){
				if((ptrusuario+i)->contrasenia != NULL){
					fprintf(guarda,"%s\n",(ptrusuario+i)->nombre);
					fprintf(guarda,"%.2f %i\n",(ptrusuario+i)->saldo,(ptrusuario+i)->contrasenia);
				}
			}
			fclose(guarda);
		}
	bank();
}


int recuperandoDatos(void)
{  int cant=0;

	guarda = fopen("jeisson_bank.dat","r");
	
	if(guarda == NULL)	return cant;
	else{
		while(feof(guarda)==0){
			fscanf(guarda,"%[^\n]",(ptrusuario+cant)->nombre);
			fscanf(guarda,"%f",&(ptrusuario+cant)->saldo);
			fscanf(guarda,"%i",&(ptrusuario+cant)->contrasenia);
			cant++;
		}
		fclose(guarda);
		return cant;
	}
}



void bank(){
system("cls");
printf("\n\n\t\t\t\t\t\t\t\t     ____                              \n");
printf("\t\t\t\t\t\t\t\t     |  |_____________\n");
printf("\t\t\t\t\t\t\t\t     | /` /;-----;   |      \n");
printf("\t\t\t\t\t\t\t\t     /` /` ||_|_||   |  .:$Bank$:. \n");
printf("\t\t\t\t\t\t\t\t   /` /`   ||_|_||   |_________________________ \n" );
printf("\t\t\t\t\t\t\t\t /`_/`     '-----'          |        |      | *\n" );
printf("\t\t\t\t\t\t\t\t    | .---.   .---.   .---. |  .--.  | .--. |  \n");
printf("\t\t\t\t\t\t\t\t    | |$_F|   |F_C|   |$_$| |  |FC|  | |$$| |  \n");
printf("\t\t\t\t\t\t\t\t    | |C_$|   |$_$|   |F_C| |  |$$|  | |FC| |  \n");
printf("\t\t\t\t\t\t\t\t    | '---'   '---' _.--._' |  '--'  | '--' | \n");
printf("\t\t\t\t\t\t\t\t   _|____________,-  _.._  -;________|______|__ \n");
printf("\t\t\t\t\t\t\t\t  /_______________,-  __  -._________T________| \n");
printf("\t\t\t\t\t\t\t\t   ||   .----.   ||  |$$|  ||  .--.  | .--. ||   \n");
printf("\t\t\t\t\t\t\t\t   ||   |$FC$|   ||  | .|  ||  |$$|  | |$$| ||  \n");
printf("\t\t\t\t\t\t\t\t   ||   |$FC$|  _$$_ |  | _$$_ |$$|  | |$$| ||  \n");
printf("\t\t\t\t\t\t\t\t   ||   '----'  |**|_|__|_|**| '--'  | '--' ||  \n");
printf("\t\t\t\t\t\t\t\t   ||TTTTTTTTTTT|  |======|  |TTTTTTTTTTTTTTTT  \n");
printf("\t\t\t\t\t\t\t\t   ||||||||||||||  |======|  |||||||||||||||||  \n");
printf("\t\t\t\t\t\t\t\t  ^^^^^^^^^^^^^^^^^^      ^^^^^^^^^^^^^^^^^^^^^  \n");
}


void gotoxy (int x , int y)
{  
    HANDLE hcon;
    hcon=GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition (hcon,dwPos);
}
