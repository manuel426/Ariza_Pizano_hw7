#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265
#define gamma 1,4
#define dt 0.001
#define npoints 2001
#define a1 0.4
#define L 20


double FLUX(double u11, double u22, double u33, int c);

int main(int argc, char **argv){
    
    //Parametros
    double ttt = (int)atof(argv[1])/dt;
    double tttt = (float)atof(argv[1]);
    
    //double ttttt = printf("%g \n", tttt);
    //printf("%g \n", ttttt);
    
    double dx = 0.1;//20/npoints;
    double *pos = malloc(npoints*sizeof(float));
    
    //Gases constants
    double rho1=1; //kg/m^3
    double presion1=100; //kN/m^2
    double rho2=0.125; //kg/m^3
    double presion2 = 10; //kN/m^2
    
    
    //Conserved variables v for past, i for intermediate
    float *u1 = malloc(npoints*sizeof(float));
    float *u2 = malloc(npoints*sizeof(float));
    float *u3 = malloc(npoints*sizeof(float));
    float *u1v = malloc(npoints*sizeof(float));
    float *u2v = malloc(npoints*sizeof(float));
    float *u3v = malloc(npoints*sizeof(float));
    float *u1i = malloc(npoints*sizeof(float));
    float *u2i = malloc(npoints*sizeof(float));
    float *u3i = malloc(npoints*sizeof(float));
    
    //Pressure vector
    float *P = malloc(npoints*sizeof(float));
    
    //Define constants
    int i, j;
    
    
    
    //Inicialización de matrices
    for(i=0; i<npoints; i++){
        if(i<(npoints/2)){
            
            u1[i]=rho1;
            u2[i]=0.0;
            u3[i]=presion1/a1;
            P[i]=presion1;
            
        }
        else{
            
            u1[i]=rho2;
            u2[i]=0.0;
            u3[i]=presion2/a1;
            P[i]=presion2;
        }
       
    }
    
    int y, k, l;
    
    for(y=0;y<ttt;y++){
        
        
        for(k=0;k<npoints-1;k++){
        
            u1i[k] = 0.5*(u1[k+1]+u1[k])-(dt/(2*dx))*(FLUX(u1[k+1],u2[k+1],u3[k+1],0)-FLUX(u1[k],u2[k],u3[k], 0));
            
            u2i[k] = 0.5*(u2[k+1]+u2[k])-(dt/(2*dx))*(FLUX(u1[k+1],u2[k+1],u3[k+1],1)-FLUX(u1[k],u2[k],u3[k], 1));
            
            u3i[k] = 0.5*(u3[k+1]+u3[k])-(dt/(2*dx))*(FLUX(u1[k+1],u2[k+1],u3[k+1],2)-FLUX(u1[k],u2[k],u3[k], 2));
            
            
            
        }
        for(l=1;l<npoints-1;l++){
            
            u1[l] = u1[l] + (dt/dx)*(FLUX(u1i[l],u2i[l],u3i[l], 0)-FLUX(u1i[l-1],u2i[l-1],u3i[l-1], 0));
            
            u2[l] = u2[l] - (dt/dx)*(FLUX(u1i[l],u2i[l],u3i[l], 1)-FLUX(u1i[l-1],u2i[l-1],u3i[l-1], 1));
            
            u3[l] = u3[l] - (dt/dx)*(FLUX(u1i[l],u2i[l],u3i[l], 2)-FLUX(u1i[l-1],u2i[l-1],u3i[l-1], 2));
            
            //P[l] = a1*(u3[l]-0.5*((u2[l]*u2[l])/u1[l]));
            
        }
        
    }
    
    FILE *file;
    
    
    file = fopen("estado_t.dat", "w");
    for(j=0;j<npoints-1;j++){
        pos[j] = (double)L*j/npoints-10;
        P[j] = a1*(u2[j]-0.5*(pow(u1[j],2)/u1[j]));
        fprintf(file, "%f \t %f \t %f \t %f \n", pos[j], u2[j]/u1[j], P[j], u1[j]);
    }
    fclose(file);
    
    return 0;
}



//Flux calculation
double FLUX(double u11, double u22, double u33, int c){
    
    //Initialize Flux vector
    double flux [3];
    
    
    flux[0] = u22;
    flux[1] = (u22*u22)/u11 + a1*(u33-0.5*((u22*u22)/u11));
    
    flux[2] = (u33+a1*(u33-0.5*((u22*u22)/u11)))*(u22/u11);
    return flux[c];
    
}