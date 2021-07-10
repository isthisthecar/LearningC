#include <stdio.h>

// 형식 매개변수 Formal parameter : 함수정의에서 기술되는 매개변수 목록
// 실 매개변수 real parameter : 함수 호출에서 기술되는 값, 인자 Argument

void add(int a, int b){

    a += b;
    printf("%d\n", a);

}

int main (){
    int a = 5 , b=3;
    add(a,b);
    printf("%d", a);
    return 0;

}