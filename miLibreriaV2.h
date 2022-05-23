/* 
Autor: Franciscomilan
Realizado: 05/05/22
Escuela: Universidad UVM
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Libreria personalizada .h de 3 parcial en C, contiene funciones comunes de programa en C
para la materia programacion estructurada 
Version 2 
*/


indef _MILIBRERIAv2
define _MILIBRERIAv2

//Librerias
#include<stdio.h>	
#include<string.h>
#include<stdlib.h> 
//Prototipos
void leers(char *mensaje, char s[], int n);
float leerf(char *mensaje, float inferior, float superior);
int leerd(char *mensaje, int inferior, int superior);
//Encabecados nuevas funciones
int validar_entero(char *cadena);
int validar_decimal (char *cadena);

include "miLibreriaV2.cpp"
endif
