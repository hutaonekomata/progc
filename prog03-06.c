#include<stdio.h>
#include<hamako.h>
#include<string.h>

int main(){
    char a[256],b[256];
    int i=0,lenn,lenm,ans=0,min;
    lenn=getstring("Input a : ",a);
    lenm=getstring("Input b : ",b);
    if(lenn<lenm){
        min=lenn;
    }else{
        min=lenm;
    }
    while(a[i]==b[i]&&i<min){
        i++;
    };
    printf("String's Long : %d\n",i);
    return(0);
}