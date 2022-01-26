#include<stdio.h>
#include<string.h>
#include<hamako.h>

#define MAXS 101
#define MAXN 41
#define NSIZE 5
#define MAXG 7
#define FIN 100
#define SUB 3
#define MAXSize 100

//---------------------
int setData(int n,int dataN[][NSIZE],char name[][MAXN]);
void setRank(int n,int dataN[][NSIZE]);
void setGraph(int n,int dataG[],int dataN[][NSIZE]);
void outData(int n,int dataN[][NSIZE],double dataA[],char name[][MAXN]);
void outGraph(int dataG[]);
void ave(int n,int dataN[][NSIZE],double dataA[]);
void asuta(int n);

int main(){
    int n,num;
    int dataN[MAXS][NSIZE]={};
    double dataA[MAXS]={};
    char name[MAXS][MAXN]={};
    int dataG[MAXG]={};
    //データ数の入力
    if((n = getint("生徒人数を入力\n"))>MAXSize){
        printf("異常なデータ入力\n");
        return(1); // 異常終了
    }
    // データの入力
    num = setData(n,dataN,name);
    // // 配列の上限を確認
    // // // 入力と同時に合計を確保
    // // // 合計値から,平均を出力
    ave(num,dataN,dataA);
    // 合計成績から順位を決定
    setRank(num,dataN);
    //度数分布表用のデータを格納
    setGraph(num,dataG,dataN);
    //出力
    outData(num,dataN,dataA,name);
    outGraph(dataG);
    return(0);
}

/*
機能：渡されたn分のデータ(上限１００)を配列dataNに格納
機能２：内部で同時に合計を算出
機能３：入力データのサイズが正しいか判断
引数１(n)：データ数
引数２(dataN)：データを格納する配列(平均値以外の値)
引数３(name)：データを格納する配列(名前)
戻り値：入力に成功したデータ数(上限１００)
*/
int setData(int n,int dataN[][NSIZE],char name[][MAXN]){
    char buff[256]={};
    char fname[20]={},sname[20]={};
    int i=0,num,jap,math,eng;
    while(i<n){
        fgets(buff,sizeof(buff),stdin);
        sscanf(buff,"%d %s %s %d %d %d",&num,&fname,&sname,&jap,&math,&eng);
        // 一度仮の変数に一行分のデータを格納しておき、後で全体で使うデータの配列に格納する。
        num--;
        dataN[num][0]=jap;
        dataN[num][1]=math;
        dataN[num][2]=eng;
        //入力された名前は、結合して一つの文字列に格納する。
        strcat(fname," ");
        strcat(fname,sname);
        strcpy(name[num],fname);
        dataN[num][3] = dataN[num][0] + dataN[num][1] + dataN[num][2];
        dataN[FIN][0] += dataN[num][0];
        dataN[FIN][1] += dataN[num][1];
        dataN[FIN][2] += dataN[num][2];
        dataN[FIN][3] += dataN[num][3];
        i++;
    }
    return(i);
}

/*
機能：渡された配列から、全体順位を決定、格納する
引数１(n)：データ数
引数２(dataN):データが格納されている配列
戻り値：なし
*/
void setRank(int n,int dataN[][NSIZE]){
    int rank;
    for(int i=0;i<n;i++){
        rank = n+1;
        for(int j=0;j<n;j++){
            if(dataN[i][3]>=dataN[j][3]){
                rank--;
            }
        }
        dataN[i][4] = rank;
    }
    return;
}

/*
機能：渡された配列から、度数分布表出力用のデータを格納する
引数１(n)：データ数
引数２(dataG):データを格納する配列
引数３(dataN)：参照するデータが入った配列
戻り値：なし
*/
void setGraph(int n,int dataG[],int dataN[][NSIZE]){
    int j = 0;
    for(int i=0;i<n;i++){
        j = 0;
        while((j*50)-1 < dataN[i][3]&&j<MAXG){
            j++;
        }
        dataG[j-1]++;
    }
    return;
}

/*
機能：表の作成
引数１(n)：データ数
引数２(dataN)：平均値以外の値が格納された配列
引数３(dataA)：平均値が格納された配列
戻り値：なし
*/
void outData(int n,int dataN[][NSIZE],double dataA[],char name[][MAXN]){
    printf("|  No | Name                                      |  Japanese |      Math |   English |       Sum |      Rank |   Average |\n");
    printf("|-------------------------------------------------------------------------------------------------------------------------|\n");
    for(int i=0;i<n;i++){
        printf("|%4d | %-41s | %9d | %9d | %9d | %9d | %9d | %9.2lf |\n",i+1,name[i],dataN[i][0],dataN[i][1],dataN[i][2],dataN[i][3],dataN[i][4],dataA[i]);
    }
    printf("|-------------------------------------------------------------------------------------------------------------------------|\n");


    printf("\n\t\t\t\t\t合計 %14d %11d %11d %11d\n",dataN[FIN][0],dataN[FIN][1],dataN[FIN][2],dataN[FIN][3]);
    printf("\t\t\t\t\t平均 %14.2lf %11.2lf %11.2lf %11.2lf\n\n",(double)dataN[FIN][0]/n,(double)dataN[FIN][1]/n,(double)dataN[FIN][2]/n,(double)dataN[FIN][3]/n);
    return;
}

/*
機能：度数分布表を作成する
引数１：要素の格納された配列
戻り値：なし
*/
void outGraph(int dataG[]){
    int j=0;
    for(int i=0;i<MAXG;i++){
        if(i<MAXG-1){
            printf("[%3d] - [%3d] [%3d] ",50*i,50*i+49,dataG[i]);
        }else{
            printf("[%3d]         [%3d] ",50*i,dataG[i]);
        }
        asuta(dataG[i]);
        printf("\n");
    }

    return;
}

/*
機能：渡された値の分だけ"*"を出力する。
引数１：出力したい数
戻り値；なし
*/
void asuta(int n){
    for(int i=0;i<n;i++){
        printf("*");
    }
    return;
}

/*
機能：データの平均を求める
引数１：データ数
引数２；データが格納された配列
引数３；平均を格納する変数
戻り値：なし
*/
void ave(int n,int dataN[][NSIZE],double dataA[]){
    for(int i=0;i<n;i++){
        dataA[i]=(double)dataN[i][3] / SUB;
    }
    return;
}