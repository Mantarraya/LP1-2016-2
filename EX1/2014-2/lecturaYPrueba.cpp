#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_CAR_LIN 1500
#define MAX_AUTORES 1000
#define MAX_PAL 1000
#define MAX_LIBROS 2000
#define INCREMENTO 5

void separarPalabras(char *linea, char **palabras, int &nPal){
	
	nPal = 0;
	
	if (!isblank(linea[0])){
		
		palabras[0] = linea;
		nPal++;
		
	}
	
	for (int i = 1; linea[i]; i++){
		
		if (!isblank(linea[i]) and (isblank(linea[i-1]) or linea[i-1] == 0)){
			
			palabras[nPal] = &linea[i];
			nPal++;			
			
		}
		
		if (!isblank(linea[i]) and isblank(linea[i+1])){
			
			linea[i+1] = 0;
			i++;
			
		}		
		
	}
	
}

void obtenerNombre(char linea[], char *&nombAutor){
	
	char *palabras[MAX_PAL];
	int nPal;
	
	separarPalabras(linea, palabras, nPal);	

	char nombAux[MAX_CAR_LIN];
	
	strcpy(nombAux, palabras[0]);
	
	for (int i = 1; i < nPal; i++){
		
		strcat(nombAux, " ");
		strcat(nombAux, palabras[i]);
		
	}
	
	nombAutor = new char[strlen(nombAux)+1];
	
	strcpy(nombAutor, nombAux);
	
}

void *colocarDatos(int codAutor, char *nombAutor){
	
	void **regAutores = new void*[3];
	
	int *ptrCodAutor = new int;
	*ptrCodAutor = codAutor;
			
	regAutores[0] = ptrCodAutor;
	regAutores[1] = nombAutor;
	regAutores[2] = NULL;
	
	return regAutores;
	
}

void *memoriaExacta(void *auxAutores[], int numAutores){
	
	void **autores = new void*[numAutores+1];
	
	for (int i = 0; i < numAutores; i++)
		autores[i] = auxAutores[i];
	
	autores[numAutores] = NULL;
	
	return autores;
	
}

void leerAutores(void *&autores){
	
	char linea[MAX_CAR_LIN];
	char *nombAutor;
	int codAutor;
	
	void *auxAutores[MAX_AUTORES];
	
	int numAutores = 0;
	
	while (scanf("%d", &codAutor) == 1){
		
		cin.getline(linea, MAX_CAR_LIN, '\n');
		obtenerNombre(linea, nombAutor);
		
		auxAutores[numAutores] = colocarDatos(codAutor, nombAutor);
		
		numAutores++;		
		
	}
	
	autores = memoriaExacta(auxAutores, numAutores);
	
}

void obtenerDatosLibros(char linea[], char *&codLibro, char *&nombLibro, double &precLibro, int &codAutor){
	
	char *palabras[MAX_PAL];
	int nPal;
	
	separarPalabras(linea, palabras, nPal);
	
	/* Codigo de libro */
	codLibro = new char[strlen(palabras[0]) + 1];
	strcpy(codLibro, palabras[0]);
	
	/* Precio */
	precLibro = atof(palabras[nPal-2]);
	
	/* Codigo del autor */
	codAutor = atoi(palabras[nPal-1]);
	
	/*Nombre del libro */
	
	char nombAux[MAX_CAR_LIN];
	strcpy(nombAux, palabras[1]);
	
	for (int i = 2; i < nPal-2; i++){
		strcat(nombAux, " ");
		strcat(nombAux, palabras[i]);
	}
	
	nombLibro = new char[strlen(nombAux) + 1];
	strcpy(nombLibro, nombAux);
	
}


void *colocarDatosLibro(char *codLibro, char *nombLibro, double precLibro){
	
	void **regLibros = new void*[3];
	
	double *ptrPrecLibro = new double;
	*ptrPrecLibro = precLibro;
	
	regLibros[0] = codLibro;
	regLibros[1] = nombLibro;
	regLibros[2] = ptrPrecLibro;
	
	return regLibros;	
	
}
	
int buscarPosAutor(void *autores, int codAutorBusc){
	
	void **arrAutores = (void **) autores;
	
	for (int i = 0; arrAutores[i]; i++){
		
		void **regAutores = (void **) arrAutores[i];
		
		if ( *(int *)regAutores[0] == codAutorBusc )
			return i;		
		
	}
	
	return -1;
	
}

void inicializarRegistro(void *&autor){
	
	void **regAutor = (void **) autor;
	
	char **arrCodLibro = new char*[INCREMENTO];
	
	for (int i = 0; i < INCREMENTO; i++)
		arrCodLibro[i] = NULL;

	regAutor[2] = arrCodLibro;
	
	autor = regAutor;	
	
}

int calcularCantLibros(char **libros){
	
	int pos = 0;
	
	while (libros[pos] != NULL)
		pos++;
	
	return pos;
	
	
}

void adjuntarLibro(void *&autor, int cantLibros, char *codLibro){
	
	void **regAutor = (void **) autor;
	
	char **libros = (char **) regAutor[2];
	
	libros[cantLibros] = codLibro;
	
	regAutor[2] = libros;
	
	autor = regAutor;
	
}

void incrementarTamanio(void *&autor, int cantLibros){
	
	void **regAutor = (void **) autor;
	
	char **auxArrLibros = new char*[cantLibros + INCREMENTO+1];
	
	char **libros = (char **) regAutor[2];

	for (int i = 0; i < cantLibros; i++)
		auxArrLibros[i] = libros[i];
	
	for (int i = 0; i < INCREMENTO+1; i++)
		auxArrLibros[cantLibros+i] = NULL;
	
	delete [] libros;
	
	regAutor[2] = auxArrLibros;
	
	autor = regAutor;
	
}

void colocarLibroAutor(void *&autores, int posAutor, char *codLibro){
	
	void **arrAutores = (void **) autores;
	void **regAutores = (void **) arrAutores[posAutor];
	
	int cantLibros;
	
	if (regAutores[2] == NULL)
		inicializarRegistro(arrAutores[posAutor]);
		
	char **ArrLibros = (char **) regAutores[2];
	cantLibros = calcularCantLibros(ArrLibros);
		
	if (cantLibros % INCREMENTO == 0)
		incrementarTamanio(arrAutores[posAutor], cantLibros);

	adjuntarLibro(arrAutores[posAutor], cantLibros, codLibro);	
	
}
	
void leerLibrosYCompletarAutores(void *&libros, void *&autores){
	
	char linea[MAX_CAR_LIN];
	char *codLibro, *nombLibro;
	double precLibro;
	int codAutor, posAutor;
	
	void *auxLibros[MAX_LIBROS];
	
	int numLibros = 0;
	while (cin.getline(linea, MAX_CAR_LIN, '\n')){
		
		obtenerDatosLibros(linea, codLibro, nombLibro, precLibro, codAutor);
		
		auxLibros[numLibros] = colocarDatosLibro(codLibro, nombLibro, precLibro);
		
		posAutor = buscarPosAutor(autores, codAutor);
	
		if (posAutor != -1)
			colocarLibroAutor(autores, posAutor, codLibro);
	
		numLibros++;
				
	}
	
	libros = memoriaExacta(auxLibros, numLibros);	
	
}
