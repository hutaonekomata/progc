#include<stdio.h>
#include<hamako.h>

int main(){
    //上限値を設定。自然数nを入力。
    int n;
    n = getint("Input n : ");
    //配列を用意
    int a[n+1];
    //--配列を初期化。
    int i=3;
    // １を除くn以下の奇数を用意する。
    while(i<=n){
    // 配列を初期化。
        a[i]=1;
        i+=2;
    }
    i=3;
    int j;
    //倍数を次々消去していく。
    while(i*i<=n){
        // 全探索
        // √nまで調べて、効率化
        j=i*i;//iを見ない。
        // 探索済みかを確認。
        if(a[i]){
            while(j<=n){
            // 倍数を消去
                a[j]=0;
                j=j+i*i;//次に消去するiの倍数。
            }
        }
        // 奇数のみ判定
        i+=2;//次の自然数[奇数]iを選ぶ。
    }
    // 予め2は出力しておく
    printf("2 ");
    // 残った自然数[素数・奇数]を表示する。
    for(i=3;i<=n;i+=2){
        // 奇数のみ判定
        if(a[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    return(0);
}

