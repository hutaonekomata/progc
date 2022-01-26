#include<stdio.h>
#include<hamako.h>

int main(){
    double limit,temp;
    double a[1000]={};//配列を宣言
    //---------Inout---------//
    limit = getint("Input limit : ");//上限を設定
    for(int i=0;i<limit;i++){
        printf("Input a[%d] : ",i);
        a[i] =getfloat("");
    }
    //-----------------------//
    //i番目以降の最大値を見つける
    int mx,i=0,j=0;
    while(i<limit-1){
        //i番目以降の最大値を見つける
        mx=i;//最大値
        j=i+1;
        while(j<=limit-1){
            //maxとa[i]を比較して必要ならmaxを更新する。
            if(a[j]>a[mx]){
                mx=j;//位置情報を取得
            }
            j++;
        }
        if(a[i]!=a[mx]){
            //位置の更新
            //位置情報同士で値を交換
            temp=a[mx];
            a[mx]=a[i];
            a[i]=temp;
        }

        //遷移
        i++;
    }
    printf("^^^^^sorting result^^^^^\n");
    for(int i=0;i<limit;i++){
        printf("%g ",a[i]);
    }
    printf("\n");
    return(0);
}