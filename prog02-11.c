#include<stdio.h>
#include<hamako.h>

int main(){
    int n,i,j;
    float ans,x,a[100];
    n = getint("n: ");
    for(i=0;i<=n;i++){
        printf("a[%d] : ",n-i);
        a[i] = getfloat("");
    }
    do{
        ans=0;
        x = getfloat("x : ");
        for(i=0;i<=n;i++){
            float k=1;
            for(j=i;j<n;j++){
                k*=x;
            }
            ans+=k*a[i];
        }
        printf("y = %g\n",ans);
    }while(x!=0);
    return(0);
}