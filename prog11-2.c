#include<stdio.h>
#include<hamako.h>

int gcm(int m, int n);
int numbercheck(void);

int main(){
    int m,n;
    printf("Input n : ");
    m=numbercheck();
    printf("Input m : ");
    n=numbercheck();
    printf("GCM : %d\n",gcm(m,n));
    return(0);
}

int gcm(int m, int n){
    int r=m%n;
    while(r!=0){
        m=n;
        n=r;
        r=m%n;
    }
    return(n);
}

int numbercheck(void){
    int num;
    num=getint("");
    if(num<=0){
        printf("Input again. Your number is not be able to be used.\n");
        num = numbercheck();
    }
    return(num);
}