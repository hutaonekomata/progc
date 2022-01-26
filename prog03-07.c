#include<stdio.h>
#include<hamako.h>
#include<string.h>

int main(){
    char c[1023];
    int len,charn,numn,charkey,numkey;
    len = getstring("文字列　:　",c);
    charkey = getint("charkey　：　");
    numkey = getint("numkey : ");
    charn = 'Z'-'A'+1;
    numn = '9'-'0'+1;
    charkey%=charn;
    numkey%=numn;
    for(int i=0;i<len;i++){
        if(c[i]<='Z'&&c[i]>='A')c[i]='A'+(c[i]+charn+charkey-'A')%charn;
	if(c[i]<='9'&&c[i]>='0')c[i]='0'+(c[i]+numn+numkey-'0')%numn;
    }
    printf("%s\n",c);
    return(0);
}
