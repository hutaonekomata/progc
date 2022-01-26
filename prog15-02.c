#include<stdio.h>
#include<hamako.h>

//データの上限を設定する

#define MAX_N 101

//__関数を列挙_____________________________

int inputData(int n,double Data[]);
void showData(int n,double Data[]);
double sumData(int n,double Data[]);
double Distributed(int n,double m,double Data[]);
void Sort(int n,double Data[]);
double LookData(int n,double Data[]);
//________________________________________

int main(){
    double ave=0,sum=0,dis=0,Maxi=0,Mini=0,Data[MAX_N];
    int n=0,num;
    n = getint("Input n\n");
    //1 : n個の実数を入力する
    // // 1.1 : 入力する個数であるnを取得する。
    // // // 1.1.1 : 入力する個数は、上限を設定する必要がある。
    // //1.2 : 実際に入力できた個数を返す。
    if((num = inputData(n,Data))<n){
        printf("データが正しく入力されませんでした\n");
    }
    //2:n個の実数を出力する
    showData(num,Data);
    //3:合計を求める。
    sum=sumData(num,Data);
    //4:平均を求める
    ave=sum/num;
    //5:分散を求める
    dis = Distributed(num,ave,Data);
    //6:大きい順に並べ替える
    Sort(num,Data);
    //7:最大値と最小値を求める
    // // 7.1 : 最大値を求める。
    Maxi = LookData(0,Data);
    // // 7.2 : 最小値を求める
    Mini = LookData(num-1,Data);
    // 8 : ソート済みのデータを出力する。
    printf("\n");
    showData(num,Data);
    //9:最大値、最小値、合計、平均、分散を求める。
    printf("\n最大値: %lf\n最小値: %lf\n合計  : %lf\n平均  : %lf\n分散  : %lf\n",Maxi,Mini,sum,ave,dis);
    return(0);
}

/*
機能：データの入力
引数１：n/データ数
引数２：double Data[] /　データを格納する配列。
戻り値：格納できた要素数
*/
int inputData(int n,double Data[]){
    int i;
    for(i=0;i<n&&i<MAX_N;i++){
        Data[i]=getfloat("");
    }
    return(i);
}

/*
機能：配列データの表示
引数１：表示させたい配列の要素数
引数２：表示させたいデータが格納された配列
戻り値：なし
*/
void showData(int n,double Data[]){
    for(int i=0;i<n;i++){
        printf("x[%3d] : %lf\n",i+1,Data[i]);
    }
    return;
}

/*
機能：配列に格納された要素を合計させる
引数１：配列の要素数
引数２：データが格納された配列
戻り値：要素の合計
*/
double sumData(int n,double Data[]){
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=Data[i];
    }
    return(ans);
}

/*
機能：与えられた配列のデータから分散を求める
引数１：要素数
引数２：分散を求めるのに使うデータの平均
引数３：データの格納された配列
戻り値：分散
*/
double Distributed(int n,double m,double Data[]){
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=(Data[i]-m)*(Data[i]-m);
    }
    ans/=n;
    return(ans);
}

/*
機能：与えられた配列を昇順に並べ替える
引数１：要素数
引数２：ソートする配列
戻り値：なし
*/
void Sort(int n,double Data[]){
    // シェーカーソート
    double Copy=0;
    int i,j,k;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(Data[j] > Data[j - 1]) {
                Copy = Data[j];
                Data[j]=Data[j-1];
                Data[j-1] = Copy;
            }
        }
        n--;
        for(int k = n - 1; k > i; k--) {
            if(Data[k] > Data[k - 1]) {
                Copy = Data[k];
                Data[k]=Data[k-1];
                Data[k-1]=Copy;
            }
        }
    }
    return;
}

/*
機能：指定された配列の要素を参照
引数１：添字の指定
引数２：参照したい配列
戻り値：参照した要素のデータ
*/
double LookData(int n,double Data[]){
    double ans = Data[n];
    return(ans);
}