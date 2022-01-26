#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <hamako.h>
#include "stack.h"

int main(){
	int n,outP,judge;
	Stack data;
	initStack(&data);
	n = getint("");
	while(n!=EOF){
		if(n == 0){
			judge = pop(&data,&outP);
			printf("%d\n",outP);
		}else{
			judge = push(&data,n);
		}
		n = getint("");
	}
	return(0);
}