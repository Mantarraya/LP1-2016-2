#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void inicializarLetras(char *&);

void inicializarPalabras(char ***&);

void inicializarEnteros(int *&);

void inicializarFlotantes(double *&);

void leerListaCar(char [], char [], int &);

void convertirMayuscula(char []);

int verificarTipo(char []);

template <typename T>
void insertarOrdenado(T [], int &, T);

void insertarOrdenadoPalabra(char **, int &, char *);

void imprimirPalabras(char ***);

void imprimirEnteros(int *);

void imprimirFlotantes(double *);

#endif