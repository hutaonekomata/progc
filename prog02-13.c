#include<stdio.h>
#include<hamako.h>

int main(){
    int n;
    n = getint("段数 : ");
    for(int i=n;i>0;i--){
        for(int j=i-1;j<n;j++){
            printf("*");
        }
        printf("\n");
    }
    return(0);
}