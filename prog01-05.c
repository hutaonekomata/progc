#include<stdio.h>
#include<hamako.h>

int main()
{
    //------Input----------------------//
    int a,b,c;
    a=getint("a=");
    b=getint("b=");
    c=getint("c=");
    //---------------------------------//

    //---------judging-----------------//
    if(a==b&&a==c){
        printf("3つの値は等しいです\n");
    }else if(a!=b&&a!=c&&b!=c){
        printf("3つの値は異なります\n");
    }else{
        printf("２つの値が等しいです\n");
    }
    return(0);
}