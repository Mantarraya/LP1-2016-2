#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


char *buscarNombreLibro(void *libros , char *codigoBusc){
	
	
	void **arrLibros = (void **) libros;
	
	int cont = 0;
	
	while (arrLibros[cont] != NULL){
		
		void **regLibros = (void **) arrLibros[cont];
		
		if (strcmp((char *)regLibros[0], codigoBusc) == 0)
			return (char *)regLibros[1];
		
		cont++;
		
	}
	
	char *frase;
	strcpy(frase, "NO ENCONTRADO");
	return frase;
	
}

double buscarPrecioLibro(void *libros , char *codigoBusc){
	
	
	void **arrLibros = (void **) libros;
	
	int cont = 0;
	
	while (arrLibros[cont] != NULL){
		
		void **regLibros = (void **) arrLibros[cont];
		
		if (strcmp((char *)regLibros[0], codigoBusc) == 0)
			return *(double *)regLibros[2];
		
		cont++;
		
	}
	

	return -1;
	
}

void reporteFinal(void *autores, void *libros){
	
	
	printf("Catalogo de autores\n");
	for (int i = 0; i < 100; i++) printf("=");
	printf("\n");
	
	void **arrAutores = (void **) autores;
	
	for (int i = 0; arrAutores[i]; i++){
	
		void **regAutor = (void **) arrAutores[i];
		
		printf("%02d) %8d %-60s\n", i+1, *(int *) regAutor[0], (char *) regAutor[1]);

		printf("Libros:\n");
		printf("      Codigo    Titulo                                                             Precio\n");
		if (regAutor[2] != NULL){
			
			char **arrLibros = (char **) regAutor[2];
			
			for (int j = 0; arrLibros[j] != NULL; j++){
				
				printf("  %10s    %-60s   %10.2lf\n", arrLibros[j], buscarNombreLibro(libros, arrLibros[j]), 
				                                                   buscarPrecioLibro(libros, arrLibros[j]));
				
				
			}
			
			cout << endl;
			
		}
		
		printf("\n");

	}	
	
}
	
	

