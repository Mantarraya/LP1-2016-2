#include <iostream>
#define MAX 10
using namespace std;

/* Funciones de la Libreria estatica ordenar.a */

template <typename T>
void swap(T[], int, int);

template <typename T>
int particion(T[], int, int);

template <typename T>
void quickSort(T[], int, int);

template <typename T>
void imprimirArreglo(T[], int);


/* Programa Principal */

int main(){

	/*Arreglo de numeros enteros */

	int numEnteros[MAX] = {5, 2, 4, 1, 3, 10, 8, 6, 9, 7};	

	cout << "Arreglo de enteros" << endl << endl;
	cout << "Arreglo original: " << endl;
	imprimirArreglo(numEnteros, MAX);

	quickSort(numEnteros, 0, MAX-1);

	cout << "Arreglo ordenado: " << endl;
	imprimirArreglo(numEnteros, MAX);

	/* Arreglo de numeros reales */

	double numReales[MAX] = {5.8, 2.9, 1.5, 10.5, 8.2, 7.1, 3.3, 6.2, 4.6, 9.3};	

	cout << endl << "Arreglo de reales" << endl << endl;
	cout << "Arreglo original: " << endl;
	imprimirArreglo(numReales, MAX);

	quickSort(numReales, 0, MAX-1);

	cout << "Arreglo ordenado: " << endl;
	imprimirArreglo(numReales, MAX);

	/* Arreglo de caracteres */

	char palabra[MAX] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};	

	cout << endl << "Arreglo de caracteres" << endl << endl;
	cout << "Arreglo original: " << endl;
	imprimirArreglo(palabra, MAX);

	quickSort(palabra, 0, MAX-1);

	cout << "Arreglo ordenado: " << endl;
	imprimirArreglo(palabra, MAX);

	return 0;

}