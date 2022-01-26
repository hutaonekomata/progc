#include<stdio.h>
#include<hamako.h>

int main(){
    float a,b,c,d;
    int e,f,g;
    a = getfloat("a = ");
    b = getfloat("b = ");
    c = getfloat("c = ");
    d = getfloat("d = ");
    e = getint("e = ");
    f = getint("f = ");
    g = getint("g = ");
    printf("a = %f b = %f c = %f d = %f\n",a,b,c,d);
    printf("e = %d f = %d g = %d\n");
    return(0);
}