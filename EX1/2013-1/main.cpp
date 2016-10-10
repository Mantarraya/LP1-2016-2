#include "funcs.h"

int main(){
	
	void *articulos, *movimientos;
	
	leerArticulos(articulos);	
	
	//ordenarArticulos(articulos);
	
	
	//imprimirArticulos(articulos);
	
	leeMovimientos(movimientos, articulos);
	
	imprimirMovimientos(movimientos, articulos);
	
	return 0;
}