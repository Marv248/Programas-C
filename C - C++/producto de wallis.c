#include <stdio.h>

int main(){
    int n=0;
    float res_pi=1.0;

    printf("n:\t");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        res_pi = res_pi * (float)(4*i*i)/(float)(4*i*i-1);
    }

    printf("\nValor aproximado de PI:\t%f", res_pi);    
    system("pause");
}