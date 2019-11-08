/*
	1. Hacer una estructura llamada corredor, en la cual se tendran los
	siguientes miembros: Nombre, edad, sexo, club, pedir datos al usuario 
	para un corredor, y asignarle una categoria de competicion:
	- Juvenil <= 18 años
	- Señor <= 40 años
	- Veterano > 40 años
	posteriormente imprimir todos los datos del corredor, incluida su
	categoria de competicion
*/
#include<stdio.h>
#include<stdlib.h>

struct Corredor
{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
	char categoria[20];
};

int main()
{
	Corredor corredor1;
	int val = 1;

	printf("Digite su nombre: ");
	gets(corredor1.nombre);

	printf("Digite su edad: ");
	scanf("%d",&corredor1.edad);
	fflush(stdin);

	printf("Digite su sexo: ");
	gets(corredor1.sexo);

	printf("Digite su club: ");
	gets(corredor1.club);
	
	if((corredor1.edad > 5) && (corredor1.edad <= 18))
		strcpy(corredor1.categoria,"Juvenil"); //categoria = Juvenil
	else if(corredor1.edad <= 40)
		strcpy(corredor1.categoria,"Senior"); //categoria = Señor
	else if (corredor1.edad <= 90)
		strcpy(corredor1.categoria,"Veterano");
	else
		val = 0;

	if (val)
	{
		printf("\n\nSu categoria es: %s",corredor1.categoria);
		printf("\nSu nombre es: %s",corredor1.nombre);
		printf("\nSu edad es: %d",corredor1.edad);
		printf("\nSu sexo es: %s",corredor1.sexo);
		printf("\nSu club es: %s\n",corredor1.club);
	}else
		puts("Datos del corredor invalido");
	
	system("pause");
	return 0;
}  