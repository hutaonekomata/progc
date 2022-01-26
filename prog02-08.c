#include<stdio.h>
#include<hamako.h>

int main(){
    int i,n,m,five=0,thr=0,fift=0;
    n = getint("Input n : ");
    m = getint("Input m : ");
    for(i=n;i<=m;i++){
        if(i%5==0){
            if(i%3==0&&i!=0){
                fift++;
                thr++;
                five++;
                // printf("%dFizzBuzz\n",i);
            }else if(i!=0){
                five++;
                // printf("%dBuzz\n",i);
            }
        }else if(i%3==0){
            thr++;
            // printf("%dFizz\n",i);
        }
    }
    printf("３の倍数 : %d\n5の倍数 : %d\n3と5の公倍数 : %d\n",thr,five,fift);
    return(0);
}