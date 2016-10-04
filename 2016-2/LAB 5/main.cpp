#include <iostream>
#include "diccionario.h"
using namespace std;

int main(){
    
    char *letras, ***palabras;
    int *valoresEnteros;
    double *valoresDePuntoFlotante;
    
    crearDiccionario(letras, palabras, valoresEnteros, valoresDePuntoFlotante);
    reporte(letras, palabras, valoresEnteros, valoresDePuntoFlotante);
    
    return 0;
}