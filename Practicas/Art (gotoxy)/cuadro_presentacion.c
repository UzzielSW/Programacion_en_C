// funciona solo el windows en este caso
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void gotoxy (int,int);

int main ()
{
	int a, b;
	// cuadro
	for (a=2; a < 118; a++)
	{
		gotoxy (a, 1);
		printf ("%c", 205);
		
		gotoxy (a, 28);
		printf ("%c", 205);
		system ("color 3");
	}

	for (b=2; b < 28; b++)
	{
		gotoxy (1, b);
		printf ("%c", 186);
			
		gotoxy (118, b);
		printf ("%c", 186);
		system ("color 6");
	}

	// esquinas
	gotoxy (1, 1);
	printf ("%c", 201);
	
	gotoxy (118, 1);
	printf ("%c", 187);
	
	gotoxy (1, 28);
	printf ("%c", 200);
	
	gotoxy (118, 28);
	printf ("%c", 188);
	system ("color 3");
	
	return (0);
}

void gotoxy (int x , int y)
{  
    HANDLE hcon = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition (hcon, dwPos);
}