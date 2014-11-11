/* Ejercicio 1
#Tarea 7 metodos computacionales*/
/* Manuel Ariza Fuentes y Lapizano */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv){
FILE *filename;
/* Constantes de derivacion */
int n_points =10;
int n_time=121;
int i=0;
double constante=0.0;
double tension=40.0;
int longitud =101;
int j=0;
/*Revisa que el numero de argumentos sea correcto*/
if(argc!=2){
printf("No se ingreso el argumento requerido \n");
exit(1);
}
/* Variable */
float rho;
/*Las condiciones iniciales */
rho = atof(argv[1]);
constante=sqrt(tension/rho);
/* Arreglos de espacio y tiempo */
int posicion[longitud];
float u_initial[longitud];
float u_future[longitud];
float u_past[longitud];
float u_present[longitud];
double delta_x=0.0;
double delta_t=0.0;
double r=0.0;
/* #find the first iteration for fixed boundary conditions */
delta_x = longitud/n_points;
delta_t = 0.001;
r = constante * delta_t / delta_x; /* Tiene que ser menor que 1 */
for (i=0;i<longitud;i++)
{ posicion[i]=i;
}
for(i=0;i<longitud;i++)
{
if((i) <= (0.8*longitud))
{
u_initial[i] = (1.25*i)/longitud;
}
else if((i)>(0.8*longitud))
{
u_initial[i] = 5-((5*i)/longitud);
}
}
for (i=0;i<longitud;i++)
{ u_future[i]=0.0;
}
for (i=0;i<longitud;i++)
{ u_past[i]=0.0;
}
for (i=0;i<longitud;i++)
{ u_present[i]=0.0;
}
char archivo[100]="string_rho.dat";
sprintf(archivo, "string_%.3f.dat", rho);
filename = fopen(archivo,"w");
printf("%f \n ",r);
if(!filename){
printf("problemas con el archivo %s\n", archivo);
exit(1);
}

 fprintf(filename,"%.10f",u_future[0]);
for(i=1;i<(longitud);i++){
if(i==(longitud-1)){
fprintf(filename,"%.10f ",u_future[longitud-1]);
}
else {
u_future[i]=u_initial[i]+(r*r/2.0)*(u_initial[i+1]-2.0*u_initial[i]+u_initial[i-1]);
fprintf(filename,"%.10f",u_future[i]);
}

}
fprintf(filename,"\n");

for(i=0;i<(longitud);i++){
/* #create a new variable to hold the previous value */
u_past[i] = u_initial[i];
/* #create a new variable to hold the present value */
u_present[i] = u_future[i];
 }


/* next iterations */
for(j=1;j<n_time;j++)
{
fprintf(filename,"%.10f ", u_future[0]);
for(i=1;i<longitud;i++)
{

 if(i==longitud-1){
	fprintf(filename,"%.10f ", u_future[longitud-1]);
      }
      else{
u_future[i]=(2.0*(1.0-r*r))*u_present[i]-u_past[i]+(r*r)*(u_present[i+1]+u_present[i-1]);
fprintf(filename,"%.10f ", u_future[i]);
}
 }

for(i=0;i<longitud;i++){

u_past[i]=u_present[i];
u_present[i]=u_future[i];
 }

fprintf(filename,"\n");
}
/* Crea el archivo y escribe en el */
fclose(filename);
return 0;
}
