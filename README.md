# Programación en C || Programación ATS

Todos los programas vistos en el curso, tanto los practicos hechos en el curso como los dejados de tarea.
Estan tanto los que salen en los videos actuales (hasta video 39) como tambien los demas que estaban antes.

## Estructura del Curso del lenguaje C

1. Introducción
2. Variables, Comentarios
3. Entrada y Salida de datos
4. Operadores y Expresiones
5. Estructura de Selección (if, else, switch)
6. Estructura de Control (Ciclos [for, while, do/while])
7. Funciones
8. Arreglos (vectores y matrices)
9. Estructuras y Uniones
10. Punteros
11. Asignación Dinámica de Memoria
12. Manejo de Cadenas
13. Manejo de Archivos
14. Listas Enlazadas, Pilas y Colas
15. Arboles

## Palabras clave reservadas de C

| <!-- --> | <!-- --> | <!-- --> | <!-- --> |
| :------: | :------: | :------: | :------: |
|   auto   |   else   |   long   |  switch  |
|  break   |   enum   | register | typedef  |
|   case   |  extern  |  return  |  union   |
|   char   |  float   |  short   | unsigned |
|  const   |   for    |  signed  |   void   |
| continue |   goto   |  sizeof  | volatile |
| default  |    if    |  static  |  while   |
|    do    |   int    |  struct  | \_Packed |
|  double  |          |          |          |

## Librerias

```c++
#include <stdio.h> //libreria estandar de c
#include <iostream> //libreria estandar de c++
#include <stdlib.h> //trabajndo con funciones del sistema
#include <fstream> //manejo de archivos
#include <math.h> //funciones matematicas
#include <string> //manejo de cadenas
#include <ctype.h> //manejo de caracteres
#include <vector> //coleccion STL
#include <list> //coleccion STL
#include <stack> //coleccion STL
#include <queue> //coleccion STL
#include <algorithn> //Funciones para colecciones STL
#include <iterator> //iteradorers de colecciones
#include <stdexcept> //manejo de excepciones
#include <iomanip> //funciones para acomodar salida por consola
#include <stddef> //tipo size_t
```

## Prioridad de los Operadores

1. Paréntesis ()
2. Potencia
3. mul \* , div / , mod % , not !
4. suma + , resta - , and &
5. '> , < , ==, >=, <=, !=, or ||

## Correcciones

1. Para todos los programas que manejen cadenas y se este usando la funcion gets() para la lectura, ahora se debe usar la siguiente funcion con el siguiente formato:
   `fgets(cadena, sizeof(cadena), stdin);`

2. Tambien tener en cuenta que varias funciones puede que solo funcionen en Windows o esten actualizadas por otras. En version de Dev-C++ deberia funcionar. Mientras que para compiladores mas actuales puede que den error. Sin embargo la logica es la misma solo es cambiar la sintaxis.

## Referencias y Ayuda
[cplusplus](https://cplusplus.com/reference/algorithm/)
