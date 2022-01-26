#include<stdio.h>
#include<hamako.h>

int chkFizzBuzz(int x,int m,int n);

int main(){
    int j,z,m,n;
    z=getint("Input z : ");
    m=getint("Input m : ");
    n=getint("Input n : ");
    for(int i=-z;i<=z;i++){
        printf("%d",i);
        j=chkFizzBuzz(i,m,n);
        if(j==1){
            printf(" Fizz");
        }else if(j==2){
            printf(" Buzz");
        }else if(j==3){
            printf(" FizzBuzz");
        }
        printf("\n");
    }
    return(0);
}

int chkFizzBuzz(int x,int m,int n){
    int judge;
    if(x==0){
        judge=0;
    }else if(x%m==0&&x%n==0){
        judge=3;
    }else if(x%m==0){
        judge=1;
    }else if(x%n==0){
        judge=2;
    }else{
        judge=-1;
    }
    return(judge);
}