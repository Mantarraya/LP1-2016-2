## LABORATORIO #4 PREGUNTA 1 2016-2

### TEMA
Implementar una biblioteca estatica para manipular el movimiento de una tortuga(puntero)

### LINEA DE COMANDOS PARA COMPILAR Y EJECUTAR EL PROGRAMA
```sh
$ g++ main.cpp tortuga.cpp
$ a.exe > salida.txt
```

### SALIDA
```
Tablero Inicial: 

0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Posicion Inicial (x, y): 0 0

1 1 1 1 1 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Posicion (x, y): 5 0

1 1 1 1 1 1 0 
0 0 0 0 0 1 0 
0 0 0 0 0 1 0 
0 0 0 0 0 1 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Posicion (x, y): 5 4

1 1 1 1 1 1 0 
0 0 0 0 0 1 0 
0 0 0 0 0 1 0 
0 0 0 0 0 1 0 
0 0 0 1 1 1 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Posicion (x, y): 2 4
```

### LINEA DE COMANDOS PARA GENERAR UNA LIBRERIA ESTÁTICA
Una vez que se corrobore el correcto funcionamiento de los procedimientos y/o funciones de la libreria *tortuga.cpp* se procede a crear la biblioteca estática *tortuga.a* 
```sh
$ g++ -c -o tortuga.o tortuga.cpp
$ ar r tortuga.a tortuga.o
```