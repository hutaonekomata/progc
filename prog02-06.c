#include<stdio.h>
#include<hamako.h>

int main(){
    int n,i,ans=1;
    n = getint("Input n: ");
    for(i=1;i<=n;i++){
        ans*=i;
    }
    printf("%d! = %d\n",n,ans);
    return(0);
}