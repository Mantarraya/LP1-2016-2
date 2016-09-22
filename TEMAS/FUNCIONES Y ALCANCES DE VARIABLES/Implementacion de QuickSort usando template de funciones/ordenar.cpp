#include <iostream>
using namespace std;

template <typename T>
void swap(T A[], int i, int j){
	T aux;
	aux = A[i];
	A[i] = A[j];
	A[j] = aux;
}

template void swap(double[], int, int);
template void swap(char[], int, int);
template void swap(int[], int, int);


template <typename T>
int particion(T A[], int ini, int fin){

	T pivote = A[fin];

	int i = ini - 1;

	for (int j = ini; j < fin; j++){
		if (A[j] < pivote){
			i++;
			swap(A, i, j);
		}
	}

	swap(A, i+1, fin);

	return (i + 1);

}

template int particion(double[], int, int);
template int particion(char[], int, int);
template int particion(int[], int, int);


template <typename T>
void quickSort(T A[], int ini, int fin){

	if (ini < fin){

		int pivote = particion(A, ini, fin);

		quickSort(A, ini, pivote-1);
		quickSort(A, pivote+1, fin);

	}


}

template void quickSort(double[], int, int);
template void quickSort(char[], int, int);
template void quickSort(int[], int, int);


template <typename T>
void imprimirArreglo(T A[], int n){
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

template void imprimirArreglo(double[], int);
template void imprimirArreglo(char[], int);
template void imprimirArreglo(int[], int);
