#include<stdio.h>
#include<hamako.h>

int main()
{
    int a,b,c,d;
    a=getint("a=");
    b=getint("b=");
    c=getint("c=");
    d=getint("d=");
    int max,min;
    if(a>b)
    {
        max=a;
        min=b;
    }
    else
    {
        max=b;
        min=a;
    }
    if(max<c)
    {
        max=c;
    }
    else if(min>c)
    {
        min=c;
    }
    if(max<d)
    {
        max=d;
    }
    else if(min>d)
    {
        min=d;
    }
    printf("max=%d\nmin=%d\n",max,min);
    return(0);

}