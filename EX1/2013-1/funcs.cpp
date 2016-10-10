#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;
 
#define MAX_CAR_LIN 1000
#define MAX_ART 1500
#define MAX_PAL 1000
#define MAX_MONTOS 1200
#define INCREMENTO 5
 
void separarPalabras(char *linea, char **palabras, int &nPal){
   
    nPal = 0;
   
    if (strlen(linea) > 0){
       
       
        if (!isblank(linea[0])){
            palabras[0] = linea;
            nPal++;
        }
       
        for (int i = 1; linea[i]; i++){
           
            if (!isblank(linea[i]) and (isblank(linea[i-1]) or linea[i-1] == 0)){
               
                palabras[nPal] = &linea[i];
                nPal++;
               
            }
           
            if (!isblank(linea[i]) and isblank(linea[i+1])){
               
                linea[i+1] = 0;
                i++;
               
            }
           
        }
       
    }
   
}
 
void obtenerDatosArticulos(char linea[], char *&codArt, char *&descripArt, int &stockArt, double &precArt){
   
    char *palabras[MAX_PAL];
    int nPal;
   
    separarPalabras(linea, palabras, nPal);
   
    /* Codigo del articulo */
    codArt = new char[strlen(palabras[0]) + 1];
    strcpy(codArt, palabras[0]);
   
    /* Precio del articulo */
    precArt = atof(palabras[nPal-1]);
   
    /* Stock del articulo */
    stockArt = atoi(palabras[nPal-2]);
   
    /* Descripcion del articulo */
    char nombAux[MAX_CAR_LIN];
    strcpy(nombAux, palabras[1]);
   
    for (int i = 2; i < nPal-2; i++){
        strcat(nombAux, " ");
        strcat(nombAux, palabras[i]);
    }
   
    descripArt = new char[strlen(nombAux) + 1];
    strcpy(descripArt, nombAux);
}
 
void *colocarDatosArticulos(char *codArt, char *descripArt, int stockArt, double precArt){
   
    void **regArticulo = new void*[4];
   
    int *ptrStock = new int;
    *ptrStock = stockArt;
   
    double *ptrPrecio = new double;
    *ptrPrecio = precArt;
   
    regArticulo[0] = codArt;
    regArticulo[1] = descripArt;
    regArticulo[2] = ptrStock;
    regArticulo[3] = ptrPrecio;
   
    return regArticulo;
   
}
       
void *memoriaExacta(void *auxArticulos[], int numArticulos){
   
    void **articulos = new void*[numArticulos+1];
   
    for (int i = 0; i < numArticulos; i++)
        articulos[i] = auxArticulos[i];
   
    articulos[numArticulos] = NULL;
   
    return articulos;
   
}
       
void imprimirArticulos(void *articulos){
   
    void **arrArticulos = (void **) articulos;
   
    int cont = 0;
   
    printf("%-10s %-64s  %-9s %-10s\n", "CODIGO", "DESCRIPCION", "STOCK", "PRECIO");
   
    while (arrArticulos[cont] != NULL){
       
        void **regArticulo = (void **) arrArticulos[cont];
       
        printf("%-10s %-60s %10d %10.2lf\n", (char *) regArticulo[0], (char *) regArticulo[1], *(int *) regArticulo[2], *(double *) regArticulo[3]);
       
        cont++;
       
    }
   
}
       
void leerArticulos(void *&articulos){
   
    char linea[MAX_CAR_LIN];
   
    char *codArt, *descripArt;
    int stockArt;
    double precArt;
   
    /* Declaramos un puntero a void auxiliar */
    void *auxArticulos[MAX_ART];
    int numArticulos = 0;
   
   
    while (cin.getline(linea, MAX_CAR_LIN, '\n')){
       
        if (strcmp(linea, "VENTAS:") == 0)
            break;
       
        obtenerDatosArticulos(linea, codArt, descripArt, stockArt, precArt);
       
        auxArticulos[numArticulos] = colocarDatosArticulos(codArt, descripArt, stockArt, precArt);
       
        numArticulos++;    
       
    }
   
    articulos = memoriaExacta(auxArticulos, numArticulos);
   
}
 
 
 
void obtenerDatosMovimientos(char linea[], char *&codArt, double ArrMontos[], char ArrOper[], int &numOper){
   
    char *palabras[MAX_PAL];
    int nPal;
   
    separarPalabras(linea, palabras, nPal);
   
    codArt = new char[strlen(palabras[0]) + 1];
    strcpy(codArt, palabras[0]);
   
    numOper = 0;
    for (int i = 1; i < nPal; i++){
       
        ArrMontos[numOper] = atof(palabras[i]);
        ArrOper[numOper] = *palabras[i+1];
 
        numOper += 1;
        i++;       
       
    }
       
}
 
 
void inicializarMovimientos(void *&movimientos, void *articulos, int &numArticulos){
   
    void **arrArticulos = (void **) articulos;
   
    int cont = 0;
    while (arrArticulos[cont] != NULL)
        cont++;
   
    void **arrMovimientos = new void*[cont];
   
    for (int i = 0; i < cont; i++)
        arrMovimientos[i] = NULL;
 
    movimientos = arrMovimientos;
   
    numArticulos = cont;
       
}
 
