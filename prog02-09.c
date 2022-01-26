#include<stdio.h>
#include<hamako.h>

int main(){
    int n;
    n = getint("Input n : ");
    int gusu=0,kisu=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            gusu+=i;
        }else{
            kisu+=i;
        }
    }
    printf("偶数の和 = %d\n奇数の和 = %d\n",gusu,kisu);
    return(0);
}