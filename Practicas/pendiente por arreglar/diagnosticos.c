// pag 31 problema1
/*
	determine los diagnosticos que existen y la cantidad de pacientes por enfermedad diagnosticada.
	ademas de presentar la lista de todos los pacientes.
 */

#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdbool.h"
typedef struct 
{
	int dia,mes,anio;
}fecha;


typedef struct 
{
	char nombre[10],diagnostico[15];
	int identificacion;
    fecha naci; 
}pacientes;


int main(){
	bool desi = false;
	pacientes _pacientes[10];
	char aux[15];
	char diagnosticos[10][15];
	int cant_diag[10];
	int opc,cant=0,i,k,con=0;
	for(i=0;i<10;i++) cant_diag[i] = 0;
	do{	system("cls");
		printf("\n clinica");
		printf("\n 1.Atenderse");
		printf("\n 2.diagnosticos");
		printf("\n 3.lista de pacientes");
		printf("\n 4.salir");
		printf("\n elije una opcion: ");	scanf("%i",&opc);
		switch(opc){

			case 1:
				if (cant<=10){
					fflush(stdin);
					printf("\n digite su nombre: ");	scanf("%[^\n]",&_pacientes[cant].nombre);
					printf(" digite su identificacion: ");	scanf("%i",&_pacientes[cant].identificacion);
					fflush(stdin);
					printf(" digite su diagnostico: ");	scanf("%[^\n]",&_pacientes[cant].diagnostico);
					printf(" digite su fecha de nacimiento: ");	
					scanf("%i %i %i",&_pacientes[cant].naci.dia, &_pacientes[cant].naci.mes, &_pacientes[cant].naci.anio);
					cant++;
				}else printf("\n cantidad de pacientes lleno");
			break;

			case 2:
//			    for(i=0;i<10;i++) cant_diag[i] = 0;
//	metodo #1	diagnosticos[10][15] = 0;	
//				aux[15] = 0;
//				con=0;	
				for ( i = 0; i < cant; i++)
				{
					strcpy(aux, _pacientes[i].diagnostico);
					for ( k = 0; k <con ; ++k){
						if(strcmp(aux, diagnosticos[k])==0) desi = true;
					}
					
					if(desi==false){
						strcpy(diagnosticos[con], aux);
//						for ( k = 0; k < cant; ++k){
// 	metodo #1				if(strcmp(diagnosticos[con], _pacientes[k].diagnostico)==0) ++cant_diag[con];
//						}
						con++;
					}
					desi=false;
				}

				// metodo 2 ////////////////////////////////////////////////////
				for ( i = 0; i < con ; i++)
				{
					strcpy(aux,diagnosticos[i]); cant_diag[i]=0;
					for ( k = 0; k < cant ; k++)
					{
						if(strcmp(aux,_pacientes[k].diagnostico)==0) ++cant_diag[i];
					}
				}
				///////////////////////////////////////////////////////////////////
				
				printf("\n diagnosticos existentes: ");
				for ( i = 0; i < con; ++i){
					printf("\n\n diagnostico #%i",i+1);
					printf("\n nombre: %s  ||  cantidad: %i",diagnosticos[i],cant_diag[i]);
				}
			break;

			case 3:
				printf("\n lista de todos los pacientes: ");
				for ( i = 0; i < cant; ++i){
					printf("\n\n paciente #%i",i+1);
					printf("\n nombre: %s",_pacientes[i].nombre);
					printf("\n identificacion: %i",_pacientes[i].identificacion);
					printf("\n diagnostico: %s",_pacientes[i].diagnostico);
					printf("\n fecha de nacimiento: %i/%i/%i",_pacientes[i].naci.dia, _pacientes[i].naci.mes, _pacientes[i].naci.anio);
				}
			break;
		}getch();
	}while(opc!=4);
return 0;
}