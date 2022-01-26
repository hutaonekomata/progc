#include<stdio.h>
#include<hamako.h>

int main(){
    int a,b,c,min,max;
    a=10;
    b=20;
    c=30;
    printf("Now each numbers is readied.\na=10\tb=20\tc=30\nDo you want to change the Number?\n1 . Yes\t2 . No\n");
    int judge;
    judge=getint("Please Input the number:");
    if(judge==1){
        a=getint("a = ");
        b=getint("b = ");
        c=getint("c = ");
    }
    if(a>b){
        max=a;
        min=b;
    }else{
        max=b;
        min=a;
    }
    if(max<c){
        max=c;
    }else{
        if(c<min){
            min=c;
        }
    }
    printf("MAX = %d\nMIN = %d\n",max,min);
    return(0);
}