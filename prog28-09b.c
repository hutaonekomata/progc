#include <stdio.h>
#include <stdlib.h>

void printBinaryN(int d, int n);

int main(int argc, char *argv[])
{
  int d, n;

  if (argc < 3) {
    fprintf(stderr, "10進整数と表示するビット長を引数に指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &d);
  sscanf(argv[2], "%d", &n);

  printBinaryN(d, n);
  putchar('\n');

  return(0);
}

void printBinaryN(int d, int n)
{

  if(d < 2){
    for(int i=1;i<n;i++){
      printf("0");
    }
    printf("%d",d);
  }else{
    printBinaryN(d/2,n-1);
    printf("%d",d%2);
  }
  return;
}
