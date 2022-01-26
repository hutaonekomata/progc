#include<stdio.h>
#include<hamako.h>

int max(int a,int b);

int main(){
    int a,b;
    a = getint("Input a : ");
    b = getint("Input b : ");
    printf("Biggest number ");
    return;
}

int max(int a,int b){
    if(a<b){
        a=b;
    }
    return a;
}