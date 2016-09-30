#include <iostream>
#include <cstdio>
#include "auxiliar.h"
using namespace std;

double cos(double, int);
double sen(double, int);
double exp(double, int);
double ln(double, int);
double pot(double, double, int);
double senh(double, int);



int main(){
	
	char c;
	double valor, precision, x, y, angulo;
	
	int tipo;
	
	double total = 0;
	
	double num1, num2;
	char operador;
	
	int nLin = 0;
	
	while (scanf(" %[scelph]c", &c) == 1){
		
		nLin++;
		
		num1 = obtenerValor(c);
		
		while (scanf(" %[+-/x]c", &operador) == 1){
			
			
			while ( (c=getchar() ) == ' ');
			
			num2 = obtenerValor(c);
			
			num1 = operar(num1, num2, operador);			
			
		}	
		
		printf("Resultado N %d = %10.4lf\n", nLin, num1);
		
	}
	
	return 0;
	
}