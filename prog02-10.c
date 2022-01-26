#include<stdio.h>
#include<hamako.h>

int main(){
    int n;
    n = getint("Input n : ");
    int gusu=0;
    for(int i=0;i<n;i++){
        int a;
        printf("a[%d] =",i);
        a = getint(" ");
        if(a%2==0){
            gusu+=a;
        }
    }
    printf("偶数データの和 = %d\n",gusu);
    return(0);
}