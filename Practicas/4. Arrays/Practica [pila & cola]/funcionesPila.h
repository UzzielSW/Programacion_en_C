#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

struct DatosMercancia
{
	string nombre;
	int cantidad; 
	float precio;
};

typedef DatosMercancia Pila;

//funciones pila
int Pone_Pila(Pila[], int);
int Quita_Pila(Pila[], int);
void Mostrar_Mercancia(Pila);

int Menu_Pila(Pila Mercancias[MAX], int TOPE)	// (1.1)
{
	int opc;

	//Menu Pila
	do
	{	system("cls");
		cout<<"\n .:Inventario de Mercancias:."<<"\t\t\tPila["<<TOPE+1<<"]"
			<<"\n\n 1.Insertar Mercancia"
			<<"\n 2.Quitar Mercancia"
			<<"\n 3.Mostrar Mercancias disponibles"
			<<"\n 4.Back"
			<<"\n\n >> ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				TOPE = Pone_Pila(Mercancias, TOPE);
			break;

			case 2:
				TOPE = Quita_Pila(Mercancias, TOPE);
			break;

			case 3:
				if(TOPE != -1){
					for(int i = TOPE; i >= 0; i--)
						Mostrar_Mercancia(Mercancias[i]);
				}else
					cout<<"\n no hay mercancias disponibles";	
			break;

			default: opc = 4; break;
				
		}getch();
	} while (opc != 4);

return TOPE;
}



int Pone_Pila(Pila Mercancias[MAX], int TOPE) // 1.1.1
{
	bool Pila_llena(int);
	bool band = Pila_llena(TOPE);
	Pila Cargar_Datos_Mercancia(void);

	if(band)
		cout<<"\n Desbordamiento - Pila llena";
	else{
		TOPE+=1;
		Mercancias[TOPE] = Cargar_Datos_Mercancia();
	}

return TOPE;
}

bool Pila_llena(int TOPE)
{	
	return (TOPE == MAX-1)? true : false;
}



Pila Cargar_Datos_Mercancia(void)
{
	Pila mercancia;
	
	system("cls");
	cout<<"\n [+] Ingrese nombre de la mercancia: ";
	fflush(stdin);
	getline(cin,mercancia.nombre);

	cout<<" [+] cantidad: ";
	fflush(stdin);
	cin>>mercancia.cantidad;

	cout<<" [+] precio: ";
	cin>>mercancia.precio;
	
return mercancia;
}



int Quita_Pila(Pila Mercancias[MAX], int TOPE) // 1.1.2
{
	bool PilaVacia(int);
	bool band = PilaVacia(TOPE);

	if(band)
		cout<<"\n Subdesbordarniento - Pila vacia";
	else{	
		Pila aux;
		aux = Mercancias[TOPE];
		TOPE--;
		
		cout<<"\n Sacando Mercancia: ";
		Mostrar_Mercancia(aux);
	}

return TOPE;
}

bool PilaVacia(int TOPE)
{
	return (TOPE == -1)? true : false;
}



void Mostrar_Mercancia(Pila aux) // 1.1.3
{
	cout<<"\n\n Mercancia: "<<aux.nombre
		<<"\n Cantidad: "<<aux.cantidad
		<<"\n Precio: "<<aux.precio
		<<"\n___________________________";
}


#endif