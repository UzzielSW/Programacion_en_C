#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int dia,mes,anio;
}Fecha;

typedef struct
{
	char nombre[20], direccion[30];
	int curso;
	Fecha fecha;
}Estudiantes;


Estudiantes Leer(Estudiantes);
void Buscar();
void ImprimirRegistro(Estudiantes);

FILE *stud;
Estudiantes alumno;

int main()
{	
	void EscribirRegistro();

	EscribirRegistro();  
	Buscar();
	getchar();

	return 0;
}

void EscribirRegistro()
{
	stud = fopen("academia.dat","w+");

	if(stud == NULL)
	{
		puts("\n no se creo el archivo");
		return;
	} 
	
	while(1)
	{
		fflush(stdin);
		printf("\n\n ingrese el nombre del estudiante, (SI) para salir: "); 
		scanf("%[^\n]",alumno.nombre);

		if(strcmp(alumno.nombre,"SI") == 0) break; //fin de proceso
		
		fflush(stdin);
		printf(" ingrese la direccion: "); 
		scanf("%[^\n]",alumno.direccion);

		printf(" ingrese el anio que cursa: "); 
		scanf("%d",&alumno.curso);

		puts(" ingrese la fecha: (DD/MM/AA)");
		scanf("%d %d %d",&alumno.fecha.dia, &alumno.fecha.mes, &alumno.fecha.anio);

		//escribiendo en el archivo
		//guarda en el archivo separando cada dato por el caracter de salto de linea.
	  	//esto servira para a la hora de lectura o recuperacion de informacion	
		fprintf(stud, "%s %s %d %d %d %d \n",alumno.nombre, alumno.direccion, alumno.curso, alumno.fecha.dia, alumno.fecha.mes, alumno.fecha.anio); 
	}
	
	fclose(stud); 
}


void Buscar()
{
	char nombre[20];
	int ban = 0;

	stud = fopen("academia.dat","r+");
	
	if (stud == NULL) 
	{
		puts("\n error al abrir el archivo");
		return;
	}
	
	printf("\n ingrese el nombre que desea buscar: ");
	scanf("%s",nombre);

	while(feof(stud) == 0)
	{
		alumno = Leer(alumno);

		if(strcmp(alumno.nombre, nombre) == 0)
		{ 
			ban++;
			break;
		}
	}
	
	if(ban)
		ImprimirRegistro(alumno); 
	else
		puts("\n el nombre no se encontro");
}


Estudiantes Leer(Estudiantes alumno)
{
	fscanf(stud, "%s", alumno.nombre);
	fscanf(stud, "%s", alumno.direccion);
	fscanf(stud, "%d", &alumno.curso);
	fscanf(stud, "%d", &alumno.fecha.dia);
	fscanf(stud, "%d", &alumno.fecha.mes);
	fscanf(stud, "%d", &alumno.fecha.anio);

	return alumno;	
}


void ImprimirRegistro(Estudiantes alumno)
{
	puts("\n Mostrando datos de estudiante:");
	printf("\n nombre: %s", alumno.nombre);
	printf("\n direccion: %s", alumno.direccion);
	printf("\n anio que cursa: %d", alumno.curso);
	printf("\n Fecha: |%d/%d/%d|", alumno.fecha.dia, alumno.fecha.mes, alumno.fecha.anio);	
}