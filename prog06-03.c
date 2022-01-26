#include<stdio.h>
#include<hamako.h>

int main(){
    int n,j;
    //自然数nを入力する
    n = getint("Input n : ");
    //素数２をそのまま出力する。
    printf("2 ");
    //n以下の奇数をすすうかどうか順に調べ、素数なら表示する。
    //n回回す。
    for(int i=3;i<=n;i++){
        //今見ている数が素数かどうかを判定する。
        j=2;
        while(j<i&&i%j!=0){
            j++;
        }
        if(j==i){
            printf("%d ",i);
        }
    }
    printf("\n");
    return(0);
}