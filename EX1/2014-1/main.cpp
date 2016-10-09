#include "funcs.h"

int main(){

	void *cursos, *alumnos, *egresados;

	leerDatos(cursos, alumnos);
	
	//imprimirCursos(cursos); 
	
	//imprimirAlumnos(alumnos);
	
	agregarNotas(alumnos);
	
	imprimirAlumnosNotas(alumnos);
	
	
	separacionDeEgresados(cursos, alumnos, egresados);

	return 0;
}