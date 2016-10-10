#include "lecturaYPrueba.h"
#include "reporte.h"

int main(){
	
	void *autores, *libros;
	
	leerAutores(autores);
	
	leerLibrosYCompletarAutores(libros, autores);
	
	reporteFinal(autores, libros);
	
	return 0;
}