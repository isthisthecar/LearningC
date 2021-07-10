#include <stdio.h>

void add(int *a, int *b){

    *a += *b;
    printf("%d\n", *a);

}

int main (){
    int a = 5 , b=3;
    add(&a,&b);
    printf("%d", a);
    return 0;

}