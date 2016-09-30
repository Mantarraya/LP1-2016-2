#include <cstdio>

double cos(double, int);
double sen(double, int);
double exp(double, int);
double ln(double, int);
double pot(double, double, int);
double senh(double, int);


double obtenerValor(char c){
	
	double x, y;
	int prec;
	
	double resul;
	if (c == 's'){
		scanf("%lf %d", &x, &prec);
		resul = sen(x, prec);
	}
	else if (c == 'c'){
		scanf("%lf %d", &x, &prec);
		resul = cos(x, prec);
	}
	else if (c == 'l'){
		scanf("%lf %d", &x, &prec);
		resul = ln(x, prec);
	}
	else if (c == 'p'){
		scanf("%lf %lf %d", &x, &y, &prec);
		resul = pot(x, y, prec);
	}
	else if (c == 'h'){
		scanf("%lf %d", &x, &prec);
		resul = senh(x, prec);	
	}
	else if (c == 'e'){
		scanf("%lf %d", &x, &prec);
		resul = exp(x, prec);	
	}
	return resul;
	
}

double operar(double num1, double num2, char operador){
	
	double res;
	
	if (operador == '+')
		res = num1 + num2;
	else if (operador == '-')
		res = num1-num2;
	else if (operador == 'x')
		res = num1*num2;
	else if (operador == '/')
		res = num1/num2;
	
	return res;
	
}