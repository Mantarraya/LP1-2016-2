/* auxiliar.cpp */

#include <cstdio>
#include <cctype>
#define MAX_LIN 120
#define MAX_CAR 40

void imprimirDobleLinea(){
	for (int i = 0; i < MAX_LIN; i++)
		printf("=");
	printf("\n");
}

void imprimirLinea(){
	for (int i = 0; i < MAX_LIN; i++)
		printf("-");
	printf("\n");
}

void imprimirEspacios(int n){
	for (int i = 0; i < n; i++)
		printf(" ");
}

int imprimirSubCabecera(){

	char c;
	int numLetra;

	/* Verificamos que despues de haber leido la cantidad de agua llovida no haya un caracter fin de archivo */
	while ((c=getchar()) == ' ');
	if (c == EOF)
		return 0;

	imprimirDobleLinea();
	printf("%s%40s%50s\n","ESTACION", "CIUDAD", "DEPARTAMENTO");
	imprimirLinea();

	/* Imprimir nombre de la estacion en mayuscula */
	putchar(toupper(c));
	numLetra = 0;
	while (  (c=getchar()) != ',' ){
		numLetra++;
		putchar(toupper(c));
	}

	imprimirEspacios(MAX_CAR - numLetra);

	/* Imprimir nombre de la ciudad en mayuscula */
	numLetra = 0;
	while (  (c=getchar()) != ',' ){
		numLetra++;
		putchar(toupper(c));
	}

	imprimirEspacios(MAX_CAR - numLetra);

	/* Imprimir nombre del departamento en mayuscula */
	numLetra = 0;
	while (  (c=getchar()) != ':' ){
		numLetra++;
		putchar(toupper(c));
	}

	imprimirEspacios(MAX_CAR - numLetra);

	printf("\n");

	imprimirLinea();
	printf("%10s%25s%25s%25s%25s\n","Fecha", "Cantidad", "Tiempo total", "Total llovido", "Promedio");
	imprimirLinea();

	return 1;

}

void imprimirCabecera(){

	imprimirDobleLinea();
	printf("%70s\n","INFORME DE PRECIPITACIONES");

}

int calcularTiempo(int horaIni, int minIni, int segIni, int horaFin, int minFin, int segFin){

	int tiempoIni = horaIni*3600 + minIni*60 + segIni;
	int tiempoFin = horaFin*3600 + minFin*60 + segFin;

	return (tiempoFin - tiempoIni);

}

void imprimirDatosFecha(int diaAnt, int mesAnt, int anioAnt, int cantFecha, int tiempoSegTotal, double totalLovido){

	int hora = tiempoSegTotal/3600;
	int min = tiempoSegTotal%3600/60;
	int seg = tiempoSegTotal%3600%60;

	double promedio = totalLovido*60.0/tiempoSegTotal;

	printf("  %02d/%02d/%04d %19d %16s %02d:%02d:%02d %22.2lf %22.2lf mm/min\n", diaAnt, mesAnt, anioAnt, cantFecha, " ", hora, min, seg, totalLovido, promedio);

}

void imprimirResumen(int diaIni, int mesIni, int anioIni, int diaFin, int mesFin, int anioFin, int cantTotalReg, int cantDiasReg, int tiempoTotaLluvia, double totalLovidoPeriodo){

	imprimirLinea();
	printf("   Resumen:\n");
	printf("       Fecha Inicial: %02d/%02d/%04d       Fecha final: %02d/%02d/%04d\n", diaIni, mesIni, anioIni, diaFin, mesFin, anioFin);
	printf("       Cantidad total de registros: %14d\n", cantTotalReg);
	printf("       Cantidad de dias registrados: %13d\n", cantDiasReg);

	int hora = tiempoTotaLluvia/3600;
	int min = tiempoTotaLluvia%3600/60;
	int seg = tiempoTotaLluvia%3600%60;

	printf("       Tiempo total de lluvia:            %02d:%02d:%02d\n", hora, min, seg);
	printf("       Total llovido en el periodo: %14.2lf\n", totalLovidoPeriodo);
}