#include<stdio.h>
#include<hamako.h>

int main()
{
    //--------Input--------------//
    int a;
    a=getint("Input: ");
    //---------------------------//

    //--------judging------------//
    if(a!=0){
        //--------No Accept zero---------//
        if(a%5==0){
            if(a%3==0)
            {
                printf("FizzBuzz\n");
            }else{
                printf("Buzz\n");
            }
        }else if(a%3==0){
            printf("Fizz\n");
        }
    }
    return(0);
}