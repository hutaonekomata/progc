#include<stdio.h>
#include<string.h>
#include<hamako.h>

int main(){
    int len;
    char c[256];
    len = getstring("Input c : ",c);
    for(int i=0;i<len;i++){
        if(c[i]>='A'&&'Z'>=c[i]){
            c[i]+='a'-'A';
        }else if(c[i]>='a'&&c[i]<='z'){
            c[i]-='a'-'A';
        }
    }
    printf("After Changed string,c : %s\n",c);
    return(0);
}
