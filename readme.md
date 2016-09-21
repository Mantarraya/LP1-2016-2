# LENGUAJE DE PROGRAMACIÓN 1

### PUNTEROS

#### Operador de dirección (o de referencia)
El operador de dirección (&) devuelve la dirección en donde se encuentra el operando

```cpp
#include <iostream>
using namespace std;

int main(){

	int a = 10;

	cout << "El valor de a es " << a << endl;
	cout << "La direccion de a es " << &a << endl;

	return 0;
}

```

```console 
El valor de a es 10
La direccion de a es 0x61ff1c

```

#### Operador de indirección (o de desreferencia)
El operador de indirección (*) devuelve el valor del objeto a que apunta.

```cpp
#include <iostream>
using namespace std;

int main(){

	int a = 7;
	int *ptr; /* Declaramos el puntero */

	ptr = &a; /* Le pasamos la dirección de a */

	cout << "El valor de a es " << a << endl;
	cout << "El valor de &a es" << &a << endl;

	cout << endl;

	/* Imprimimos la direccion del puntero */
	cout << "El valor de ptr es " << ptr << endl;
	/* Imprimimos el valor del objeto a donde apunta */
	cout << "El valor de *ptr es " << *ptr << endl;

	return 0;
}

```
```console
El valor de a es 7
El valor de &a es0x61ff18

El valor de ptr es 0x61ff18
El valor de *ptr es 7
```

#### Aritmética de punteros
A un puntero se le puede aplicar cualquier clase de operación de suma o resta (incluyendo los incrementos y decrementos). 

```cpp
#include <iostream>
#include <cstdio>
#define MAX 10
using namespace std;

int main(){
	
	int *ptr; /* Puntero */
	int A[MAX] = {5, 8, 11, 13, 18, 20, 24, 25, 30, 40}; /* Arreglo */
	
	/* Inicializamos el valor del puntero */
	ptr = A; /* ptr = &A[0] */
	
	/* Imprimimos el arreglo inicial */
	cout << "Arreglo inicial: " << endl;
	for (int i = 0; i < MAX;  i++)
		printf("%4d", A[i]);
	
	printf("\n\n");
	
	/* Imprimimos los valores de los objetos hacia donde apuntan */
	cout << "Valores de los objetos en las direcciones hacia donde apuntan *ptr: " << endl;
	for (int i = 0; i < MAX; i++)
		printf("%4d", *(ptr+i));			
	
	/* Modificamos los valores en las direcciones de memoria del puntero */
	for (int i = 0; i < MAX; i++){
		*ptr *=5;
		(ptr)++;
	}

	printf("\n\n");
	
	/* Imprimimos el arreglo inicial */
	cout << "Arreglo Final (x5): " << endl;
	for (int i = 0; i < MAX;  i++)
		printf("%4d", A[i]);

	printf("\n");
	
	return 0;
}
```
```console
Arreglo inicial: 
   5   8  11  13  18  20  24  25  30  40

Valores de los objetos en las direcciones hacia donde apuntan *ptr: 
   5   8  11  13  18  20  24  25  30  40

Arreglo Final (x5): 
  25  40  55  65  90 100 120 125 150 200

```

