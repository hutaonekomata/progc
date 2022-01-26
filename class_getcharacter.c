#include<stdio.h>
#include<hamako.h>

int main(){
    int n;
    char a[100],s[]="ABC";
    n = getstring("a[0] : ",s);
    n = getstring("a[1] : ",a);
    printf("a[0] : %s\na[1] : %s\n文字列 : %s\n",a,s,"a");
    return(0);
}