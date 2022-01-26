#include<stdio.h>
#include<hamako.h>

int main(){
    int n,m,r,a,ansn,ansm;
    char k='\0';
    do{
        n = getint("Input N : ");
        m = getint("Input M : ");
        // 入力時点でエラーをだす
        if(m<1||n<0){
            printf("What do you want to do?\nPlease Input Again\n");
        }
    }while(m<1||n<0);
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
        int r=m%n;
        // ユークリッドの互除法
        while(r!=0){
            m=n;
            n=r;
            r=m%n;
        }
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
