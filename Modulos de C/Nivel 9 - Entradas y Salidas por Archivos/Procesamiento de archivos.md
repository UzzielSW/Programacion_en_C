# Procesamiento de archivos:
 
Las actividades principales son: apertura y cierre del archivo, creacion de archivo y procesamiento.


## Apertura y Cierre de archivos: 
	
Los archivos son tipo secuenciales, es decir los datos se archivan y se recuperan en forma secuencial. 
Antes de pensar en abrir un archivo, debe reservar el espacio donde se va a encontrar la informacion. 
Esto se realiza a traves de la declaracion de un area y un apuntador hacia esa area. 
Para ello se realiza lo siguiente:

`FILE *apunta`

El archivo debe abrirse antes de utilizarlo, al igual que los demas lenguajes de programacion, 
la diferencia es que C permite abrir el archivo solo de lectura, solo de escritura o si desea hacer una lectura escrita y se realiza con la sentencia fopen. 

Si lo relacionamos con el anterior podemos utilzar la sentencia.

`apunta = fopen(nda, tipo-archivo);`
	
* **nda**(nombre del archivo)
	> es una cadena que indica el nombre real del archivo o la localizacion del archivo.

* **tipo-archivo**
	es un codigo que indica el tipo de archivo, si es de entrada solo o mas de salida: 
	* **r** es solo lectura, 
	* **w** es solo escritura, 
	* **a** es para adicionar informacion, 
	* **r+** para lectura escrita, 
	* **w+** uno nuevo de lectura escrita,
	* **a+** es para leer y añadir.

ejemplo: `apunta = fopen("cuenta.txt","r");`

para cerrar el archivo solo se utilisa la sentencia `fclose()`, 
en el caso anterior se cerraria asi: `fclose(apunta);`

## Creacion de registros en un archivo 

> Los archivos se crean si no existen y 
se adicionan datos o podemos llamarlos registros, cuando ya existen los archivos. Para ello puede utilizar la funcion fputs, fgets, para escribir y leer respectivamente cadenas de caracteres dentro del archivo o mas bien, si es un dato compuesto o estructura, puede utilizar fscanf, fprintf, para leer y escribir registros(estructuras).