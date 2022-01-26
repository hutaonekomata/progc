#include<stdio.h>
#include<hamako.h>

main(){
    float sum,avg,min,max,a[100];
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
        min = a[0];
        sum = a[0];
        i = 1;
        while(i < n){
            if(a[i] > max){
                max = a[i];
            }else if(min>a[i]){
                min = a[i];
            }
            sum+=a[i];
            i = i + 1;
        }
        avg = sum/(float)n;
        printf("max = %g min = %g\n",max,min);
        printf("sum = %g avg = %g\n",sum,avg);
    }
    return(0);
}