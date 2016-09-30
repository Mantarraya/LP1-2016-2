
/* Valor Absoluto */

double abs(double num){
	
	return (num >= 0) ? num : -num;
	
}

/* Funcion Coseno */

double cos(double x, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num, signo;
	
	valor1 = 1.0;
	
	num = 2;
	
	valor2 = valor1 - (x*x)/2.0;
	
	termino = (x*x)/2.0;
	signo = 1;
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		termino = (1.0*termino*x*x)/((num+1)*(num+2));
		
		valor2 = valor1 + signo*termino;
		
		signo *= -1;
		
		num += 2;		
	}
	
	return valor2;
	
}

/* Funcion seno */

double sen(double x, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num, signo;
	
	valor1 = x;
	
	num = 3;
	
	termino = (x*x*x)/6.0;
	
	valor2 = valor1 - termino;
	signo = 1;
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		termino = (1.0*termino*x*x)/((num+1)*(num+2));
		
		valor2 = valor1 + signo*termino;
		
		signo *= -1;
		
		num += 2;		
	}
	
	return valor2;
	
}

/* Funcion Exponencial */

double exp(double x, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num;
	
	valor1 = 1;
	
	num = 1;
	
	termino = x*1.0;
	
	valor2 = valor1 + termino;
	
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		termino = (1.0*termino*x)/(num+1);
		
		valor2 = valor1 + termino;

		num += 1;		
	}
	
	return valor2;
	
}

/* Funcion Logaritmica */

double ln(double x, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num;
	
	double factor = (x-1)*1.0/x;
	
	valor1 = factor;
	
	num = 2;
	
	termino = factor*factor;
	
	valor2 = valor1 + termino/2.0;
	
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		termino = (1.0*termino*factor);
		
		valor2 = valor1 + termino*1.0/(num+1);

		num += 1;		
	}
	
	return valor2;
	
}

/* Funcion Potencia */

double pot(double x, double y, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num;
	
	
	valor1 = 1.0;
	
	num = 1;
	
	double factor = y*ln(x, prec)*1.0;
	
	termino = factor;
	
	valor2 = valor1 + termino;
	
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		/* La ecuacion de la potencia esta mal planteada en la hoja, la potencia solo elevaria al numerador */
		termino = (1.0*termino*factor)/(num+1);
		
		valor2 = valor1 + termino;

		num += 1;		
	}
	
	return valor2;
	
}

/* Funcion Senh */

double senh(double x, int prec){
	
	double precision = 1.0;
	
	/* Calculamos la precision */
	
	for (int i = 0; i < prec; i++)
		precision /= 10;
	
	double valor1, valor2, termino;
	int num;
	
	valor1 = x;
	
	num = 3;
	
	termino = (x*x*x)/6.0;
	
	valor2 = valor1 - termino;
	while (abs(valor2-valor1) > precision){
		
		valor1 = valor2;
		
		termino = (1.0*termino*x*x)/((num+1)*(num+2));
		
		valor2 = valor1 + termino;
		
		num += 2;		
	}
	
	return valor2;
	
	
	
}









