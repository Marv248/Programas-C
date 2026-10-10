#include<stdio.h>

int main(){
    int n=0, mayor=0, menor=0;
    float promedio=0.0;

    printf("n:\t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int num=0;
        printf("\nIngrese un número:\t");
        scanf("%d", &num);

        if(i==0){
            mayor=num;
            menor=num;
        }else{
            if(num>mayor){
                mayor=num;
            }
            if(num<menor){
                menor=num;
            }
        }

        promedio+=num;
    }
    promedio/=n;
    printf("\nMayor:\t%d", mayor);
    printf("\nMenor:\t%d", menor);
    printf("\nPromedio:\t%f", promedio);
    return 0;
}