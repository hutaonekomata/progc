#include<stdio.h>
#include<stdlib.h>

int fib(int n,int a,int b);

int main(int argc, char *argv[]){
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に正数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%ld\n", fib(n,1,1));

  return(0);
}

int fib(int n,int a,int b){
	if(2 < n){
		return(fib(n-1,b,a+b));
	}else{
		return(b);
	}
}