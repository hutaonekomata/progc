#include<stdio.h>
#include<hamako.h>

int main()
{
    //------yearの入力--------//
    int year;
    year=getint("year=");
    //-----------------------//

    //------判定--------------//
    if(year%4!=0){
        printf("平年\n");
    }else if(year%100!=0){
        printf("うるう年\n");
    }else if(year%400!=0){
        printf("平年\n");
    }else{
        printf("うるう年\n");
    }
    return(0);
}