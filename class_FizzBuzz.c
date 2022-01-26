#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    printf("Input number is %d\n",n);
    int ansf=0,anst=0,ansft=0;
    int k;
    while(n>0){
        k=0;
        if(n%3==0){
            anst++;
            k++;
        }
        if(n%5==0){
            ansf++;
            k++;
        }
        if(k==2){
            ansft++;
        }
        n--;
    }
    printf("3 = %d\n5 = %d\n15 = %d\n",anst,ansf,ansft);
    return(0);
}