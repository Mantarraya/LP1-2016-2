### PUNTEROS GENÉRICOS
Un puntero genérico o un *puntero void* permite apuntar a cualquier tipo de dato.
A comparación de un puntero a un tipo de dato en específico, su impresión requiere de una conversión explícita (cast) 
```cpp
#include <iostream>
using namespace std;

int main(){
	
	/* Declaracion de un puntero a void */
	void *ptrVoid;	
	
	int numero = 10;
	
	/* Inicializamos el puntero void */
	ptrVoid = &numero;
	
	cout << "Direcciones: " << endl;
	cout << "   &numero:  " << &numero << endl;
	cout << "   ptrVoid:  " << ptrVoid << endl;
	
	cout << endl << "Valores: " << endl;
	cout << "   numero:   " << numero << endl;
	cout << "   *(int*)ptrVoid: " << *(int*)ptrVoid << endl;
	
	return 0;
}
```
Salida:
```console 
Direcciones: 
   &numero:  0x28ff28
   ptrVoid:  0x28ff28

Valores: 
   numero:         10
   *(int*)ptrVoid: 10

```

Al aplicar un puntero void a un arreglo, se debe tomar en cuenta la precedencia de los paréntesis.


```cpp
#include <iostream>
#include <cstdio>
#define MAX 10
using namespace std;

int main(){
	
	/* Declaracion de un puntero a void */
	void *ptrVoid;	
	
	double ArrFlotantes[MAX] = {4.2, 3.7, 2.4, 1.1, 5.1, 6.4, 7.9, 9.2, 8.7, 10.2};

	/* Inicializacion del puntero a void */
	ptrVoid = ArrFlotantes;

	/* Recorremos el ptrVoid para la impresion */
	for (int i = 0; i < MAX; i++)	
		cout << "((double*)ptrVoid)[" << i << "]" << " = " << ((double*)ptrVoid)[i] << endl;
		
	return 0;
}
```
Salida:
```console 
((double*)ptrVoid)[0] = 4.2
((double*)ptrVoid)[1] = 3.7
((double*)ptrVoid)[2] = 2.4
((double*)ptrVoid)[3] = 1.1
((double*)ptrVoid)[4] = 5.1
((double*)ptrVoid)[5] = 6.4
((double*)ptrVoid)[6] = 7.9
((double*)ptrVoid)[7] = 9.2
((double*)ptrVoid)[8] = 8.7
((double*)ptrVoid)[9] = 10.2

```