int buscarPosArt(void *articulos, int numArticulos, char *codArt){
   
    void **arrArticulos = (void **) articulos;
   
    for (int i = 0; i < numArticulos; i++){
       
        void **regArt = (void **) arrArticulos[i];
       
        if (strcmp((char *)regArt[0], codArt) == 0)
            return i;
       
    }
   
    return -1;
   
   
}
 
 
void inicializarRegMovimiento(void *&movimientos){
   
    void **regMovimientos = new void*[3];
   
    int *cantidades = new int[2];
    double *ArrMontos = new double[INCREMENTO+1];
    char *ArrOper = new char[INCREMENTO+1];
   
    cantidades[0] = INCREMENTO;
    cantidades[1] = 0;
   
    regMovimientos[0] = cantidades;
    regMovimientos[1] = ArrMontos;
    regMovimientos[2] = ArrOper;
   
    movimientos = regMovimientos;  
   
}
 
 
void insertarMontoYOper(void *&movimientos, double monto, char oper){
   
    void **regMovimientos = (void **) movimientos;
   
    int *cantidades = (int *) regMovimientos[0];
    double *montos = (double *) regMovimientos[1];
    char *operaciones = (char *) regMovimientos[2];
   
    montos[cantidades[1]] = monto;
    operaciones[cantidades[1]] = oper;
    cantidades[1] += 1;
   
    regMovimientos[0] = cantidades;
    regMovimientos[1] = montos;
    regMovimientos[2] = operaciones;
   
    movimientos = regMovimientos;
   
}
 
void incrementarTamanio(void *&movimientos){
   
    void **regMovimientos = (void **) movimientos;
           
    int *cantidades = (int *) regMovimientos[0];
    double *montos = (double *) regMovimientos[1];
    char *operaciones =(char *) regMovimientos[2];
   
    double *auxMontos = new double[cantidades[0] + INCREMENTO + 1];
    char *auxOperaciones = new char[cantidades[0] + INCREMENTO + 1];
   
    for (int i = 0; i < cantidades[0]; i++){
   
        auxMontos[i] = montos[i];
        auxOperaciones[i] = operaciones[i];
   
    }
   
    cantidades[0] += INCREMENTO;
   
    delete [] montos;
    delete [] operaciones;
   
    regMovimientos[0] = cantidades;
    regMovimientos[1] = auxMontos;
    regMovimientos[2] = auxOperaciones;
   
    movimientos = regMovimientos;
   
}
 
void insertarMovimientos(void *&movimientos, double ArrMontos[], char ArrOper[], int numOper){
   
    for (int i = 0; i < numOper; i++){
       
       
        if (movimientos == NULL)
            inicializarRegMovimiento(movimientos);
           
        void **regMovimientos = (void **) movimientos;
           
        int *cantidades = (int *) regMovimientos[0];
        double *montos = (double *) regMovimientos[1];
        char *operaciones = (char *) regMovimientos[2];
       
       
   
       
        if (cantidades[1] < cantidades[0])
            insertarMontoYOper(movimientos, ArrMontos[i], ArrOper[i]);
        else{
            incrementarTamanio(movimientos);
            insertarMontoYOper(movimientos, ArrMontos[i], ArrOper[i]);
        }
           
    }
   
   
}
 
 
void leeMovimientos(void *&movimientos, void *articulos){
   
    char linea[MAX_CAR_LIN];
   
    char *codArt;
    double ArrMontos[MAX_MONTOS];
    char ArrOper[MAX_MONTOS];
    int numOper, numArticulos;
   
    inicializarMovimientos(movimientos, articulos, numArticulos);
   
    void **arrMovimientos = (void **) movimientos;
   
    while (cin.getline(linea, MAX_CAR_LIN, '\n')){
       
 
        obtenerDatosMovimientos(linea, codArt, ArrMontos, ArrOper, numOper);
       
        int posArt = buscarPosArt(articulos, numArticulos, codArt);
       
        if (posArt != -1)
            insertarMovimientos(arrMovimientos[posArt], ArrMontos, ArrOper, numOper);
       
       
    }
   

    movimientos = arrMovimientos;  
    
}
 
 void imprimirMovimientos(void *movimientos, void *articulos){
	 
	void **arrMovimientos = (void **) movimientos;
	void **arrArticulos = (void **) articulos;
	
	
	
    for (int i = 0; arrArticulos[i]; i++){
        
		void **regMovimientos = (void **) arrMovimientos[i];
		void **regArticulos = (void **) arrArticulos[i];
		
		printf("%8s ", (char *) regArticulos[0]);
		
		
        int *cantidades = (int *) regMovimientos[0];
        double *montos = (double *) regMovimientos[1];
        char *operaciones =(char *) regMovimientos[2];

        for (int j = 0; j < cantidades[1]; j++){
            printf(" %10.2lf %5c ", montos[j], operaciones[j]);
        }
		
		printf("\n");
       
       
    }
   
	 
 }
 
 
int calcularNumArticulos(void *articulos){
   
    int cont = 0;
   
   
    void **arrArticulos = (void **) articulos;
   
    while (arrArticulos[cont] != NULL)
        cont++;
   
    return cont;   
   
}
 
char *obtenerCodigo(void *articulo){
   
    void **regArt = (void ** ) articulo;
   
    return ((char *) regArt[0]);
   
   
}
 
void intercambiar(void *&articulo1, void *&articulo2){
   
    void *auxArticulo;
   
    auxArticulo = articulo1;
    articulo1 = articulo2;
    articulo2 = auxArticulo;
   
}
 
void ordenarArticulos(void *&articulos){
   
   
    int numArticulos = calcularNumArticulos(articulos);
   
    int i , j;
   
    void **arrArticulos = (void **) articulos;
   
    for (i = 0; i < numArticulos-1; i++){
        for (j = 0; j < numArticulos-i-1; j++){
           
            char *cod1 = obtenerCodigo(arrArticulos[j]);
            char *cod2 = obtenerCodigo(arrArticulos[j+1]);
           
            if (strcmp(cod1, cod2) > 0)
                intercambiar(arrArticulos[j], arrArticulos[j+1]);
           
        }
    }
   
   
}