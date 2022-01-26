#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<hamako.h>

#include"stack.h"
#include"queue.h"

int main(){
    int n;
    // scanf("%d",&n);
    n = getint("");
    char buff[25],ans[1000];
    int data;
    int j;
    Queue que;
    initQueue(&que);
    Stack st;
    initStack(&st);
    for(int i=0;i<n;i++){
        fgets(buff,sizeof(buff),stdin);
        if(buff[0] == '+' || buff[0] == '-'){
            if(buff[0] == '-'){
                initStack(&st);
                // for(j = 1 ; j < (int)sizeof(buff) -1 ; j++){
                j = 1;
                while(buff[j] != '\n'){
                    data = (int)buff[j];
                    push(&st,data);
                    j++;
                }
                j = 1;
                while(pop(&st,&data) == 1){
                    buff[j] = (char)data;
                    j++;
                }
            }
            // for(j = 1;j < (int)sizeof(buff)-1;j++){
            j = 1;
            while(buff[j] != '\n'){
                data = (int)buff[j];
                enQueue(&que,data);
                j++;
            }
        }
    }
    while(deQueue(&que,&data) == 1){
        printf("%c",(char)data);
    }
    printf("\n");
    return(9);
}