#include <stdio.h>
#include <stdlib.h>

int main(){
    char letters[] = "abcdefghijklmnopqrstuvwxyz ";
    while (0<1){
        char l = letters[rand() % 27];
        printf("%c", l);
    }
}