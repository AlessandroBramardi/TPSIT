#include <stdio.h>
int main(){
    int v[5]={5,4,3,2,1};
    int * p;
    p = v;
    p++;
    printf("%d",*p);
    printf("%d",*v);
    return 0;
}