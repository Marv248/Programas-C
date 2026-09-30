#include<stdio.h>
# include<iostream>

int main(){
    char c = ' ';
    int flag = 0;
    while(!flag){
        printf("\nC:\t");
        fflush(stdin);
        scanf("%c", &c);
        printf("\nC:\t\n", c);
        flag = (c >= '0') && (c <='9');
    }

    system("pause");
    return 0;
}