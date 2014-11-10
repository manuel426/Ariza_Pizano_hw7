/* Ejercicio 1
#Tarea 6 metodos computacionales*/
/* Manuel Ariza Fuentes y Billy Revelo */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv){
FILE *filename;

/* Constantes de derivacion */
int n_points =101;
int n_time=121;
int i=0;
double constante=0.0;
int tension=40;
int longitud =101;

/*Revisa que el numero de argumentos sea correcto*/
if(argc!=2){
printf("No se ingreso el argumento requerido \n");
exit(1);
}

/* Punteros de la variable */
float* rho;

/* Espacio para los 3 punteros */
rho = malloc(5*sizeof(float));

/*Las condiciones iniciales */
rho[0] = atof(argv[1]);

rhofinal=rho[0];

/* Arreglos de espacio y tiempo */

int tiempo[n_time];
int posicion[longitud];
float velocidad[n_time][longitud];


for (i=0;i<n_time;i++)
  { tiempo[i]=i;

}

for (i=0;i<longitud;i++)
  { posicion[i]=i;

}












/*Crea el archivo y escribe en el*/
char archivo[100]="poblaciones_rho.dat";
sprintf(archivo, "poblaciones_%f.dat", rhofinal);
filename = fopen(archivo,"w");
printf("El archivo fue creado con exito");
if(!filename){
printf("problemas con el archivo %s\n", archivo);
exit(1);
}
/* Las 3 columnas de las variables, incluyendo las condiciones iniciales */
for(i=0;i<n_points;i++){
    for(j=0;j<n_time;j++){
        fprintf(filename, "%f %f \n", t[i], velocidad[i][j]);
          }
     }





fclose(filename);

return 0;
}



