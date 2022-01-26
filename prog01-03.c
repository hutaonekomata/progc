#include<stdio.h>
#include<hamako.h>

int main()
{
    int a,b,c;
    int max,min,mid;
    a=getint("a = ");
    b=getint("b = ");
    c=getint("c = ");
    if(a>b){
        max=a;
        min=b;
    }else{
        max=b;
        min=a;
    }
    if(max<c){
        mid=max;
        max=c;
    }else if(c<min){
        mid=min;
        min=c;
    }else{
        mid=c;
    }
    printf("max=%d\nmid=%d\nmin=%d\n",max,mid,min);
    return(0);

}