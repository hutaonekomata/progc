#include <stdio.h>
#include <stdlib.h>

long long stepCount(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "整数を引数に指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);
  printf("%ld\n", stepCount(n));

  return(0);
}

long long stepCount(int n)
{
  if(n < 1){
    return 0;
  }else if(n < 2){
    return 1;
  }else if(n < 3){
    return 2;
  }else if(n < 4){
    return stepCount(n-1) + stepCount(n-2) + 1;
  }
  return(stepCount(n-1) + stepCount(n-2) + stepCount(n-3));
}
