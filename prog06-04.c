#include<stdio.h>
#include<hamako.h>
#include<math.h>

int main(){
    int n,j,o;
    int a[10000];
    //自然数nを入力する
    n = getint("Input n : ");
    //素数２をそのまま出力する。
    if(n>1){
        printf("2 ");
        if(n>2){
            printf("3 ");
        }
    }
    //n以下の奇数をすすうかどうか順に調べ、素数なら表示する。
    //n回回す。
    for(int i=3;i<=n;i+=2){//奇数のみを判定する。
        //今見ている数が素数かどうかを判定する。
        j=3;
        o=1;
        while(j*j<i&&o!=0){
            j+=2;
            o=i%j;
        }
        if(o!=0){
            printf("%d ",i);
        }
    }
    printf("\n");
    return(0);
}
