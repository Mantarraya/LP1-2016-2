#include <iostream>
#include <cstdio>
#include "funcs.h"

using namespace std;


void *leerCursos();
double promedio(void *);

int main(){
	
	void *alumnos;

	int anio, ciclo;
	
	leerAlumnos(alumnos, anio, ciclo);
	
	
	reporte(alumnos, anio, ciclo);
	
	
	
	
	
	
	return 0;
}