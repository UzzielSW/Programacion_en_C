#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float real;
	float imag;
} complejo;

complejo *capturacomplejo(complejo *z);
complejo *sumacomplejo(complejo *z1, complejo *z2);
complejo *restacomplejo(complejo *z1, complejo *z2);
complejo *multicomplejo(complejo *z1, complejo *z2);
complejo *creacomplejo();
void despliegacomplejo(complejo *z);
complejo *conjugado(complejo *z);
void liberamemoria(complejo *z);

complejo *z1, *z2;

int main()
{
	complejo *sum = NULL, *rest = NULL, *mult = NULL, *zconj = NULL;
	int opc;

	do
	{
		system("cls");
		printf("\n\n\t\t  Menu de Opciones");
		printf("\n\n\t 1. Captura 2 numeros complejos");
		printf("\n\n\t 2. desplejar 2 numeros complejos");
		printf("\n\n\t 3. suma 2 numeros complejos");
		printf("\n\n\t 4. resta 2 numeros complejos");
		printf("\n\n\t 5. Multiplicar dos numeros complejos");
		printf("\n\n\t 6. Conjugado de un complejo");
		printf("\n\n\t 7. Liberar memoria");
		printf("\n\n\t 8. Salir");
		printf("\n\n\t Cual opcion desea ?:  ");
		scanf("%d", &opc);
		fflush(stdin);
		switch (opc)
		{
		case 1:
			z1 = creacomplejo();
			z2 = creacomplejo();
			printf("\n\n\t Z1");
			z1 = capturacomplejo(z1);
			printf("\n\n\t Z2");
			z2 = capturacomplejo(z2);
			getchar();
			break;

		case 2:
			printf("\n\n\t Z1");
			despliegacomplejo(z1);
			printf("\n\n\t Z2");
			despliegacomplejo(z2);
			getchar();
			break;

		case 3:
			if (z1 != NULL && z2 != NULL)
			{
				sum = sumacomplejo(z1, z2);
				printf("\n\n\t Z1");
				despliegacomplejo(z1);

				printf("\n\n\t Z2");
				despliegacomplejo(z2);

				printf("\n\n\t suma");
				despliegacomplejo(sum);
			}
			else
				printf("\n\n\t Capture los dos numeros complejos");
			getchar();
			break;
		case 4:
			if (z1 != NULL && z2 != NULL)
			{
				rest = restacomplejo(z1, z2);
				printf("\n\n\t Z1");
				despliegacomplejo(z1);

				printf("\n\n\t Z2");
				despliegacomplejo(z2);

				printf("\n\n\t resta");
				despliegacomplejo(rest);
			}
			else
				printf("\n\n\t Capture los dos numeros complejos");
			getchar();
			break;

		case 5:
			if (z1 != NULL && z2 != NULL)
			{
				mult = multicomplejo(z1, z2);
				printf("\n\n\t Z1");
				despliegacomplejo(z1);

				printf("\n\n\t Z2");
				despliegacomplejo(z2);

				printf("\n\n\t Multiplicacion");
				despliegacomplejo(mult);
			}
			else
				printf("\n\n\t Capture los dos numeros complejos");
			getchar();

			break;

		case 6:
			z1 = creacomplejo();
			printf("\n\t Z1");
			z1 = capturacomplejo(z1);
			printf("\n\t Z1");
			despliegacomplejo(z1);
			zconj = conjugado(z1);
			printf("\n\t z Conjugado: ");
			despliegacomplejo(zconj);
			getchar();
			break;

		case 7:
			if (z1 != NULL && z2 != NULL)
			{

				liberamemoria(z1);
				liberamemoria(z2);
				printf("\n\n\t la memoria esta libre");
			}
			else
				printf("\n\n\t\t\t La lista esta vacia");
			break;
		}
	} while (opc != 8);
	return 0;
}

void *creamemoria(int n)
{
	void *p = (int *)malloc(n);
	if (p == NULL)
	{
		puts("Lo siento no hay memoria disponible");
		getchar();
		exit(1);
	}

	return (p);
}

complejo *creacomplejo()
{
	return (complejo *)creamemoria(sizeof(complejo));
}

complejo *capturacomplejo(complejo *z)
{
	printf("\n Ingrese la parte real:  ");
	scanf("%f", &z->real);
	fflush(stdin);
	printf("\n Ingrese la parte imaginaria:  ");
	scanf("%f", &z->imag);
	fflush(stdin);
	return z;
}

void despliegacomplejo(complejo *z)
{
	if (z->real >= 0 && z->imag >= 0)
		printf("\t %f + %f i", z->real, z->imag);
	else if (z->real > 0 && z->imag < 0)
		printf("\t %f  %f i", z->real, z->imag);
	else if (z->real < 0 && z->imag > 0)
		printf("\t %f + %f i", z->real, z->imag);
	else if (z->real < 0 && z->imag < 0)
		printf("\t %f  %f i", z->real, z->imag);
	else if (z->real == 0)
		printf("\t  %f i", z->imag);
	else if (z->imag == 0)
		printf("\t %f ", z->real);

	return;
}

complejo *sumacomplejo(complejo *z1, complejo *z2)
{
	complejo *suma;
	suma = creacomplejo();
	suma->real = (z1->real + z2->real);
	suma->imag = (z1->imag + z2->imag);
	return (suma);
}

complejo *restacomplejo(complejo *z1, complejo *z2)
{

	complejo *resta;
	resta = creacomplejo();
	resta->real = (z1->real - z2->real);
	resta->imag = (z1->imag - z2->imag);
	return (resta);
}

complejo *multicomplejo(complejo *z1, complejo *z2)
{
	complejo *multi;
	multi = creacomplejo();
	multi->real = (z1->real * z2->real - z1->imag * z2->imag);
	multi->imag = (z1->real * z2->imag + z1->imag * z2->real);
	return (multi);
}

complejo *conjugado(complejo *z)
{
	complejo *conjug;
	conjug = creacomplejo();
	conjug->real = z->real;
	conjug->imag = -z->imag;
	return conjug;
}

void liberamemoria(complejo *z)
{
	free(z);
}