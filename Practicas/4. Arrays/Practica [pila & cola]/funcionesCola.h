#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H 

struct DatosClientes
{
	string nombre;
	float total;
};

typedef DatosClientes Cola;

//funciones Cola
int Pone_Cola(Cola[], int*, int);
int Quitar_Cola(Cola[], int, int*);
void Mostrar_Clientes(Cola);

void Menu_Cola(Cola Clientes[MAX], int *frente, int *final) // (1.2)
{
	int opc;
	int FRENTE = *frente, FINAL = *final;

	//Menu Cola
	do
	{	system("cls");
		cout<<"\n .: Menu de Caja :."
			<<"\n\n 1.Insertar Datos de los Clientes"
			<<"\n 2.Quitar Datos de los Clientes"
			<<"\n 3.Mostrar Clientes"
			<<"\n 4.Back"
			<<"\n\n >> ";
		cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				FINAL = Pone_Cola(Clientes, &FRENTE, FINAL);
			break;

			case 2:
				FRENTE = Quitar_Cola(Clientes, FRENTE, &FINAL);
			break;

			case 3:
				if(FINAL != -1){
					for(int i = FRENTE; i <= FINAL; i++)
						Mostrar_Clientes(Clientes[i]);
				}else
					cout<<"\n no hay clientes en lista";	
			break;

			default: opc = 4; break;
		}getch();
	} while (opc != 4);

	// actualizando FRENTE y FINAL del menu principal
	*frente = FRENTE;
	*final = FINAL;
}


int Pone_Cola(Cola Clientes[MAX], int *FRENTE, int FINAL) // 1.2.1 
{
	bool Cola_llena(int);
	bool band = Cola_llena(FINAL);
	Cola Cargar_Datos_Cola(void);

	if(band)
		cout<<"\n Desbordamiento - Cola llena";
	else{
		FINAL+=1;
		Clientes[FINAL] = Cargar_Datos_Cola();
		if(FINAL == 0)
			*FRENTE = 0;
	}
	
return FINAL;
}

bool Cola_llena(int FINAL)
{
	return (FINAL == MAX-1)? true : false;
}

Cola Cargar_Datos_Cola(void)
{
	Cola Cliente;

	fflush(stdin);
	cout<<"\n [+] ingrese nombre del Cliente: ";
	getline(cin,Cliente.nombre);
	
	fflush(stdin);
	cout<<" [+] total a pagar: ";
	cin>>Cliente.total;
	
return Cliente;
}


int Quitar_Cola(Cola Clientes[MAX], int FRENTE, int *FINAL) // 1.2.2 
{
	bool Cola_Vacia(int);
	bool band = Cola_Vacia(FRENTE);

	if(band)
		cout<<"\n Subdesbordarniento - Cola vacia";
	else{	
		Cola aux;
		aux = Clientes[FRENTE];
		
		if(FRENTE == *FINAL)
			FRENTE = *FINAL = -1;
		else
			FRENTE+=1;

		cout<<"\n Cliente Eliminado: ";
		Mostrar_Clientes(aux);
	}

return FRENTE;
}

bool Cola_Vacia(int FRENTE)
{
	return (FRENTE == -1)? true : false;
}


void Mostrar_Clientes(Cola aux) // 1.2.3
{
	cout<<"\n\n Cliente: "<<aux.nombre
		<<"\n Total: "<<aux.total
		<<"\n___________________________";
}


#endif
