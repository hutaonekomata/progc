#include<stdio.h>
#include<hamako.h>

int main(){
    int i,n,ans;
    n = getint("Input n : ");
    for(i=n;i>0;i--){
        ans+=i;
    }
    printf("Sum : %d\n",ans);
    return(0);
}