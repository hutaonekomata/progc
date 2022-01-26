#include<stdio.h>
#include<string.h>
#include<hamako.h>

int main(){
    char c,s[256];
    int len,p=0;
    len = getstring("Input s : ",s);
    c = getcharacter("Input c : ");
    while(s[p]!=c&&p<len){
        p++;
    }
    if(p==len){
        p=-1;
    }
    printf("p = %d\n",p);
    return(0);
}
