#include <cstdio>
#include "auxiliar.h"
#define MAX_LIN 120
#define MAX_CAR 40

int main(){	

	int diaAnt, mesAnt, anioAnt, dia, mes, anio, horaIni, minIni, segIni, horaFin, minFin, segFin;
	int hayFecha, tiempoSeg, cantFecha, tiempoSegTotal, diaIni, mesIni, anioIni, cantTotalReg, cantDiasReg;
	double cantidadAgua, totalLovido, totalLovidoPeriodo, tiempoTotaLluvia;

	imprimirCabecera();
	
	while (	imprimirSubCabecera() == 1){

		/* Inicializamos variables del reporte de la fecha */
		diaAnt = mesAnt = anioAnt = 0;
		cantFecha = 1;
		tiempoSegTotal = 0;
		totalLovido = 0;

		/* Inicializamos variables del resumen */
		cantTotalReg = 0;
		cantDiasReg = 0;
		tiempoTotaLluvia = 0;
		totalLovidoPeriodo = 0;

		/* Leemos la fecha */
		while (scanf("%d/%d/%d", &dia, &mes, &anio) == 3){

			if (dia == diaAnt and mes == mesAnt and anio == anioAnt and diaAnt){
				cantFecha +=1 ;
			}
			else if (diaAnt != 0){

				/* Si la fecha leida es diferente a la fecha anterior entonces imprimimos el reporte de la fecha Anterior */
				imprimirDatosFecha(diaAnt, mesAnt, anioAnt, cantFecha, tiempoSegTotal, totalLovido);

				/* Actualizamos los valores para el resumen */
				cantTotalReg += cantFecha;
				cantDiasReg += 1;
				tiempoTotaLluvia += tiempoSegTotal;
				totalLovidoPeriodo += totalLovido;

				/* Inicializamos los valores del reporte de la fecha por linea */
				cantFecha = 1;
				tiempoSegTotal = 0;
				totalLovido = 0;
			}
			else if (diaAnt == 0){

				/* Guardamos la primera fecha leida */
				diaIni = dia; mesIni = mes; anioIni = anio;
			}
				
			/* Leemos la hora inicial */
			hayFecha = scanf("%d:%d:%d", &horaIni, &minIni, &segIni);

			/* Verificamos la cantidad de datos leidos de la hora */
			if (hayFecha == 2)
				segIni = 0;
			else if (hayFecha == 1)
				minIni = segIni = 0;

			/* Leemos la hora final */
			hayFecha = scanf("%d:%d:%d", &horaFin, &minFin, &segFin);

			/* Verificamos la cantidad de datos leidos de la hora */
			if (hayFecha == 2)
				segFin = 0;
			else if (hayFecha == 1)
				minFin = segFin = 0;

			/* Leemos la cantidad de agua caida */
			scanf("%lf ", &cantidadAgua);

			/* Actualizamos los valores del reporte de la fecha */
			tiempoSeg = calcularTiempo(horaIni, minIni, segIni, horaFin, minFin, segFin);
			tiempoSegTotal += tiempoSeg;
			totalLovido += cantidadAgua;

			/* Guardamos la fecha anterior */
			diaAnt = dia; mesAnt = mes; anioAnt = anio;

		}

		/* Imprimimos la ultima fecha leida */
		imprimirDatosFecha(diaAnt, mesAnt, anioAnt, cantFecha, tiempoSegTotal, totalLovido);

		/* Actualizamos los valores deñ resumen con los datos del reporte de la ultima fecha leida */
		cantTotalReg += cantFecha;
		cantDiasReg += 1;
		tiempoTotaLluvia += tiempoSegTotal;
		totalLovidoPeriodo += totalLovido;

		imprimirResumen(diaIni, mesIni, anioIni, diaAnt, mesAnt, anioAnt, cantTotalReg, cantDiasReg, tiempoTotaLluvia, totalLovidoPeriodo);

	}

	return 0;

}