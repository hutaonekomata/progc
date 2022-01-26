#include<hamako.h>
#include<stdio.h>
#include<string.h>

int main(){
    char m[10000],c[10000];
    int numc=0,numm=0,i=0,o=-1;
    // パターンと文字列の入力。
    numc = getstring("Input String : ",c);
    numm = getstring("Input patern : ",m);
    if(numc!=0||numm!=0){
        //繰り返し。
        while(i<numc&&o!=numm-1&&numc>=numm){//二つの添字をともに増やすため、パターンの添字がnummを超えないように監視。
            // コード量減らしたい。
            // 毎回二つの添字を増やしていって、ifで文字が違う時だけ、パターンの添字を-1に戻す。
            o++;
            printf("# %d %d %d\n",o,i,i-(o+1));
            printf("c[i] = %c m[o] = %c\n",c[i],m[o]);
            if(c[i]!=m[o]){
                o=-1;
            }
            i++;
        }
        if(o==-1){
            o=i;
        }
        printf("P = %d",i-(o+1));
    }else{
        printf("Unacceptable input");
    }
    printf("\n");
    return(0);
}
