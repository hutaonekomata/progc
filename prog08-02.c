#include<stdio.h>
#include<hamako.h>

int sumConsInt(int n);
int numbercheck(void);

int main(){
    int n;
    n=numbercheck();
    printf("Sum : %d\n",n);
    return(0);
}

int sumConsInt(int n){
    int ans=0;
    ans=n*(n+1)/2;
    return(ans);
}

int numbercheck(void){
    int n;
    n=getint("Input n : ");
    if(n<0){
        n=-1;
    }else{
        n=sumConsInt(n);
    }
    return(n);
}