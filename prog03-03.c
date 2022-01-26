#include<stdio.h>
#include<string.h>
#include<hamako.h>

int main(){
    char c[256];
    int len;
    len = getstring("Input c : ",c);
    int Big=0,Sma=0,Num=0,Cha=0;
    for(int i=0;i<len;i++){
        if(c[i]>=' '&&c[i]<='~'){
            if(c[i]>='A'&&c[i]<='Z'){
                Big++;
            }else if(c[i]>='a'&&c[i]<='z'){
                Sma++;
            }else if(c[i]>='0'&&c[i]<='9'){
                Num++;
            }else{
                Cha++;
            }
        }
    }
    printf("大文字=%d\n小文字=%d\n記号=%d\n数字=%d\n",Big,Sma,Cha,Num);
    return(0);
}
