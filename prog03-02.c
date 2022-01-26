#include<stdio.h>
#include<hamako.h>
#include<string.h>

int main(){
    int i=0,n,p=1;
    char c[256];
    n = getstring("Input String : ",c);
    do{
        if(c[i]!=c[n-i-1]){
            p=0;
        }
        i++;
    }while(i<n-i-1&&c[i]==c[n-i-1]);
    printf("p : %d\n",p);
    return(0);
}
