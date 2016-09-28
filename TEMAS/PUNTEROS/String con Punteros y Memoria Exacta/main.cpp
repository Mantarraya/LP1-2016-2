#include <iostream>
#include "curso.h"
using namespace std;

int main(){

	char **codCur;
	double *credCur;
	char **nombCur;

	leerCursos(codCur, credCur, nombCur);
	imprimeCursos(codCur, credCur, nombCur);

	return 0;
}