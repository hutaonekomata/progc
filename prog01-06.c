#include<stdio.h>
#include<hamako.h>

int main()
{
    //--------Input---------------//
    int a,b;
    a=getint("a=");
    b=getint("b=");
    //----------------------------//

    //----------judging-----------//
    if(a-b>=11||b-a>=11){
        printf("差は11以上です\n");
    }else{
        printf("差は10以下です\n");
    }
    return(0);
}
