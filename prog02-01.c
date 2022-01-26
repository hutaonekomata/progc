#include<stdio.h>
#include<hamako.h>

main(){
    float max,a[100];
    int n,i;
    n = getint("Input n: ");
    if(n <= 0 || n > 100){
        printf("データの数が正しくありません\n");
    }else{
        i = 0;
        while(i < n){
            printf("a[%d] = ",i);
            a[i]=getfloat("");
            i++;
        }
        max = a[0];
        i = 1;
        while(i < n){
            if(a[i] > max){
                max = a[i];
            }
            i = i + 1;
        }
        printf("max = %f\n",max);
    }
    return(0);
}