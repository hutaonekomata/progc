#include<stdio.h>
#include<hamako.h>

int gcm(int m, int n);
int numbercheck(void);

int main(){
    int n,m,r,a,ansn,ansm;
    char k='\0';
    printf("Input n : ");
    n=numbercheck();
    printf("Input m : ");
    m=numbercheck();
    ansn=n;
    ansm=m;
    printf("N/M = ");
    //　aはあまり。
    a=n%m;
    if(a!=0){
        // 括弧はヌル文字からの変更でだす。
        // 予め分子はちいさくしておく。
        if(n>m){
            //　あまりを元の数から引いて、割り切れる値にして、帯分数を作り出す。
            n-=a;
            n/=m;
            printf("%d(",n);
            n=a;
            ansn=n;
            k=')';
        }
        // ユークリッドの互除法
        n=gcm(n,m);
        // キャラ型で括弧をおこす。
        printf("%d/%d",ansn/n,ansm/n);
        if(k!='\0'){
            printf("%c",k);
        }
    }else{
        printf("%d",n/m);
    }
    printf("\n");
    return(0);
}

int gcm(int m, int n){
    int r=m%n;
    while(r!=0){
        m=n;
        n=r;
        r=m%n;
    }
    return(n);
}

int numbercheck(void){
    int num;
    num=getint("");
    if(num<=0){
        printf("Input again. Your number is not be able to be used.\n");
        num = numbercheck();
    }
    return(num);
}