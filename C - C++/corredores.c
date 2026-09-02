/******************************************************************************

    Rebollo Vargas Marco Antonio
    
    Programa 1. Calcular velocidad de corredores mediante el tiempo que tardaron
    en minutos, segundos y centésimas y la distancia recorrida dada en metros

*******************************************************************************/

#include <stdio.h>
#include <math.h>
# include<iostream> // Para que no se cierre la consola

int main()
{
    float min, seg, cen, dis;
    float tse;
    float vms, vkm;
    
    // Solicitar datos
    printf("Introduce la distancia recorrida en metros: ");
    scanf("%f", &dis);
    printf("\nIntroduce el tiempo en minutos: ");
    scanf("%f", &min);
    printf("\nIntroduce el tiempo en segundos: ");
    scanf("%f", &seg);
    printf("\nIntroduce el tiempo en centésimas: ");
    scanf("%f", &cen);
    
    // Cálculos
    tse = (min*60) +(seg) + (cen/100);
    vms = dis/tse;
    vkm = (vms*3600)/1000;
    
    printf("La velocidad en metros sobre sesgundo es: %f\t", vkm);
    
    system("pause"); // Para que no se me cierre la consola
    return 0;
}