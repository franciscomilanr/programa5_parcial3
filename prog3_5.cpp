/* 
Autor: Franciscomilan
Realizado: 07/04/22 - 05/05/2022
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa 5 en C del parcial 3 que utilice la estrcutura de Alumno y almacene los datos de 10 alumnos
en el arreglo de la estructura para almacenar los datos y guardarlos en un archivo binarios, mostrando los datos en 
pantalla con el siguiente menu en un switch case:
0 para Salir
1 para Agregar alumnos
2 para Imprimir
3 para Alumnos aprobados
4 para Alumnos reprobados
5 para Pormedio del grupo
6 para Porcentaje de alumnos aprobados 
7 para Guardar datos
8 para Cargar datos
9 para Ordenar nombre
Basado en prog 3_3, ahora utilizando archivos binarios para la materia programacion estructurada
*/

#include<stdio.h>
#include<stdlib.h>
#include"miLibreriaV2.h"

//Variables globales
#define MAX 100	
struct alumno {
	char nombre[30];
	float promedio;
	int faltas;
};	
int n=0;  

//Prototipos de funcion
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo); 
void promedioGrupo (struct alumno x[]);
void porcentajeAprobados (struct alumno x[]);
void guardar (struct alumno x[]);
void cargar (struct alumno x[]);
void ordenarNombre(struct alumno x[]);

//Funciones
int main () {
	int op;
	struct alumno grupo[MAX];	//Se declaro el arreglo de estrucutura alumno
	do {
		op=menu();
		switch(op) {
			case 0: printf(" - Adios - \n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				break;
			case 4: imprimir(grupo,2);
				break;
			case 5: promedioGrupo(grupo);
				break;
			case 6: porcentajeAprobados(grupo);
				break;
			case 7: guardar(grupo);
				break;
			case 8: cargar(grupo);
				break;
    			case 9: ordenarNombre(grupo);
       				 break;
		}
	}while(op!=0);
	//Retorno
	return 0;
}

//Funcion menu
int menu() {
	int opcion;
	printf(" --------------- MENU -------------\n ");
	printf(" 0. Salir \n");
	printf(" 1. Agregar alumnos \n");
	printf(" 2. Imprimir \n");
	printf(" 3. Alumnos aprobados\n");
	printf(" 4. Alumnos reprobados \n");
	printf(" 5. Promedio del grupo \n");
	printf(" 6. Porcentaje de alumno aprobados \n");
	printf(" 7. Guardar datos \n");
	printf(" 8. Cargar datos \n");
  	printf(" 9. Ordenar por nombre \n");
	opcion=leerd(" Seleccionar una opcion: ", 0, 10);
	return opcion;
}

//Funcion agregar
void agregar (struct alumno x[]) {
	int pregunta;
	while (n<MAX) {
		leers("Nombre: ", x[n].nombre,30);
    //x[n].nombre=leers("Nombre: ",0, 30);
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd(" Faltas: ", 0, 32);
		pregunta=leerd(" Agregar otro alumno? (1-Si, 0-No): ",0,1);
		n++;
		if (pregunta==0) {
			break;
		}	
	}
	if (n==MAX) {
		printf(" Arreglo lleno ! \n");
		system("PAUSE");
	}
}

		
//Funcion imprimir
void imprimir(struct alumno x[], int tipo) {
	
	char mensaje[20];
	switch(tipo) {
		case 0: strcpy(mensaje,"Totales");
			break;
		case 1: strcpy(mensaje, "Aprobados");
			break;
		case 2: strcpy(mensaje,"Reprobados");
			break;
	}

	printf("\n--------------Alumnos %s---------------------\n", mensaje);
	printf(" -----------/- DATOS DEL GRUPO -/---------------\n");
	printf(" No.Alumno\t\t  Nombre\t   Faltas\t\t   Promedio\n");
	printf("--------------------------------------------------\n\n");
	

	for (int i=0;i<n;i++) {
		int aprobados;
		switch(tipo) {
			case 0: printf("\t%2d \t\t\t\t %s30s \t\t %2d \t\t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				break;
			case 1: if (x[i].promedio>=7) {
					printf("\t%2d \t\t\t\t %s30s \t\t %2d \t\t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
					aprobados++;
				}
				break;
			case 2: if (x[i].promedio<=7) {
					printf("\t%2d \t\t\t\t %s30s \t\t %2d \t\t %4.1f \n",i+1,x[i].nombre, x[i].faltas,x[i].promedio);
				}
				break;
			}
		}
	printf("----------------------------------------------------\n");
	system("PAUSE");
}


//Funcion promedio del grupo
void promedioGrupo (struct alumno x[]) {
	float suma=0, promedioA=0;
	int i=0;
	for (int i=0; i<n; i++) {
		suma=suma+x[i].promedio;
	}
	promedioA=suma/n;
	printf(" El promedio del grupo es: %4.1f \n", promedioA);
}

//Funcion calcular el porcentaje
void porcentajeAprobados (struct alumno x[]) {
	float porcentajeApro=0;
	int aprobados=0;
	for (int i=0;i<n;i++) {
		if(x[i].promedio>=7 && x[i].faltas <=6) {
		aprobados++;	
		}
	}
	porcentajeApro=(aprobados*100/n);
	printf(" El porcentaje de alumnos aprobados es: %.1f\n",porcentajeApro);
}

//Funcion guardar en archivo binario
void guardar (struct alumno x[]) {
  	//Declarar variable del archivo
	FILE *f;
  	//Abrir archivo
	f=fopen("alumnos.dat","w");
  	//Condicionante arreglo para validar si no se abrio
	if (f==NULL) {
		printf(" Error al intentar guardar los datos !!! \n");
	} else {
    	//Entra aqui SI se pudo abrir el archivo
		for (int i=0; i<n; i++) {
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
    		//Cerrar el proceso del archivo
		fclose(f);
		printf("\n--> Se guardaron %d registro \n\n", n);
		system("PAUSE");
	}
}


//Funcion cargar - Leer el archivo binario y cargarlo al arreglo de estructuras
void cargar (struct alumno x[]){
  	FILE *f;
  	f=fopen("alumnos.dat","r");
 	 n=0;
 	 if (f==NULL){
   	 printf("\nError al intentar cargar el archivo !! \n ");
 	 } else {
  	  printf("\n leyendo ....\n\n ");
   	 while (fread(&x[n], sizeof (x[n]),1,f)==1) {
      	 //Si regresa 1 significa que termino de leer y se sale
    	  n++;
    	 printf("%3d\t %-30s\t %4.1f\t %2d\n", n, x[n-1].nombre, x[n-1].promedio, x[n-1].faltas);
   	 }
    fclose(f);
    printf("\n--> %d de registros leidos\n\n\n",n);
    system("PAUSE");
  }
}

//Funcion ordenar por nombre
void ordenarNombre(struct alumno x[]) {
	//Ordenamiento del arreglo por el metodo de la burbuja
	for (int z=1; z<n; ++z) {
		struct alumno aux;
		for (int v=0; v<(n-z); v++) {
			//edades[v] > edades[v+1]
			if (strcmp(x[v].nombre, x[v+1].nombre)>0) {
				aux = x[v];
				x[v] = x[v+1];
				x[v+1] = aux;
			}
		}
	}
	imprimir(x,0);
}

