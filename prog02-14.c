#include<stdio.h>
#include<hamako.h>

int main(){
    int n;
    n = getint("Input n : ");
    for(int i=1;i<=n;i++){
        int judge[10]={};
        printf("%d",i);
        int k=i;
        if(k%3==0){
            printf(" アホ");
        }else{
            do{
                k/=10;
            }while(k%10!=3&&k>0);
            if(k>=3){
                printf(" アホ");
            }
        }
        printf("\n");
    }
    return(0);
}