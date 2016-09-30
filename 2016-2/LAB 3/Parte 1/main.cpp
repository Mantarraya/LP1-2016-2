#include <iostream>
#include <cstdio>
#include "mathLP1.h"
#define PRECISION 5
using namespace std;

int main(){
	
	printf("COS 60 = %.5lf\n", cos(3.1415/3, PRECISION));
	
	printf("SEN 30 = %.5lf\n", sen(3.1415/6, PRECISION));
	
	printf("EXP 1 = %.5lf\n", exp(1, PRECISION));
	
	printf("LN 10 = %.5lf\n", ln(10, PRECISION));
	
	printf("POT 5 a la 2 = %.5lf\n", pot(5, 2, PRECISION));
	
	printf("SENH 1 = %.5lf\n", senh(2, PRECISION));
	
	return 0;
}