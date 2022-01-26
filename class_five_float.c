#include<stdio.h>
#include<hamako.h>

int main(){
    printf("How many boxes do you want to ready?\n");
    int n;
    while(1){
        n = getint("n : ");
        if(n<0||n>=100){
            printf("No Accepted\n");
        }else{
            break;
        }
    }
    float a[n];
    int i=0;
    while(i<n){
        printf("%d",i+1);
        a[i]=getfloat(" : ");
        printf("%d = %g\n",i+1,a[i]);
        i++;
    }
    return(0);
}