#include<stdio.h>
#include<hamako.h>

int main(){
    float x,ans=1;
    int n;
    x = getfloat("Input x : ");
    n = getint("Input n : ");
    for(int i=0;i<n;i++){
        ans*=x;
    }
    printf("%g^%d = %g\n",x,n,ans);
    return(0);
}