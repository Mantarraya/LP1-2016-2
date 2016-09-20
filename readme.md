# LENGUAJE DE PROGRAMACION 1

### PUNTEROS

#### Operador de dirección (o de referencia)
El operador de dirección (&) devuelve la dirección donde se encuentra el operando

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
