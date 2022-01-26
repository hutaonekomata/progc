#include<stdio.h>
#include<hamako.h>

int main(){
    int i,n,m;
    n = getint("行数 : ");
    m = getint("列数 : ");
    for(i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("*");
        }
        printf("\n");
    }
    return(0);
}