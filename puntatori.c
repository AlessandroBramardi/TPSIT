#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 5;
    int b;
    int* p;
    p = &a;
    b=*p;
    printf("%d\n",b);
    printf("%p\n",p);
    printf("%p",&b);
}