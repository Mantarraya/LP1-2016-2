#ifndef CURSO_H
#define	CURSO_H

void leerCursos(char **&, double *&, char **&);

void separarPalabras(char *, char **, int &);

void separarDatos(char[], char *&, double &, char *&);

void imprimeCursos(char **, double *, char **);

double *memoriaExacta(char* , int);

#endif